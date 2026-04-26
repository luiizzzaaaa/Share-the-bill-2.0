//
// Created by Luiza on 23.04.2026.
//

#ifndef SHARE_THE_BILL_2_0_EQUALEXPENSE_H
#define SHARE_THE_BILL_2_0_EQUALEXPENSE_H

#include "Expense.h"
#include <vector>
#include <string>

class EqualExpense : public Expense {

private:
    std::vector<std::string> participants;

public:
    EqualExpense();
    EqualExpense(std::string description, double total, std::string payer, const std::vector<std::string>& participants);
    EqualExpense(const EqualExpense&other);

    EqualExpense& operator=(const EqualExpense& other);

    ~EqualExpense() override;

    friend std::istream& operator>>(std::istream& in, EqualExpense& obj);
    friend std::ostream& operator<<(std::ostream& out,const EqualExpense& obj);

    void calculateShares() const override;

    void addParticipant(const std::string& name);

    void updateGroupBalances(std::vector<User>& groupMembers) const override;

};










#endif //SHARE_THE_BILL_2_0_EQUALEXPENSE_H