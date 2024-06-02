#include "../include/analytics.h"

Analytics::Analytics(Teacher *t) {
    this->t = t;

    resultPath[0] = "export/Result/1_PF/pf_result.csv";
    resultPath[1] = "export/Result/2_OOP/oop_result.csv";
    resultPath[2] = "export/Result/3_IICT/iict_result.csv";
    resultPath[3] = "export/Result/4_DS/ds_result.csv";
    resultPath[4] = "export/Result/5_ALGO/algo_result.csv";
    resultPath[5] = "export/Result/6_SE/se_result.csv";
    resultPath[6] = "export/Result/7_RM/rm_result.csv";
    resultPath[7] = "export/Result/8_BDA/bda_result.csv";
    resultPath[8] = "export/Result/9_AI/ai_result.csv";
    resultPath[9] = "export/Result/10_DL/dl_result.csv";
    resultPath[10] = "export/Result/11_DIP/dip_result.csv";

    resPath = resultPath[stoi(t->tno) - 1];
    totalStu = 216;

    highest = 0;
    lowest = 10000;
}
void Analytics::menu() {
    system("cls");
    cout << "=============================================" << endl;
    cout << "              FAST Teacher Portal            " << endl;
    cout << "=============================================" << endl;
    cout << "Welcome to the Analytics Portal, Choose any option." << endl;
    cout << "\n1. View Quiz Results" << endl;
    cout << "2. View Highest/Lowest Marks" << endl;
    cout << "3. View Average and Percentage" << endl;
    cout << "4. View Graph" << endl;
    cout << "5. View Student List" << endl;
    cout << "6. Go Back" << endl;
    cout << "=============================================" << endl;
    cout << "Enter your choice (1-6): ";
    int choice;
    choice = getch();

    switch (choice) {
        case '1':
            viewResult();
            break;
        case '2':
            viewHighestLowest();
            break;
        case '3':
            viewAverage();
            break;
        case '4':
            viewGraph();
            break;
        case '5':
            viewStudentList();
            break;
        case '6':
            t->menu();
            break;
        default:
            navigate();
            break;
    }
}
void Analytics::viewResult() {
    system("cls");
    cout << "=============================================" << endl;
    cout << "              FAST Teacher Portal            " << endl;
    cout << "=============================================" << endl;

    ifstream result(resPath);
    if (!result.is_open()) {
        cout << "File not found." << endl;
        return;
    }
    string line;
    while (getline(result, line)) {
        stringstream ss(line);
        string id, name;
        string correct, total;
        string percentage;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, correct, ',');
        getline(ss, total, ',');
        getline(ss, percentage);

        cout << "=============================================" << endl;
        cout << "Student ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Correct answers: " << correct << endl;
        cout << "Total questions attempted: " << total << endl;
        cout << "Percentage score: " << percentage << "%" << endl;
        cout << "=============================================" << endl;
    }
    navigate();
}
void Analytics::navigate() {
    char userChoice;

    cout << "\n=> Press 'H' to go back to Home screen or 'Q' to Quit: ";
    userChoice = getch();

    while (tolower(userChoice) != 'h' && tolower(userChoice) != 'q')
    {
        cout << "Sorry, we received a wrong input. Please re-enter (H' -> Home Screen or 'Q' -> Quit): ";
        cin >> userChoice;
    }
    switch (tolower(userChoice))
    {
        case 'h':
            menu();
            break;

        case 'q':
            cout << "\n=> Exiting....This might take several seconds";
            
            sleep(1);
            exit(0);

            break;
    }
}
void Analytics::viewHighestLowest() {
    system("cls");
    cout << "=============================================" << endl;
    cout << "          FAST Teacher Portal - Results       " << endl;
    cout << "=============================================" << endl;

    ifstream result(resPath);
    if (!result.is_open()) {
        cout << "File not found." << endl;
        return;
    }
    string line;
    string maxName, minName;

    while (getline(result, line)) {
        stringstream ss(line);
        string id, name;
        string correct, total;
        string percentage;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, correct, ',');
        getline(ss, total, ',');
        getline(ss, percentage);

        int currentScore = stoi(correct);
        if (currentScore > highest) {
            highest = currentScore;
            maxName = name;
        }
        if (currentScore < lowest) {
            lowest = currentScore;
            minName = name;
        }
    }
    cout << "Highest score: " << maxName << " (" << highest << ")" << endl;
    cout << "Lowest score: " << minName << " (" << lowest << ")" << endl;
    navigate();
}
void Analytics::viewAverage() {
    system("cls");
    cout << "=============================================" << endl;
    cout << "          FAST Teacher Portal - Results       " << endl;
    cout << "=============================================" << endl;

    ifstream result(resPath);
    if (!result.is_open()) {
        cout << "File not found." << endl;
        return;
    }
    int totalScores = 0,totalPercent = 0, count = 0;
    float average;
    string line;

    while (getline(result, line)) {
        stringstream ss(line);
        string id, name;
        string correct, total;
        string percentage;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, correct, ',');
        getline(ss, total, ',');
        getline(ss, percentage);
        
        int currentScore = stoi(correct);
        totalScores += currentScore;

        int currectPercent = stoi(percentage);
        totalPercent += currectPercent;
        count++;
    }
    if (count == 0) {
        cout << "No results found." << endl;
    }
    else {
        avg = (totalScores) / count;
        average = (totalPercent) / count;
        cout << "Average score: " << avg << endl;
        cout << "Average Percentage: " << average << "%" << endl;
    }
    navigate();
}
void Analytics::viewStudentList() {
    system("cls");
    ifstream stud("data/students.csv");
    string line, sno, id, sname, entry;
    int sub[11] = {0};
    int count = 0;
    int serial = 1;

    cout << "=============================================" << endl;
    cout << "          FAST Teacher Portal - Results       " << endl;
    cout << "=============================================" << endl;
    cout << "Following are the Students: " << endl;
    cout << endl;

    while (getline(stud, line)) {
        stringstream stream(line);
        getline(stream, sno, ',');
        getline(stream, id, ',');
        getline(stream, sname, ',');

        if (count > 2) {
            int i = 0;
            while (getline(stream, entry, ',')) {
                sub[i] = stoi(entry);
                i++;
            }
            if (sub[10] == 1) {
                cout << serial << ". " << sname << endl;
                serial++;
            }
        }
        count++;
    }
    stud.close();
    navigate();
}
void Analytics::viewGraph() {
    system("cls");
    cout << "=============================================" << endl;
    cout << "          FAST Teacher Portal - Results       " << endl;
    cout << "=============================================" << endl;
    ifstream result(resPath);
    int totalScores = 0,totalPercent = 0, count = 0;
    float average;
    string line;

    while (getline(result, line)) {
        stringstream ss(line);
        string id, name;
        string correct, total;
        string percentage;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, correct, ',');
        getline(ss, total, ',');
        getline(ss, percentage);

        int current = stoi(correct);
        if (current > highest) {
            highest = current;
        }
        if (current < lowest) {
            lowest = current;
        }
        int currentScore = stoi(correct);
        totalScores += currentScore;

        int currectPercent = stoi(percentage);
        totalPercent += currectPercent;
        count++;
    }
    if (count != 0) {
        avg = (totalScores) / count;
        average = (totalPercent) / count;
    }
    result.close();

    makeGraph(avg, highest, lowest);
    cout << "=============================================" << endl;

    navigate();
}
void Analytics::makeGraph(double a, int h, int l)
{
    cout << "Average: ";
    for (int i = 0; i < a; i++) {
        cout << "* ";
    }

    cout << "\nHighest: ";
    for (int i = 0; i < h; i++) {
        cout << "* ";
    }

    cout << "\nLowest:  ";
    for (int i = 0; i < l; i++) {
        cout << "* ";
    }
    cout << endl;
    
    navigate();
}