//
// Created by Luiza on 24.04.2026.
//

#ifndef SHARE_THE_BILL_2_0_CATEGORY_H
#define SHARE_THE_BILL_2_0_CATEGORY_H


#include<iostream>
#include<string>

class Category {

private:
    std::string name;
    double budgetLimit;

public:
    Category();

    Category( std::string name, double budgetLimit );
    Category( const Category& c );
    Category& operator=( const Category& c );
    ~Category();


    friend std::istream& operator>>(std::istream& in, Category& c);
    friend std::ostream& operator<<(std::ostream& out, const Category& c);


    std::string getName() const;
    void setName( const std::string& name );

    double getBudgetLimit() const;
    void setBudgetLimit( double newLimit );


};






#endif //SHARE_THE_BILL_2_0_CATEGORY_H