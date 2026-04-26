//
// Created by Luiza on 25.04.2026.
//

#ifndef SHARE_THE_BILL_2_0_GROUP_H
#define SHARE_THE_BILL_2_0_GROUP_H

#include <iostream>
#include <vector>
#include <string>
#include "User.h"
#include "Expense.h"
#include "Debt.h"
#include "Settlement.h"

class Group {

private :
    std::string groupName;
    std::vector<User> members;
    std::vector<Expense*> expenses;

public:
    Group();
    Group(std::string name);
    Group(const Group& obj);
    Group& operator=(const Group& obj);
    ~Group();

    friend std::istream& operator>>(std::istream& in, Group& g);
    friend std::ostream& operator<<(std::ostream& out, const Group& g);

    void addUser( const User& u);
    void addExpense(Expense* exp);

    void showAllExpenses() const;

    void generateBalances() const;
    void processSettlement(const Settlement& s);

    void saveProgressToFile( const std::string& filename) const;



};






#endif //SHARE_THE_BILL_2_0_GROUP_H