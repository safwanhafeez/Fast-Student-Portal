#ifndef ANALYTICS_H
#define ANALYTICS_H

#include <fstream>
#include <iostream>
using namespace std;

class Teacher;

class Analytics: public Teacher {
    private:
        string resPath;
        int totalStu;
        int attempted;
        int highest;
        int lowest;
        float avg;
        Teacher *t;
        string resultPath[11];

    public:
        Analytics(Teacher *t);
        void menu();
        void viewResult();
        void navigate();
        void viewHighestLowest();
        void viewGraph();
        void viewAverage();
        void viewStudentList();
        void makeGraph(double, int, int );
};

#endif