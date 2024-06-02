#ifndef QUIZ_H
#define QUIZ_H

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <Windows.h>
#include <unistd.h>
#include <iomanip>
#include <chrono>
using namespace std;

class Teacher;
class Student;
class Time;

void mainMenu();

class Quiz {
    private:
        string filePath, writePath, keyPath;
        string markers[5], titles[5];
        string importPath[11], exportPath[11], key[11], resultPath[11];
        string serialNo, subject;
        bool quizCheck;
        bool attempt;
        Teacher *t;
        Student *s;
        string attemptPath;
        string attemptKey;
        bool teachCheck, stuCheck;
        string resPath;
        string subj[11];
        Time *time;

    public:
        Quiz(string, string , Teacher*);
        Quiz(int n, Student*);
        void findPath();
        void storeQuestions(string& , int) ;
        void makeQuiz();
        void navigate();
        void deleteQuiz();
        void attemptQuiz();
        bool hasAttemptedQuiz(string);
        void setTime();
        bool timingCheck();
};

#endif