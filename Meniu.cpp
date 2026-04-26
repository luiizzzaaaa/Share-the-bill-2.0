#include "Meniu.h"
#include "User.h"
#include "EqualExpense.h"
#include "PercentageExpense.h"
#include <stdexcept>
#include <string>


Meniu::Meniu() : isRunning(true) {}

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
        std::cout << "1. User Management\n";
        std::cout << "2. Expense Management\n";
        std::cout << "3. Group Analytics & Tools\n";
        std::cout << "4. File Options (Save/Load)\n";
        std::cout << "0. Exit Application\n";
        std::cout << "Choose a category: ";

        int choice;
        if (!(std::cin >> choice)) { std::cin.clear(); std::cin.ignore(1000, '\n'); continue; }


        switch (choice) {
            case 1: userMenu(); break;
            case 2: expenseMenu(); break;
            case 3: groupMenu(); break;
            case 4: fileMenu(); break;
            case 0:
                isRunning = false;
                std::cout << "Exiting app\n";
                break;
            default: std::cout << "Invalid choice. Try again.\n";
        }
    }
}

void Meniu::userMenu() {
    bool back = false;
    while (!back) {
        std::cout << "\n USER MANAGEMENT\n";
        std::cout << "1. Add New User\n";
        std::cout << "2. Show All Users\n";
        std::cout << "3. Remove a User\n";
        std::cout << "0. Back to Main Menu\n";
        std::cout << "Choice: ";

        int choice;
        if (!(std::cin >> choice)) { std::cin.clear(); std::cin.ignore(1000, '\n'); continue; }

        try {
            switch (choice) {
                case 1: {
                    User newUser;
                    std::cin >> newUser;
                    activeGroup.addUser(newUser);
                    std::cout << "User successfully added!\n";
                    break;
                }
                case 2:
                    activeGroup.showAllUsers();
                    break;
                case 3: {
                    std::string nameToDelete;
                    std::cout << "Enter exact name of the user to delete: ";
                    std::cin >> nameToDelete;
                    activeGroup.removeUser(nameToDelete);
                    break;
                }
                case 0: back = true; break;
                default: std::cout << "Invalid choice.\n";
            }
        } catch (const std::exception& e) { std::cerr << "Error: " << e.what() << "\n"; }
    }
}

void Meniu::expenseMenu() {
    bool back = false;
    while (!back) {
        std::cout << "\nEXPENSE MANAGEMENT\n";
        std::cout << "1. Add EQUAL Expense\n";
        std::cout << "2. Add PERCENTAGE Expense\n";
        std::cout << "3. Show All Expenses (Polymorphism)\n";
        std::cout << "0. Back to Main Menu\n";
        std::cout << "Choice: ";

        int choice;
        if (!(std::cin >> choice)) { std::cin.clear(); std::cin.ignore(1000, '\n'); continue; }

        try {
            switch (choice) {
                case 1: {
                    EqualExpense* eqExp = new EqualExpense();
                    std::cin >> *eqExp;
                    activeGroup.addExpense(eqExp);
                    std::cout << "Equal expense added!\n";
                    break;
                }
                case 2: {
                    PercentageExpense* pctExp = new PercentageExpense();
                    std::cin >> *pctExp;
                    activeGroup.addExpense(pctExp);
                    std::cout << "Percentage expense added!\n";
                    break;
                }
                case 3:
                    activeGroup.showAllExpenses();
                    break;
                case 0: back = true; break;
                default: std::cout << "Invalid choice.\n";
            }
        } catch (const std::exception& e) { std::cerr << "Error: " << e.what() << "\n"; }
    }
}


void Meniu::groupMenu() {
    bool back = false;
    while (!back) {
        std::cout << "\n GROUP ANALYTICS & TOOLS \n";
        std::cout << "1. Set / Change Group Name\n";
        std::cout << "2. Show Group Awards\n";
        std::cout << "3. Show Individual User Dashboard\n";
        std::cout << "4. Run Simplify Debts Algorithm\n";
        std::cout << "0. Back to Main Menu\n";
        std::cout << "Choice: ";

        int choice;
        if (!(std::cin >> choice)) { std::cin.clear(); std::cin.ignore(1000, '\n'); continue; }

        try {
            switch (choice) {
                case 1:
                    std::cin >> activeGroup;
                    std::cout << "Group name updated!\n";
                    break;
                case 2:
                    activeGroup.showGroupAwards();
                    break;
                case 3: {
                    std::string searchName;
                    std::cout << "Enter exact user name: ";
                    std::cin >> searchName;
                    activeGroup.showUserDashboard(searchName);
                    break;
                }
                case 4:
                    activeGroup.simplifyDebts();
                    break;
                case 0: back = true; break;
                default: std::cout << "Invalid choice.\n";
            }
        } catch (const std::exception& e) { std::cerr << "Error: " << e.what() << "\n"; }
    }
}


void Meniu::fileMenu() {
    bool back = false;
    while (!back) {
        std::cout << "\n FILE OPTIONS\n";
        std::cout << "1. Save Progress to File\n";
        std::cout << "2. Load Progress from File\n";
        std::cout << "0. Back to Main Menu\n";
        std::cout << "Choice: ";

        int choice;
        if (!(std::cin >> choice)) { std::cin.clear(); std::cin.ignore(1000, '\n'); continue; }

        try {
            switch (choice) {
                case 1:
                    activeGroup.saveProgressToFile("app_data.txt");
                    break;
                case 2:
                    activeGroup.loadProgressFromFile("app_data.txt");
                    break;
                case 0: back = true; break;
                default: std::cout << "Invalid choice.\n";
            }
        } catch (const std::exception& e) { std::cerr << "Error: " << e.what() << "\n"; }
    }
}




