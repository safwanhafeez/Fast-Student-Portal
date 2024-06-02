#include "../include/quiz.h"
#include "../include/teacher.h"
#include "../include/newtime.h"

Quiz::Quiz(string teach, string sub, Teacher *t) {
    serialNo = teach;
    subject = sub;
    quizCheck = false;
    this->t = t;
    stuCheck = false;
    teachCheck = true;

    markers[0] = "a5380ee"; // Topic title of the questions
    markers[1] = "2efcde9"; // MCQs Questions
    markers[2] = "dabfac4"; // Correct option
    markers[3] = "b94d27b"; // True/False Questions
    markers[4] = "88f7ace"; // Descriptive questions

    titles[0] = "Topic Title";
    titles[1] = "MCQs";
    titles[2] = "Correct Option";
    titles[3] = "True/False";
    titles[4] = "Descriptive";

    importPath[0] = "import/Quiz/1_PF/pf.txt";
    importPath[1] = "import/Quiz/2_OOP/oop.txt";
    importPath[2] = "import/Quiz/3_IICT/iict.txt";
    importPath[3] = "import/Quiz/4_DS/ds.txt";
    importPath[4] = "import/Quiz/5_ALGO/algo.txt";
    importPath[5] = "import/Quiz/6_SE/se.txt";
    importPath[6] = "import/Quiz/7_RM/rm.txt";
    importPath[7] = "import/Quiz/8_BDA/bda.txt";
    importPath[8] = "import/Quiz/9_AI/ai.txt";
    importPath[9] = "import/Quiz/10_DL/dl.txt";
    importPath[10] = "import/Quiz/11_DIP/dip.txt";

    exportPath[0] = "export/Quiz/1_PF/pf.txt";
    exportPath[1] = "export/Quiz/2_OOP/oop.txt";
    exportPath[2] = "export/Quiz/3_IICT/iict.txt";
    exportPath[3] = "export/Quiz/4_DS/ds.txt";
    exportPath[4] = "export/Quiz/5_ALGO/algo.txt";
    exportPath[5] = "export/Quiz/6_SE/se.txt";
    exportPath[6] = "export/Quiz/7_RM/rm.txt";
    exportPath[7] = "export/Quiz/8_BDA/bda.txt";
    exportPath[8] = "export/Quiz/9_AI/ai.txt";
    exportPath[9] = "export/Quiz/10_DL/dl.txt";
    exportPath[10] = "export/Quiz/11_DIP/dip.txt";

    key[0] = "export/Quiz/1_PF/pf_key.txt";
    key[1] = "export/Quiz/2_OOP/oop_key.txt";
    key[2] = "export/Quiz/3_IICT/iict_key.txt";
    key[3] = "export/Quiz/4_DS/ds_key.txt";
    key[4] = "export/Quiz/5_ALGO/algo_key.txt";
    key[5] = "export/Quiz/6_SE/se_key.txt";
    key[6] = "export/Quiz/7_RM/rm_key.txt";
    key[7] = "export/Quiz/8_BDA/bda_key.txt";
    key[8] = "export/Quiz/9_AI/ai_key.txt";
    key[9] = "export/Quiz/10_DL/dl_key.txt";
    key[10] = "export/Quiz/11_DIP/dip_key.txt";

    time = new Time();

    findPath();
}
Quiz::Quiz(int n, Student *s) {
    exportPath[0] = "export/Quiz/1_PF/pf.txt";
    exportPath[1] = "export/Quiz/2_OOP/oop.txt";
    exportPath[2] = "export/Quiz/3_IICT/iict.txt";
    exportPath[3] = "export/Quiz/4_DS/ds.txt";
    exportPath[4] = "export/Quiz/5_ALGO/algo.txt";
    exportPath[5] = "export/Quiz/6_SE/se.txt";
    exportPath[6] = "export/Quiz/7_RM/rm.txt";
    exportPath[7] = "export/Quiz/8_BDA/bda.txt";
    exportPath[8] = "export/Quiz/9_AI/ai.txt";
    exportPath[9] = "export/Quiz/10_DL/dl.txt";
    exportPath[10] = "export/Quiz/11_DIP/dip.txt";

    key[0] = "export/Quiz/1_PF/pf_key.txt";
    key[1] = "export/Quiz/2_OOP/oop_key.txt";
    key[2] = "export/Quiz/3_IICT/iict_key.txt";
    key[3] = "export/Quiz/4_DS/ds_key.txt";
    key[4] = "export/Quiz/5_ALGO/algo_key.txt";
    key[5] = "export/Quiz/6_SE/se_key.txt";
    key[6] = "export/Quiz/7_RM/rm_key.txt";
    key[7] = "export/Quiz/8_BDA/bda_key.txt";
    key[8] = "export/Quiz/9_AI/ai_key.txt";
    key[9] = "export/Quiz/10_DL/dl_key.txt";
    key[10] = "export/Quiz/11_DIP/dip_key.txt";

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

    subj[0] = "Programming Fundamentals";
    subj[1] = "Object Oriented Programming";
    subj[2] = "Introduction to Information and Computer Technology";
    subj[3] = "Data Structures";
    subj[4] = "Analysis of Algorithms";
    subj[5] = "Software Requirements Engineering";
    subj[6] = "Research Methodology";
    subj[7] = "Big Data Analytics";
    subj[8] = "Artificial Intelligence";
    subj[9] = "Deep Learning";
    subj[10] = "Digital Image Processing";

    attemptPath = exportPath[n - 1];
    attemptKey = key[n - 1];
    resPath = resultPath[n - 1];
    subject = subj[n - 1];
    this->s = s;
    time = new Time();

    stuCheck = true;
    teachCheck = false;
}
void Quiz::findPath() {
    filePath = importPath[stoi(serialNo) - 1];
    writePath = exportPath[stoi(serialNo) - 1];
    keyPath = key[stoi(serialNo) - 1];

    ifstream checkQuiz(writePath);
    if (checkQuiz) {
        quizCheck = true;
    }
}
void Quiz::storeQuestions(string& MARK, int n) {
    system("cls");
    ifstream infile(filePath);
    ofstream outfile(writePath, ios::app); 
    ofstream quizKey(keyPath, ios::app);

    if (!infile) {
        cerr << "Error: could not open file '" << filePath << "'" << endl;
        return;
    }
    string line;
    bool isCorrectOption = false;
    bool foundStartMark = false;
    int lineCount = 0;
    int qCount;

    if (MARK == "2efcde9") {
        qCount = 5 * n;
    }
    else if (MARK == "b94d27b") {
        qCount = 3 * n;
    }
    else if (MARK == "88f7ace") {
        qCount = n;
    }

    while (getline(infile, line)) {
        if (!foundStartMark && line != MARK) {
            continue;
        }
        else if (line == MARK) {
            foundStartMark = true;
            continue;
        }
        else if (line == markers[2]) {
            isCorrectOption = true;
            continue;
        }
        else if (foundStartMark) {
            bool isMarker = false;
            for (const string& marker : markers) {
                if (line == marker) {
                    isMarker = true;
                    break;
                }
            }
            if (!isMarker) {
                if (isCorrectOption) {
                    quizKey << line[0] << endl;
                    isCorrectOption = false;
                }
                outfile << line << endl;
                lineCount++;
                if (lineCount == qCount) {
                    break;
                }
            }
            else {
                if (lineCount == qCount) {
                    break;
                }
            }
        }
    }
    cout << "=============================================" << endl;
    cout << "              FAST Teacher Portal            " << endl;
    cout << "=============================================" << endl;
    cout << "\nMaking quiz for " << subject << "!" << endl;
    cout << "This might take several seconds..." << endl;
    sleep(2);

    cout << "\nQuiz has been created." << endl;
    cout << "=============================================" << endl;
    cout << "Do you want to add more questions (Y or N): ";
    char opt = getch();
    infile.close();
    outfile.close();
    quizKey.close();

    if (opt == 'y' || opt == 'Y') {
        makeQuiz();
    }
    else {
        quizCheck = true;
        setTime();
    }
}
void Quiz::makeQuiz() {
    system("cls");
    if (quizCheck) {
        system("cls");
        cout << "=============================================" << endl;
        cout << "              FAST Teacher Portal            " << endl;
        cout << "=============================================" << endl;
        cout << "\nQuiz for " << subject << " already exists!" << endl;
        cout << "Delete that quiz to add a new one" << endl;
        cout << "=============================================" << endl;
        navigate();
        return;
    }
    cout << "=============================================" << endl;
    cout << "              FAST Teacher Portal            " << endl;
    cout << "=============================================" << endl;
    cout << "You are now making a quiz for " << subject << "!" << endl;
    cout << "What type of Questions you want:" << endl;
    cout << "\n1. Multiple Choice Questions" << endl;
    cout << "2. True / False Questions" << endl;
    cout << "3. Descriptive Questions" << endl;
    cout << "4. Go Back" << endl;
    cout << "=============================================" << endl;

    char choice;
    cout << "Enter your choice (1-4): ";
    choice = getch();
    int no;

    switch (choice) {
        case '1':
            system("cls");
            cout << "=============================================" << endl;
            cout << "              FAST Teacher Portal            " << endl;
            cout << "=============================================" << endl;
            cout << "How many MCQs you want to add!"<< endl;
            cout << "\nEnter your choice (Max: 5): ";
            cin >> no;
            storeQuestions(markers[1], no);
            return;
            break;
        case '2':
            system("cls");
            cout << "=============================================" << endl;
            cout << "              FAST Teacher Portal            " << endl;
            cout << "=============================================" << endl;
            cout << "How many True/False you want to add!"<< endl;
            cout << "\nEnter your choice (Max: 5): ";
            cin >> no;
            while (no > 5 || no < 0) {
                cout << "\nMaximum Allowed Questions are 5, Please enter again: ";
                cin >> no;
            }
            storeQuestions(markers[3], no);
            return;
            break;
        case '3':
            system("cls");
            cout << "=============================================" << endl;
            cout << "              FAST Teacher Portal            " << endl;
            cout << "=============================================" << endl;
            cout << "How many Descriptive you want to add!"<< endl;
            cout << "\nEnter your choice (Max: 5): ";
            cin >> no;
            storeQuestions(markers[4], no);
            return;
            break;
        case '4':
            mainMenu();
            return;
            break;
        default:
            navigate();
            return;
            break;
    }
}
void Quiz::navigate() {
    char userChoice;

    cout << "\n=> Press 'H' to go back to Home screen or 'Q' to Quit: ";
    userChoice = getch();

    while (tolower(userChoice) != 'h' && tolower(userChoice) != 'q')
    {
        cout << "\nSorry, we received a wrong input. Please re-enter (H' -> Home Screen or 'Q' -> Quit): ";
        cin >> userChoice;
    }
    switch (tolower(userChoice))
    {
        case 'h':
            if (teachCheck) {
                t->menu();
            }
            else if (stuCheck) {
                s->menu();
            }
            break;

        case 'q':
            cout << "\n=> Exiting....This might take several seconds";
            sleep(1);
            exit(0);
            break;
    }
}
void Quiz::deleteQuiz() {
    ifstream quiz(writePath);
    ifstream key(keyPath);
    const char* wP = writePath.c_str();
    const char* kP = keyPath.c_str();

    if (quiz) {
        quiz.clear();
        key.clear();

        system("cls");
        cout << "=============================================" << endl;
        cout << "              FAST Teacher Portal            " << endl;
        cout << "=============================================" << endl;
        cout << "Deleteing Quiz for " << subject << "!" << endl;

        cout << "This might take several seconds..." << endl;
        sleep(2);

        cout << "\nQuiz has been deleted." << endl;
        cout << "=============================================" << endl;
        quiz.close();
        key.close();

        remove(wP);
        remove(kP);
        navigate();
        return;
    }
    else {
        system("cls");
        cout << "=============================================" << endl;
        cout << "              FAST Teacher Portal            " << endl;
        cout << "=============================================" << endl;
        cout << "Quiz for " << subject << " has not been created yet!" << endl;
        cout << "\n=============================================" << endl;
        navigate();
        return;
    }
}
void Quiz::attemptQuiz() {
    system("cls");
    
    if (!timingCheck()) {
        cout << "=============================================" << endl;
        cout << "              FAST Student Portal            " << endl;
        cout << "=============================================" << endl;
        cout << "\nQuiz for " << subject << " can't be" << endl;
        cout << "attempted currently, Please try again later." << endl;
        cout << "=============================================" << endl;
        navigate();
    }
    if (hasAttemptedQuiz(s->getRoll())) {
        cout << "=============================================" << endl;
        cout << "              FAST Student Portal            " << endl;
        cout << "=============================================" << endl;
        cout << "\nQuiz for " << subject << " has already" << endl;
        cout << "been attempted by " << s->getUsr() << endl;
        cout << "=============================================" << endl;
        navigate();
        return;
    }

    ifstream quizFile(attemptPath);
    ifstream answerKey(attemptKey);
    ofstream result(resPath, ios::app);

    if (!quizFile) {
        cout << "=============================================" << endl;
        cout << "              FAST Student Portal            " << endl;
        cout << "=============================================" << endl;
        cout << "\nQuiz for " << subject << " has not been created yet." << endl;
        cout << "Please wait for Teacher to create the quiz first." << endl;
        cout << "=============================================" << endl;
        navigate();
        return;
    }
    if (!quizFile || !answerKey) {
        cerr << "Error: could not open quiz or answer key file" << endl;
        return;
    }
    string question;
    string optionA, optionB, optionC, optionD;
    char correctAnswer;
    string tempAns;
    string tempUsr;
    int score = 0;
    int questionCount = 0;
    bool MCQ;

    while (getline(quizFile, question)) {
        getline(quizFile, optionA);
        getline(quizFile, optionB);

        if (((optionA == "a) True") || (optionA == "a) False")) || ((optionB == "b) True") || (optionB == "b) False"))) {
            MCQ = true;
        }
        if (!MCQ) {
            getline(quizFile, optionC);
            getline(quizFile, optionD);
        }
        getline(answerKey, tempAns);

        system("cls");
        cout << "=============================================" << endl;
        cout << "              FAST Student Portal            " << endl;
        cout << "=============================================" << endl;
        cout << "\nQuestion " << questionCount + 1 << ":" << endl;
        cout << question << endl;
        
        if (optionA == "a) True" || optionA == "a) False" || optionB == "b) True" || optionB == "b) False") {
            cout << "\n" << optionA << endl;
            cout << optionB << endl;
        }
        else {
            cout << "\n" << optionA << endl;
            cout << optionB << endl;
            cout << optionC << endl;
            cout << optionD << endl;
        }
        cout << "\n=============================================" << endl;

        char ans;
        cout << "Enter your answer (A/B/C/D): ";
        cin >> tempUsr;

        correctAnswer = tempAns.at(0);
        ans = tempUsr.at(0);

        if (tolower(ans) == tolower(correctAnswer)) {
            cout << "\nYour answer is Correct!";
            sleep(1);
            score++;
        }
        else {
            cout << "\nYour answer is Incorrect.";
            sleep(1);
        }
        questionCount++;
    }
    quizFile.close();
    answerKey.close();

    system("cls");
    cout << "=============================================" << endl;
    cout << "              FAST Student Portal            " << endl;
    cout << "=============================================" << endl;
    cout << "\nQuiz for " << subject << " is over!" << endl;
    cout << "Your score is: " << score << "/" << questionCount << endl;
    cout << "=============================================" << endl;

    float percentage = ((float)score / (float)questionCount) * 100;
    result << s->getUsr() << "," << s->getName() << "," << score << "," << questionCount << "," << percentage << "%" << endl;
    result.close();

    navigate();
}
bool Quiz::hasAttemptedQuiz(string id) {
    ifstream resultFile(resPath);

    if (!resultFile) {
        cerr << "Error: could not open result file" << endl;
        return false;
    }
    string line;

    while (getline(resultFile, line)) {
        stringstream ss(line);
        string rollno, sname, obtained, total;
        getline(ss, rollno, ',');
        getline(ss, sname, ',');
        getline(ss, obtained, ',');
        getline(ss, total);

        if (rollno == id) {
            resultFile.close();
            return true;
        }
    }
    resultFile.close();
    return false;
}
void Quiz::setTime() {
    system("cls");
    ofstream timeFile("export/Time/timings.csv");
    int h,s;

    if (!timeFile) {
        cerr << "Error: could not open time file" << endl;
        return;
    }
    cout << "=============================================" << endl;
    cout << "              FAST Teacher Portal            " << endl;
    cout << "=============================================" << endl;
    cout << "Enter the time for the Quiz." << endl;
    cout << "\nEnter Hours: ";
    cin >> h;
    time->setHour(h);

    cout << "Enter Minutes: ";
    cin >> s;
    time->setMinute(s);

    cout << "=============================================" << endl;
    cout << "Setting Time for Quiz of " << subject << endl;
    sleep(1);

    timeFile << subject << "," << time->getHour() << "," << time->getMinute() << endl;
    timeFile.close();

    navigate();
}
bool Quiz::timingCheck() {
    Time currentTime;

    ifstream file("export/Time/timings.csv");
    int hour, minute;

    if (file) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string quizSubject;
            string quizHour, quizMinute;

            if (getline(ss, quizSubject, ',') && getline(ss, quizHour, ',') && getline(ss, quizMinute, ',')) {
                if (quizSubject == subject) {
                    hour = stoi(quizHour);
                    minute = stoi(quizMinute);
                }
            }
        }
    }
    time->setHour(hour);
    time->setMinute(minute);

    if ((currentTime.getHour() <= time->getHour()) && (currentTime.getMinute() <= time->getMinute())) {
        sleep(2);
        return false;
    }
    return true;
}