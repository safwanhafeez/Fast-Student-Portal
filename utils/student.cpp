#include "../include/student.h"
#include "../include/quiz.h"

Student::Student(string i = "\0") {
    sno = i;
    login = false;
}
string Student::getName() {
    return sname;
}
string Student::getRoll() {
    return usr;
}
void Student::defaultRun() {
    system("cls");
    cout << "=============================================" << endl;
    cout << "               FAST Student Login            " << endl;
    cout << "=============================================" << endl;
    cout << "Enter Your Nu ID (12I-3456): ";
    cin >> usr;

    cout << "Enter Your Password: ";
    char c;
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

    if (!authID()) {
        cout << "Invalid ID." << endl;
    }
    ifstream readFile("data/students.csv");
    string line, id;

    while(getline(readFile,line)) {
        stringstream stream(line);
        getline(stream, sno, ',');
        getline(stream, id, ',');
        getline(stream, sname, ',');

        if (usr == id) {
            ifstream passwordFile("data/studentPasswords.csv");
            string passLine, serial, password;

            while (getline(passwordFile, passLine)) {
                stringstream passStream(passLine);
                getline(passStream, serial, ',');
                getline(passStream, password, ',');

                if (serial == sno && password == pwd) {
                    check = true;
                    login = true;
                    menu();
                    return;
                }
            }
            if (!check) {
                cout << "Incorrect Nu ID or password." << endl;
                navigate();
            }
            passwordFile.close();                   
            break;  
        }
    }
    if (!check) {
        cout << "Student not Found." << endl;
        navigate();
    }
    readFile.close();
}
void Student::menu() {
    system("cls");
    cout << "=============================================" << endl;
    cout << "              FAST Student Portal            " << endl;
    cout << "=============================================" << endl;
    cout << "Welcome Student, " << sname << endl;
    cout << "Please select an option from the menu below:" << endl;
    cout << "\n1. View Courses" << endl;
    cout << "2. View Personal Information" << endl;
    cout << "3. Attempt a quiz" << endl;
    cout << "4. Logout from your Portal" << endl;
    cout << "5. Exit" << endl;
    cout << "=============================================" << endl;

    char choice;
    cout << "Enter your choice (1-5): ";
    choice = getch();

    switch(choice) {
        case '1':
            courseView();
            break;
        case '2':
            studentInfo();
            break;
        case '3':
            quizMenu();
            break;
        case '4':
            logout();
            return;
        case '5':
            cout << "\nExiting the program..." << endl;
            sleep(1);
            exit(0);
            break;
        default:
            navigate();
            break;
    }
}
bool Student::authID() {
    if (usr.length() != 8) { 
        return false;
    }
    if (usr[2] != 'I') {
        return false;
    }
    for (int i = 0; i < 2; i++) {
        if (!isdigit(usr[i])) {
            return false;
        }
    }
    for (int i = 4; i < 8; i++) { 
        if (!isdigit(usr[i])) {
            return false;
        }
    }
    return true;
} 
void Student::courseView() {
    system("cls");
    cout << "=============================================" << endl;
    cout << "              FAST Student Portal            " << endl;
    cout << "=============================================" << endl;
    const int NUM_SUBJECTS = 11;
    string line;
    ifstream file("data/studentsubjects.csv");

    if (file.is_open()) {
        if (getline(file, line)) {
            stringstream ss(line);
            string subject;
            int i = 0;

            while (getline(ss, subject, ',')) {
                subjects[i] = subject;
                i++;
            }
        }
        else {
            cout << "Error: file is empty." << endl;
        }

        int row = 1;
        while (getline(file, line)) {
            stringstream ss(line);
            string entry;
            int i = 0;

            while (getline(ss, entry, ',')) {
                sub[i] = stoi(entry);
                i++;
            }
            if (row == stoi(sno)) {

                cout << "You are enrolled in Subjects: " << endl;
                cout << endl;
                for (int i = 0; i < NUM_SUBJECTS; i++) {
                    if (sub[i] == 1) {
                        cout << subjects[i] << endl;
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
    cout << "=============================================" << endl;
    navigate();
}
void Student::studentInfo() {
    system("cls");
    cout << "=============================================" << endl;
    cout << "              FAST Student Portal            " << endl;
    cout << "=============================================" << endl;
    cout << "Name: " << sname << endl;
    cout << "Roll No: " << usr << endl;
    email = usr;
    email += "@nu.edu.pk";
    cout << "Email Id: " << email << endl;
    cout << "=============================================" << endl;

    navigate();
}
void Student::navigate() {
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
            if (login) {
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
void Student::logout() {
    system("cls");
    cout << "=============================================" << endl;
    cout << "               FAST UMS Portal               " << endl;
    cout << "=============================================" << endl;
    cout << "Welcome to the University Management System!" << endl;
    cout << "Logging out from your account, This might take several sconds..." << endl;
    check = false;
    sleep(2);
    mainMenu();
}
void Student::quizMenu() {
    system("cls");
    cout << "=============================================" << endl;
    cout << "              FAST Student Portal            " << endl;
    cout << "=============================================" << endl;

    const int NUM_SUBJECTS = 11;
    string line;
    ifstream file("data/studentsubjects.csv");

    if (file.is_open()) {
        if (getline(file, line)) {
            stringstream ss(line);
            string subject;
            int i = 0;

            while (getline(ss, subject, ',')) {
                subjects[i] = subject;
                i++;
            }
        }
        else {
            cout << "Error: file is empty." << endl;
        }

        int row = 1;
        int count = 1;
        while (getline(file, line)) {
            stringstream ss(line);
            string entry;
            int i = 0;

            while (getline(ss, entry, ',')) {
                sub[i] = stoi(entry);
                i++;
            }
            if (row == stoi(sno)) {
                cout << "Select a subject to take the quiz: " << endl;
                cout << endl;
                for (int i = 0; i < NUM_SUBJECTS; i++) {
                    if (sub[i] == 1) {
                        cout << i + 1 << ". " << subjects[i] << endl;
                    }
                }
                int choice;

                cout << "\n=============================================" << endl;
                cout << "Only Enter the Serial Number next to the Corresponding Course." << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                if (choice >= 1 && choice <= NUM_SUBJECTS) {
                    cout << "\nLoading Quiz for " << subjects[choice - 1] << endl;
                    sleep(2);
                    Quiz q(choice, this);
                    q.attemptQuiz();
                }
                else {
                    cout << "Invalid choice!" << endl;
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
    cout << "=============================================" << endl;
    navigate();
}