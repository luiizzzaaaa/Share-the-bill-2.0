#include "Debt.h"


Debt::Debt() : debtor("unkn"), creditor("unkn"), amount(0.0) {}

Debt::Debt(std::string debtor, std::string creditor, double amount)
    : debtor(debtor), creditor(creditor), amount(amount) {}

Debt::Debt(const Debt& obj) : debtor(obj.debtor), creditor(obj.creditor), amount(obj.amount) {}

Debt& Debt::operator=(const Debt& obj) {
    if (this != &obj) {
        debtor = obj.debtor;
        creditor = obj.creditor;
        amount = obj.amount;
    }
    return *this;
}

Debt::~Debt() = default;

std::istream& operator>>(std::istream& in, Debt& d) {
    std::cout << "Who owes money?";
    in >> d.debtor;
    std::cout << "To whom?";
    in >> d.creditor;
    std::cout << "Amount owed:";
    in >> d.amount;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Debt& d) {
    out << d.debtor<<" owes " << d.creditor<<" amount " << d.amount;
    return out;
}


std::string Debt::getDebtor() const { return debtor; }
std::string Debt::getCreditor() const { return creditor; }

double Debt::getAmount() const { return amount; }

