#include "User.h"

bool User::isValidEmail(const std::string &emailToCheck) const {
    return emailToCheck.find('@') != std::string::npos;
}


User::User() {
    this -> name = "Unknown";
    this -> email = "a@email.com";
    this-> balance = 0.0;
}

User::User ( std::string name, std::string email) {
    this -> name = name;

    if (!isValidEmail(email)) {
        throw std::invalid_argument("Invalid email");
    }
    this -> email = email;
    this-> balance = 0.0;
}

User ::User(const User& otherUser) {
    this -> name = otherUser.name;
    this -> email = otherUser.email;
    this -> balance = otherUser.balance;
}


User& User::operator=(const User& otherUser) {
    if (this != &otherUser) {
        this -> name = otherUser.name;
        this -> email = otherUser.email;
        this -> balance = otherUser.balance;
    }
    return *this;
}

User::~User() {

}

std::istream& operator>>(std::istream& in, User& u) {
    std::cout<<"Enter name: ";
    in>>u.name;

    std::string mail;
    std::cout<<"Enter email: ";
    in>>mail;

    if (!u.isValidEmail(mail)) {
        throw std::invalid_argument("Invalid email");
    }
    u.email = mail;

    return in;

}

std::ostream& operator<<(std::ostream& out, const User& u) {
    out << "User: " << u.name << " and email is " << u.email<< " and balance: "<< u.balance;
    return out;
}

std::string User::getName() const {
    return this->name;
}

void User::setName(const std::string& newName) {
    this->name = newName;
}

std::string User::getEmail() const {
    return this->email;
}

void User::setEmail(const std::string& newEmail) {
    if (!isValidEmail(newEmail)) {
        throw std::invalid_argument("Invalid email");
    }
    this->email = newEmail;
}

double User::getBalance() const {
    return this->balance;
}

void User::setBalance(double newBalance) {
    this->balance = newBalance;
}

void User::addToBalance(double amount) {
    this->balance += amount;
}


