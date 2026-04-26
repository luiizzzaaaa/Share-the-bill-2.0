#include "EqualExpense.h"

EqualExpense::EqualExpense() : Expense(){}

EqualExpense::EqualExpense(std::string description, double total, std::string payer, const std::vector<std::string>& participants)
    : Expense(description, total, payer) {
    this-> participants = participants;
}


EqualExpense::EqualExpense( const EqualExpense& other) : Expense(other) {
    this-> participants = other.participants;
}


EqualExpense& EqualExpense::operator=(const EqualExpense& other) {
    if (this != &other) {
        Expense::operator=(other);
        this-> participants = other.participants;
    }
    return *this;
}

EqualExpense::~EqualExpense() {}

std::istream& operator>>(std::istream& in, EqualExpense& obj) {
    in >> static_cast<Expense&>(obj);

    int noParticipants;
    std::cout << "How many people are splitting this expense?";
    in >> noParticipants;

    obj.participants.clear();

    std::cout << " Enter their names: " << std::endl;
    for ( int i = 0; i < noParticipants; ++i) {
        std::string name;
        in >> name;
        obj.participants.push_back(name);
    }

    return in;

}

std::ostream& operator<<(std::ostream& out, const EqualExpense& obj) {
    out << static_cast<const Expense&>(obj);

    out << "| is split equally among " << obj.participants.size() << " people: ";
    for (const auto& name : obj.participants) {
        out << name << " ";
    }
    return out;

}

void EqualExpense::calculateShares() const {
    if (participants.empty()) {
        std::cout << "No participants available." << std::endl;
        return;
    }
    double share = getTotal() / participants.size();

    std::cout << getDescription() << " split summary: "<< std::endl;
    std::cout << getPayerName() << " paid " << getTotal() << std::endl;

    for (const auto& person : participants) {
        if ( person != getPayerName()) {
            std::cout << person << " owes " << getPayerName() << std::endl;
        }
    }
}


    void EqualExpense::addParticipant(const std::string& name) {
        participants.push_back(name);
    }


void EqualExpense::updateGroupBalances(std::vector<User>& groupMembers) const {
    if (participants.empty()) return;
    double share = getTotal() / participants.size();

    for (auto& u : groupMembers)
    {
        if (u.getName() == getPayerName()) {
            u.addToBalance(getTotal());
        }
        for (const auto& person : participants) {
            if (person == u.getName()) {
                u.addToBalance(-share);
                break;
            }
        }
    }
}


