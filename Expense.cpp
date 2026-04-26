#include "Expense.h"
#include <stdexcept>

Expense::Expense() {
    this->description = "unkn";
    this->total = 0.0;
    this->payerName = "unkn";
}

Expense::Expense(std::string description, double total, std::string payerName) {
    if (total <= 0.0) {
        throw std::invalid_argument("Total must be greater than zero");
    }
    this->description = description;
    this->total = total;
    this->payerName = payerName;

}


Expense::Expense(const Expense& other) {
    this->description = other.description;
    this->total = other.total;
    this->payerName = other.payerName;
}

Expense& Expense::operator=(const Expense& other) {
    if (this != &other) {
        this->description = other.description;
        this->total = other.total;
        this->payerName = other.payerName;
    }
    return *this;
}


Expense::~Expense(){}

std::istream& operator>>(std::istream& in, Expense& e) {
    std::cout << "Enter expense name: ";
    in >> e.description;

    std::cout << "Enter expense total: ";
    in >> e.total;
    if (e.total <= 0.0) {
        throw std::invalid_argument("Total must be greater than zero");
    }

    std::cout << "Enter payer name: ";
    in >> e.payerName;

    return in;
}

std::ostream& operator<<(std::ostream& out,const Expense& e) {
    out<<"Expense: "<<e.description<<'/n';
    out<<"Total: "<<e.total<<'/n';
    out<<"Payer: "<<e.payerName<<'/n';
    return out;
}

std::string Expense::getDescription() const {
    return this->description;
}
void Expense::setDescription(const std::string& newDescription) {
    this->description = newDescription;
}

double Expense::getTotal() const {
    return this->total;
}
void Expense::setTotal(double newTotal) {
    if (newTotal <= 0.0) {
        throw std::invalid_argument("Total must be greater than zero");
    }
    this->total = newTotal;
}

std::string Expense::getPayerName() const {
    return this->payerName;
}
void Expense::setPayerName(const std::string& newPayerName) {
    this->payerName = newPayerName;
}

void Expense::applyVoucher(double discountAmount) {
    if (discountAmount < 0.0) {
        throw std::invalid_argument("Discount must be greater than zero");
    }
    if ( discountAmount > total ) {
        throw std::invalid_argument("Discount must be less than total");
    }
    total -= discountAmount;
    std::cout << "Discount amount: "<<discountAmount<< " applied for "<< description<<'/n'<<std::endl;
}



