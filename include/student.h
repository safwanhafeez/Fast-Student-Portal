#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <Windows.h>
#include <unistd.h>
#include <iomanip>
#include <chrono>
#include "user.h"

using namespace std;

class Quiz;

void mainMenu();

class Student: public User {
    private:
        int sub[11];
        string sno;
        string sname;
        bool check, login;
        string subjects[11];

    public: 
        Student(string i);
        string getName();
        string getRoll();
        void defaultRun();
        void menu();
        bool authID();
        void courseView();
        void studentInfo();
        void navigate();
        void logout();
        void quizMenu();
};

#endif