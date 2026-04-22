//
// Created by Luiza on 21.04.2026.
//

#ifndef SHARE_THE_BILL_2_0_USER_H
#define SHARE_THE_BILL_2_0_USER_H

#include <iostream>
#include <cstring>
#include <stdexcept>

class User {

private :
    std::string name;
    std::string email;
    double balance;

    bool isValidEmail( const std::string& emailToCheck) const;

public :
    User();

    User( std:: string name, std::string email);

    User(const User& otherUser);

    User& operator=(const User& otherUser);

    ~User();

    friend std::ostream& operator<<(std::ostream& out, const User& u);
    friend std::istream& operator>>(std::istream& in, User& u);

    std::string getName() const;
    void setName(const std::string& newName);

    std::string getEmail() const;
    void setEmail(const std::string& newEmail);

    double getBalance() const;

    void addToBalance(double amount);

};






#endif //SHARE_THE_BILL_2_0_USER_H