cmake_minimum_required(VERSION 4.1)
project(Share_the_bill_2_0)

set(CMAKE_CXX_STANDARD 20)

add_executable(Share_the_bill_2_0 main.cpp
        User.h
        User.cpp
        Expense.h
        Expense.cpp
        EqualExpense.h
        EqualExpense.cpp
        PercentageExpense.h
        PercentageExpense.cpp)
