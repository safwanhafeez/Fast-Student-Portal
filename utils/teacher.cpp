#include "../include/teacher.h"
#include "../include/analytics.h"

Teacher::Teacher(int i = 0) {
    tno = i;
    check = false;
}
string Teacher::getSubject() {
    return sub;
}
void Teacher::findSub() {
    const int NUM_COURSES = 11;
    int courses[NUM_COURSES];
    string subjects[11] = {
        "Programming Fundamentals",
        "Object Oriented Programming",
        "Introduction to Information and Computer Technology",
        "Data Structures",
        "Analysis of Algorithms",
        "Software Requirements Engineering",
        "Research Methodology",
        "Big Data Analytics",
        "Artificial Intelligence",
        "Deep Learning",
        "Digital Image Processing"
    };
    string line;
    ifstream file("data/teachersubjects.csv");

    int row = 1;

    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string tname;
            int i = 0;

            getline(ss, tname, ',');
            if (tname == usr) {
                while (getline(ss, line, ',')) {
                    courses[i] = stoi(line);
                    i++;
                }
                for (int i = 0; i < NUM_COURSES; i++) {
                    if (courses[i] == 1) {
                        sub = subjects[i];
                    }
                }
                break;
            }
            row++;
        }
        file.close();
    }
    else {
        cout << "Error: Unable to open file." << endl;
    }
}
void Teacher::defaultRun() {
    system("cls");
    cout << "=============================================" << endl;
    cout << "              FAST Teacher Login             " << endl;
    cout << "=============================================" << endl;
    cout << "Enter Your Name: ";
    getline(cin, usr);
    char c;

    cout << "Enter Your Password: ";
    while ((c = _getch()) != '\r') { 
        if (c == '\b') { 
            if (pwd.length() > 0) {
                pwd = pwd.substr(0, pwd.length()-1);
                cout << "\b \b";
            }
        }
        else {
            pwd += c;
            cout << '*'; // display a * instead of the actual character
        }
    }

    cout << "\n\nValidating...This might take several seconds." << endl;
    sleep(1);

    ifstream readFile("data/teachers.csv");
    if (!readFile) {
        cout << "Error: could not open file 'teachers.csv'" << endl;
        return;
    }

    string line, tpass, tname;
    bool flag;
    
    while (getline(readFile, line)) {
        stringstream stream(line);
        getline(stream, tno, ',');
        getline(stream, tname, ',');
        getline(stream, tpass, ',');

        if (usr == tname && pwd == tpass) {
            check = true;
            flag = true;
            readFile.close();
            findSub();
            menu();
            break;
        }
    }
    if (!flag) {
        cout << "Invalid username or password." << endl;
        navigate();
    }
    readFile.close();
}
void Teacher::menu() {
    Quiz q(tno, sub, this);
    system("cls");
    cout << "=============================================" << endl;
    cout << "              FAST Teacher Portal            " << endl;
    cout << "=============================================" << endl;
    cout << "Welcome Teacher, " << usr << endl;
    cout << "Please select an option from the menu below:" << endl;
    cout << "\n1. View Current Courses" << endl;
    cout << "2. Change your Password "<< endl;
    cout << "3. View Student Analytics "<< endl;
    cout << "4. Make a Quiz" << endl;
    cout << "5. Delete a Quiz" << endl;
    cout << "6. Logout from your Portal" << endl;
    cout << "7. Exit" << endl;
    cout << "=============================================" << endl;

    char choice;
    cout << "Enter your choice (1-7): ";
    choice = getch();

    switch(choice) {
        case '1':
            courseView();
            break;
        case '2':
            changePassword();
            break;
        case '3': {
            Analytics a(this);
            a.menu();
            break;
        }
        case '4':
            q.makeQuiz();
            break;
        case '5':
            q.deleteQuiz();
            break;
        case '6':
            logout();
            break;
        case '7':
            cout << "\nExiting the program..." << endl;
            sleep(1);
            return;
        default:
            navigate();
            break;
    }
}
void Teacher::courseView() {
    system("cls");
    cout << "=============================================" << endl;
    cout << "              FAST Teacher Portal            " << endl;
    cout << "=============================================" << endl;
    const int NUM_COURSES = 11;
    int courses[NUM_COURSES];
    string subjects[11] = {
        "Programming Fundamentals",
        "Object Oriented Programming",
        "Introduction to Information and Computer Technology",
        "Data Structures",
        "Analysis of Algorithms",
        "Software Requirements Engineering",
        "Research Methodology",
        "Big Data Analytics",
        "Artificial Intelligence",
        "Deep Learning",
        "Digital Image Processing"
    };
    string line;
    ifstream file("data/teachersubjects.csv");

    int row = 1;

    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string tname;
            int i = 0;

            getline(ss, tname, ',');
            if (tname == usr) {
                while (getline(ss, line, ',')) {
                    courses[i] = stoi(line);
                    i++;
                }
                cout << "You teach the following courses: " << endl;
                cout << endl;

                for (int i = 0; i < NUM_COURSES; i++) {
                    if (courses[i] == 1) {
                        cout << subjects[i] << endl;
                        sub = subjects[i];
                    }
                }
                break;
            }
            row++;
        }
        file.close();
    }
    else {
        cout << "Error: Unable to open file." << endl;
    }
    navigate();
}
bool Teacher::passAuth(string& str) {
    bool len = false, upper = false, spec = false, lower = false, digit = false;

    if (str.length() >= 12) {
        len = true;
    }
    else {
        return 0;
    }

    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            upper = true;
        }
        if (str[i] >= 'a' && str[i] <= 'z') {
            lower = true;
        }
        if (str[i] >= '0' && str[i] <= '9') {
            digit = true;
        }
        if ((str[i] >= 33 && str[i] <= 47) || (str[i] >= 58 && str[i] <= 64) || (str[i] >= 91 && str[i] <= 96) || (str[i] >= 123 && str[i] <= 126)){
            spec = true;
        }
    }
    return (len && upper && lower && digit && spec);
}
void Teacher::changePassword() {
    system("cls");
    cout << "=============================================" << endl;
    cout << "             Change Password                 " << endl;
    cout << "=============================================" << endl;
    cout << "Enter current password: ";
    string curPwd;
    char c;

    while ((c = _getch()) != '\r') { 
        if (c == '\b') { 
            if (curPwd.length() > 0) {
                curPwd = curPwd.substr(0, curPwd.length() - 1);
                cout << "\b \b";
            }
        }
        else {
            curPwd += c;
            cout << '*'; // display a * instead of the actual character
        }
    }
    if (curPwd != pwd) {
        cout << "\nThe Password you entered doesn't match your Current Password" << endl;
        navigate();
        return;
    }

    ifstream readFile("data/teachers.csv", ios::in);
    ofstream writeFile("data/teachers_temp.csv", ios::out);

    if (!readFile || !writeFile) {
        cout << "Error: could not open file" << endl;
        return;
    }

    string line, tpass, tname;
    bool flag = false;

    while (getline(readFile, line)) {
        stringstream stream(line);
        getline(stream, tno, ',');
        getline(stream, tname, ',');
        getline(stream, tpass, ',');

        if (usr == tname && curPwd == tpass) {
            flag = true;
            string newPassword;
            cout << "\nEnter new password: ";
            getline(cin, newPassword);

            if (passAuth(newPassword)) {
                writeFile << tno << "," << tname << "," << newPassword << endl;
                cout << "Password updated successfully!" << endl;
            }
            else {
                cout << "Password doesn't meet the requirements!" << endl;
                readFile.close();
                writeFile.close();
                remove("data/teachers_temp.csv");
                navigate();
                return;
            }
        }
        else {
            writeFile << line << endl;
        }
    }
    readFile.close();
    writeFile.close();

    if (remove("data/teachers.csv") != 0) {
        cout << "Error deleting file" << endl;
    }
    // Rename the temporary file
    if (rename("data/teachers_temp.csv", "data/teachers.csv") != 0) {
        cout << "Error renaming file" << endl;
    }
    if (!flag) {
        cout << "Invalid current password." << endl;
    }
    navigate();
}
void Teacher::navigate() {
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
            if (check) {
                menu();
            }
            else {
                mainMenu();
            }
            break;

        case 'q':
            cout << "\n=> Exiting....This might take several seconds";
            
            sleep(1);
            exit(0);

            break;
    }
}
void Teacher::logout() {
    system("cls");
    cout << "=============================================" << endl;
    cout << "               FAST UMS Portal               " << endl;
    cout << "=============================================" << endl;
    cout << "Welcome to the University Management System!" << endl;
    cout << "\nLogging out from your account, This might take several seconds..." << endl;
    check = false;
    sleep(2);
    usr = "";
    pwd = "";
    mainMenu();
}