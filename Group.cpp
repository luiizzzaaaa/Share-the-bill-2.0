#include "Group.h"
#include <fstream>
#include <stdexcept>
#include <algorithm>


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

void Group::loadProgressFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cout << "Error opening file for reading" << std::endl;
        return;
    }

    std::string aaa;
    inFile >> aaa >> groupName;

    int totalMembers;
    inFile >> aaa >> totalMembers;

    members.clear();

    for (int i = 0; i < totalMembers; i++) {
        std::string name, email;
        double balance;
        inFile >> name >> email >> balance;
        User u(name,email);
        u.setBalance(balance);
        members.push_back(u);
    }

    std::cout << " Datele au fost incarcate cu succes din" << filename;
    inFile.close();
}


void Group::showGroupAwards() const {
    std::cout << std::endl<< " Group Awards Summary : " << std::endl;
    if (members.empty() || expenses.empty()) {
        std::cout << "Not enough data for awards. " << std::endl;
        return;
    }
    std::map<std::string, double> amountPaidPerUser;
    for ( const auto exp : expenses ) {
        amountPaidPerUser[exp->getPayerName()] += exp->getTotal();
    }
    std::string topSpender="";
    double maxSpent = 0;
    for ( const auto& pair : amountPaidPerUser ) {
        if (pair.second > maxSpent) {
            maxSpent = pair.second;
            topSpender = pair.first;
        }
    }
    std::cout << std::endl<< "Top Spender : " << topSpender << std::endl;
}

void Group::showUserDashboard(const std::string &userName) const {
    std::cout << std::endl<< " User Dashboard Summary : " << std::endl;
    bool userFound = false;
    for ( const auto& u : members ) {
        if (u.getName() == userName) {
            std::cout << "Status Balance: " << u.getBalance() << std::endl;
            userFound = true;
            break;
        }
    }
    if (!userFound) {
        std::cout << std::endl<< " User Not Found. " << std::endl;
        return;
    }

    std::cout << " Expenses paid by " << userName << ": " << std::endl;
    for ( const auto& exp : expenses ) {
        if ( exp -> getPayerName() == userName ) {
            std::cout << "-> " << exp->getDescription() << " " << exp->getTotal()<< std::endl;
        }
    }
}


void Group::simplifyDebts() {
    std::cout << "\nSimplified Debts Algorithm\n";
    std::vector<User> debtors;
    std::vector<User> creditors;

    for (const auto& m : members) {
        if (m.getBalance() < 0) debtors.push_back(m);
        else if (m.getBalance() > 0) creditors.push_back(m);
    }

    int i = 0;
    int j = 0;

    while (i < debtors.size() && j < creditors.size()) {
        double debtAmount = std::abs(debtors[i].getBalance());
        double creditAmount = creditors[j].getBalance();

        double settledAmount = std::min(debtAmount, creditAmount);

        std::cout << debtors[i].getName() << " MUST PAY "
                  << creditors[j].getName() << " " << settledAmount << std::endl;

        debtors[i].setBalance(debtors[i].getBalance() + settledAmount);
        creditors[j].setBalance(creditors[j].getBalance() - settledAmount);

        if (debtors[i].getBalance() == 0) i++;
        if (creditors[j].getBalance() == 0) j++;
    }
}

