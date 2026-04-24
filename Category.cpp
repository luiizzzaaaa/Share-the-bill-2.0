#include "Category.h"

Category::Category() : name("General"), budgetLimit(0.0) {}

Category::Category( std::string name, double budgetLimit) :name(name), budgetLimit(budgetLimit) {}

Category::Category( const Category& c) : name(c.name), budgetLimit(c.budgetLimit) {}


Category& Category::operator=( const Category& c ) {
    if (this != &c) {
        name = c.name;
        budgetLimit = c.budgetLimit;
    }

    return *this;
}

Category::~Category() = default;


std::istream& operator>>(std::istream& in, Category& c) {
    std::cout << " Enter category name";
    in >> c.name;
    std::cout << " Enter budget limit";
    in >> c.budgetLimit;

    return in;
}


std::ostream& operator<<( std::ostream& out, const Category& c ) {
    out << "Category name: " << c.name << std::endl;
    out << "Budget limit: " << c.budgetLimit << std::endl;
    return out;
}


std::string Category::getName() const { return name; }
void Category::setName( const std::string& newName ) { name = newName; }

double Category::getBudgetLimit() const { return budgetLimit; }
void Category::setBudgetLimit(double newLimit) {
    budgetLimit = newLimit;
}




