//
// Created by Luiza on 24.04.2026.
//

#ifndef SHARE_THE_BILL_2_0_DEPT_H
#define SHARE_THE_BILL_2_0_DEPT_H

#include<iostream>
#include<string>

class Debt {


private:
    std::string debtor;
    std::string creditor;
    double amount;

public:
    Debt();
    Debt(std::string debtor, std::string creditor, double amount);
    Debt(const Debt& debt);
    Debt& operator=(const Debt& obj);
    ~Debt();

    friend std::istream& operator>>(std::istream& in, Debt& d);
    friend std::ostream& operator<<(std::ostream& out, const Debt& d);

    std::string getDebtor() const;
    std::string getCreditor() const;
    double getAmount() const;



};



#endif //SHARE_THE_BILL_2_0_DEPT_H