#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <Windows.h>
#include <unistd.h>
#include <iomanip>
#include <chrono>
#include "include/user.h"
#include "include/teacher.h"
#include "include/quiz.h"
#include "include/student.h"
#include "include/newtime.h"
#include "include/analytics.h"
#include "utils/quiz.cpp"
#include "utils/student.cpp"
#include "utils/teacher.cpp"
#include "utils/user.cpp"
#include "utils/newtime.cpp"
#include "utils/analytics.cpp"
using namespace std;

void mainMenu() {
    Student s;
    Teacher t;

    system("cls");
    cout << "=============================================" << endl;
    cout << "               FAST UMS Portal               " << endl;
    cout << "=============================================" << endl;
    cout << "Welcome to the University Management System!" << endl;
    cout << "Please select an option from the menu below:" << endl;
    cout << "\n1. Student Login" << endl;
    cout << "2. Teacher Login" << endl;
    cout << "3. Exit" << endl;
    cout << "=============================================" << endl;
    char choice;
    bool invalidChoice;

    do {
        invalidChoice = false;
        cout << "Enter your choice (1-3): ";
        choice = getch();

        switch(choice) {
            case '1':
                s.defaultRun();
                break;
            case '2':
                t.defaultRun();
                break;
            case '3':
                cout << "\nExiting the program..." << endl;
                sleep(1);
                return;
            default:
                cout << "\nInvalid choice! Please try again." << endl;
                invalidChoice = true;
                break;
        }
    }   while (invalidChoice);
}

int main() 
{
    mainMenu();

    return 0;
}