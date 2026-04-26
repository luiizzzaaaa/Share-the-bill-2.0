#include "Meniu.h"
#include "User.h"
#include "EqualExpense.h"
#include "PercentageExpense.h"
#include <stdexcept>


Meniu::Meniu() : isRunning() {}

Meniu::Meniu(const Group& g) : activeGroup(g), isRunning(true) {}

Meniu::Meniu(const Meniu& m) : activeGroup(m.activeGroup), isRunning(m.isRunning) {}

Meniu& Meniu::operator=(const Meniu& m) {
    if (this != &m) {
        activeGroup = m.activeGroup;
        isRunning = m.isRunning;
    }
    return *this;
}


Meniu::~Meniu() = default;

std::ostream& operator<<(std::ostream& out, const Meniu& m) {
    out << " Share the bill -> active ";
    return out;
}

std::istream& operator>>(std::istream& in, Meniu& m) {
    return in;
}

void Meniu::run() {
    std::cout<<"Start running Meniu"<<std::endl;

    while (isRunning) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Set Group Name\n";
        std::cout << "2. Add User\n";
        std::cout << "3. Add Equal Expense\n";
        std::cout << "4. Show All Expenses\n";
        std::cout << "5. Save Progress to File\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";

        int choice;
        std::cin >> choice;


        try {
            switch (choice) {
                case 1: {
                    std::cin >> activeGroup;
                    break;
                }
                case 2: {
                    User newUser;
                    std::cin >> newUser;
                    activeGroup.addUser(newUser);
                    std::cout << "User successfully added!\n";
                    break;
                }
                case 3: {
                    EqualExpense* eqExp = new EqualExpense();
                    std::cin >> *eqExp;
                    activeGroup.addExpense(eqExp);
                    std::cout << "Expense added!\n";
                    break;
                }
                case 4: {
                    activeGroup.showAllExpenses();
                    break;
                }
                case 5: {
                    activeGroup.saveProgressToFile("app_data.txt");
                    break;
                }
                case 0: {
                    isRunning = false;
                    std::cout << "Exiting app. Goodbye!\n";
                    break;
                }
                default:
                    std::cout << "Invalid choice. Try again.\n";
            }
        }

        catch (const std::invalid_argument& e) {
            std::cerr << "\n[Input Error]: " << e.what() << "\n";
        }
        catch (const std::runtime_error& e) {
            std::cerr << "\n[System Error]: " << e.what() << "\n";
        }
        catch (const std::exception& e) {
            std::cerr << "\n[Unknown Error]: " << e.what() << "\n";
        }
    }
}




