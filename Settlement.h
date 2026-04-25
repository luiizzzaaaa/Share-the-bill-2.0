//
// Created by Luiza on 25.04.2026.
//

#ifndef SHARE_THE_BILL_2_0_SETTLEMENT_H
#define SHARE_THE_BILL_2_0_SETTLEMENT_H


#include<iostream>
#include<string>

class Settlement {

private:
    std::string payerName;
    std::string receiverName;
    double amount;
    std::string method;

public:
    Settlement();
    Settlement(std::string payer , std::string receiver , double amount, std::string method);
    Settlement( const Settlement& obj);

    Settlement& operator=(const Settlement& obj);
    ~Settlement();

    friend std::ostream& operator<<(std::ostream& out, const Settlement& s);
    friend std::istream& operator>>(std::istream& in, Settlement& s);


    srd::string getPayer() const;
    std::string getReceiver() const;
    double getAmount() const;



};





#endif //SHARE_THE_BILL_2_0_SETTLEMENT_H