#ifndef TEACHER_H
#define TEACHER_H

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
#include "quiz.h"
using namespace std;

void mainMenu();

class Teacher: public User {
    private:
        bool check;

    public:
        string tno;
        string sub;
        Teacher(int);
        string getSubject();
        void findSub();
        void defaultRun();
        void menu();
        void courseView();
        bool passAuth(string& str);
        void changePassword();
        void navigate();
        void logout();
};

#endif // TEACHER_H