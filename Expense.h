//
// Created by Luiza on 22.04.2026.
//

#ifndef SHARE_THE_BILL_2_0_EXPENSE_H
#define SHARE_THE_BILL_2_0_EXPENSE_H

#include <iostream>
#include <string>


class Expense {

private:
    std::string description;
    double total;
    std::string payerName;

public:
    Expense();
    Expense(std::string description, double total, std::string payerName);

    Expense(const Expense& other);

    Expense& operator=(const Expense& other);

   virtual ~Expense(); // este virtual destr la clasa de baza pt a preveni memory leaks

    friend std::ostream& operator<<(std::ostream& out, const Expense& e);
    friend std::istream& operator>>(std::istream& in, Expense& e);

    std::string getDescription() const;
    void setDescription(const std::string& newDescription);

    double getTotal() const;
    void setTotal(double newTotal);

    std::string getPayerName() const;
    void setPayerName(const std::string& newPayerName);


    virtual void calculateShares() const = 0; // metoda pur virtuala si transforma clasa intr-o clasa abstracta

    void applyVoucher(double discountAmount);




};



#endif //SHARE_THE_BILL_2_0_EXPENSE_H