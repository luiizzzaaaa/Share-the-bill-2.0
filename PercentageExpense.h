//
// Created by Luiza on 23.04.2026.
//

#ifndef SHARE_THE_BILL_2_0_PERCENTAGEEXPENSE_H
#define SHARE_THE_BILL_2_0_PERCENTAGEEXPENSE_H

#include "Expense.h"
#include <vector>
#include <utility>


class PercentageExpense : public Expense {

private:
    std::vector<std::pair<std::string, double>> participantsShares;


public:
    PercentageExpense();
    PercentageExpense( std::string description, double total, std::string payer,
                const std::vector<std::pair<std::string, double>>& shares);
    PercentageExpense( const PercentageExpense& obj);

    PercentageExpense& operator=( const PercentageExpense& obj);

    ~PercentageExpense() override;

    friend std::istream& operator>>(std::istream& in, PercentageExpense& obj);
    friend std::ostream& operator<<(std::ostream& out,const PercentageExpense& obj);

    void calculateShares() const override;

    void addParticipantSH( const std::string& name, double percentage );


};


#endif //SHARE_THE_BILL_2_0_PERCENTAGEEXPENSE_H