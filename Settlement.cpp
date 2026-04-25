#include "Settlement.h"
#include <stdexcept>

Settlement::Settlement() : payerName("unkn"), receiverName("unkn"), amount(0.0), method("cash") {}

Settlement::Settlement( std::string payer, std::string receiver, double amount, std::string method)
    : payerName(payer), receiverName(receiver), amount(amount), method(method) {
    if ( amount <= 0.0 ) {
        throw std::invalid_argument("amount must be greater than 0 ");
    }
}

Settlement::Settlement(const Settlement& obj)
    : payerName(obj.payerName), receiverName(obj.receiverName),
      amount(obj.amount), method(obj.method) {}


Settlement& Settlement::operator=(const Settlement& obj) {
    if ( this != &obj) {
        payerName = obj.payerName;
        receiverName = obj.receiverName;
        amount = obj.amount;
        method = obj.method;
    }
    return *this;
}

Settlement::~Settlement() = default;

std::istream& operator>>(std::istream& in, Settlement& s) {
    std::cout<<"Who is paying?";
    in >> s.payerName;
    std::cout<<" who is receiving?";
    in >> s.receiverName;
    std::cout << "Amount paid:";
    in >> s.amount;
    if (s.amount <= 0.0) {
        throw std::invalid_argument("amount must be greater than 0 ");

    }

    std::cout<< " Payment method? ";
    in >> s.method;
    return in;
}

std::ostream& operator<<(std::ostream& out,const Settlement& s) {
    out << s.payerName << "paid" << s.amount << "to"<< s.receiverName<< " via " <<s.method;
    return out;
}

std::string Settlement::getPayer() const {
    return payerName;
}

std::string Settlement::getReceiver() const {
    return receiverName;
}

double Settlement::getAmount() const {
    return amount;
}






