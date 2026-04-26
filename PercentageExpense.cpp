#include "PercentageExpense.h"
#include <stdexcept>

#include "EqualExpense.h"

PercentageExpense::PercentageExpense() : Expense() {}


PercentageExpense::PercentageExpense(std::string description, double total, std::string payer, const std::vector<std::pair<std::string, double> > &shares)
    : Expense(description, total, payer) {

    double totalPercentage = 0.0;
    for (const auto& share : shares) {
        totalPercentage += share.second;
    }

    if (totalPercentage != 100.0) {
        throw std::invalid_argument("Percentage should be 100%");
    }

    this -> participantsShares = shares;

}

PercentageExpense::PercentageExpense(const PercentageExpense &obj) : Expense(obj) {
    this -> participantsShares = obj.participantsShares;
}

PercentageExpense& PercentageExpense::operator=(const PercentageExpense& obj) {
    if (this != &obj) {
        Expense::operator=(obj);
        this->participantsShares = obj.participantsShares;
    }
    return *this;
}


PercentageExpense::~PercentageExpense() {}

std::istream& operator>>(std::istream& in, PercentageExpense& obj) {
    in >> static_cast<Expense&>(obj);

    int noParticipants;
    std::cout << " How many people are splitting this by percentage: ";
    in >> noParticipants;

    obj.participantsShares.clear();

    double currentTotal = 0.0;

    for (int i = 0; i < noParticipants; i++) {
        std::string name;
        double percent;
        std::cout << "Enter name for person no." << (i+1)<< ":";
        in >> name;
        std::cout<< "Enter percentage for " << name << " : ";
        in >> percent;

        obj.participantsShares.push_back({name,percent});
        currentTotal += percent;
    }

    if (currentTotal != 100.0) {
        throw std::invalid_argument("Percentage should be 100%");
    }

    return in;
}

std::ostream& operator<<(std::ostream& out, const PercentageExpense& obj) {
    out << static_cast<const Expense&>(obj);
    out <<" Split by percentage: ";
    for (const auto& share : obj.participantsShares) {
        out << "[" << share.first <<":" << share.second << "%]";
    }

    return out;
}

void PercentageExpense::calculateShares() const {
    if ( participantsShares.empty() ) {
        std::cout << "No participants have been shared." << std::endl;
        return;
    }

    std::cout<< getDescription() << " Percentage split summary:" << std::endl;
    std::cout << getPayerName() << "paid " << getTotal() << std::endl;

    for ( const auto& share : participantsShares ) {
        std::string person = share.first;
        double percentage = share.second;

        double amountOwed = (percentage / 100.0) * getTotal();

        if ( person != getPayerName()){
            std::cout << person<< " owes " << getPayerName()<<" "<< amountOwed << " " << percentage<< std::endl;

        }
    }
}


void PercentageExpense::addParticipantSH(const std::string &name, double percentage) {
    participantsShares.push_back({name,percentage});
}

void PercentageExpense::updateGroupBalances(std::vector<User>& groupMembers) const {
    if (participantsShares.empty()) return;
    double share = getTotal() / participantsShares.size();

    for (auto& u : groupMembers) {
        if (u.getName() == getPayerName()) {
            u.addToBalance(getTotal());
        }
        for (const auto& shareInfo : participantsShares) {
            if (shareInfo.first == u.getName()) {
                double amountOwed = (shareInfo.second / 100.0) * getTotal();
                u.addToBalance(-amountOwed);;
                break;
            }
        }
    }
}




