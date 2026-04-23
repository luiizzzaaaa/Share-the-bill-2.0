//
// Created by Luiza on 23.04.2026.
//

#ifndef SHARE_THE_BILL_2_0_EQUALEXPENSE_H
#define SHARE_THE_BILL_2_0_EQUALEXPENSE_H

#include "Expense.h"
#include <vector>

class EqualExpense : public Expense {

private:
    std::vector<std::string> participants;

public:
    EqualExpense();
    EqualExpense(std::string description, double total, std::sting paayer, const std::vector<std::string>& participants);
    EqualExpense(const EqualExpense&other);

    EqualExpense& operator=(const EqualExpense& other);

    EqualExpense() override;

    friend std::istream& operator>>(std::istream& in, EqualExpense& obj);
    friend std::ostream& operator<<(std::ostream& out, EqualExpense& obj);

    void calculateShares() const override;

    void addParticipant(const std::string& name);



};










#endif //SHARE_THE_BILL_2_0_EQUALEXPENSE_H