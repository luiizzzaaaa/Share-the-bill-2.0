#include "Group.h"
#include <fstream>
#include <stdexcept>


Group::Group() : groupName("New Group") {}

Group::Group(std::string name) : groupName(name) {}

Group::Group(const Group& obj) : groupName(obj.groupName), members(obj.members) {}


Group& Group::operator=(const Group& obj) {
    if (this != &obj) {
        groupName = obj.groupName;
        members = obj.members;
        for (auto exp : expenses) { delete exp;}
        expenses.clear();
    }
    return *this;
}

Group::~Group() {
    for (auto exp : expenses) {
        delete exp;
    }
    expenses.clear();
}

std::istream& operator>>(std::istream& in, Group& g) {
    std::cout << "Enter group name: ";
    in >> g.groupName;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Group& g) {
    out << "Group: " << g.groupName;
    out << " having this no of members: " << g.members.size() << " and the total of expenses :" << g.expenses.size();
    return out;
}

void Group::addUser( const User& u) {
    members.push_back(u);

}

void Group::addExpense( Expense* exp) {
    if ( exp != nullptr) {
        expenses.push_back(exp);
    }
}

void Group::showAllExpenses() const {
    std::cout << " All Expenses for "<< groupName <<std::endl;
    if ( expenses.empty() ) {
        std::cout << " No expenses were added." << std::endl;
        return;
    }

    for ( const auto& exp : expenses ) {
        exp->calculateShares();
    }
}


void Group::generateBalances() const {
    std::cout <<std::endl<< " Balances Summary : " << std::endl;
    for ( const auto& member:members) {
        std::cout << member.getName()<< " Balance : " << member.getBalance() << std::endl;
    }
}

void Group::processSettlement(const Settlement& s) {
    std::cout << "Processint: " << s << std::endl;

}


void Group::saveProgressToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        throw std::runtime_error("Error opening file for writing");
    }

    outFile<<"Group_Name: " << groupName <<std::endl;
    outFile << "Total_Members: "<< members.size() << std::endl;

    for (const auto& m : members) {
        outFile << m.getName() << " " << m.getEmail() << " " << m.getBalance() << std::endl;
    }

    outFile << "Total_Expenses: " << expenses.size() << std::endl;
    std::cout << "Data successfully serialized to " << filename << std::endl;
    outFile.close();



}



