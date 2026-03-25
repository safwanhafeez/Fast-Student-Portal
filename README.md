# University Management System

A console-based academic management platform designed for educational institutions to facilitate quiz administration, student enrollment tracking, and performance analytics. The system implements role-based access control with distinct interfaces for students and teachers, supporting 11 computer science courses with automated grading and statistical analysis capabilities.

Built with C++ using object-oriented principles, the system manages quiz lifecycle operations including creation, scheduling, attempt tracking, and result generation. The architecture separates concerns through modular components handling authentication, quiz management, time-based access control, and analytics visualization.

## System Architecture

The application follows a modular object-oriented architecture with inheritance-based user role separation. The core workflow operates as follows: users authenticate through role-specific login portals (Student or Teacher), access course-specific functionalities based on their enrollment or teaching assignments, and interact with the quiz subsystem for creation or attempt operations. The analytics module processes result data stored in CSV format to generate statistical insights including score distributions, averages, and visual representations.

Key subsystems include the User authentication layer (base class for role inheritance), Quiz management engine (handles question parsing, answer validation, and result persistence), Time controller (enforces quiz availability windows), and Analytics processor (computes metrics and generates ASCII-based visualizations). Data persistence relies on CSV files organized by course identifiers, with separate directories for quiz content, answer keys, results, and timing configurations.

## Core Features

The system provides comprehensive quiz management capabilities including multi-format question support (multiple choice, true/false, descriptive), automated answer key generation, and time-window enforcement for quiz availability. Teachers can create quizzes by selecting questions from pre-populated question banks, set access schedules, and delete existing assessments. Students can view enrolled courses, attempt available quizzes within designated time windows, and receive immediate scoring feedback.

Analytics functionality includes result aggregation across enrolled students, calculation of highest and lowest scores, average performance metrics, and ASCII-based bar graph visualization. The system prevents duplicate quiz attempts through result file validation and maintains course enrollment mappings for 216 students across 11 subjects including Programming Fundamentals, Object Oriented Programming, Data Structures, Algorithms, Software Engineering, Research Methodology, Big Data Analytics, Artificial Intelligence, Deep Learning, and Digital Image Processing.

## Technology Stack

Language: C++ (C++11 or later)
Standard Library: iostream, fstream, sstream, chrono
Platform Dependencies: Windows API (Windows.h, conio.h, unistd.h)
Data Storage: CSV files for student records, quiz content, answer keys, results, and timing data
Build System: g++ compiler (MinGW or MSVC)

## Project Structure

The codebase is organized into three primary directories with clear separation of concerns:

`include/` contains header files defining class interfaces for User (base authentication class), Student and Teacher (role-specific implementations), Quiz (assessment management), Analytics (statistical processing), and Time (scheduling control).

`utils/` houses implementation files corresponding to each header, containing business logic for authentication workflows, quiz creation and attempt processing, result calculation, and analytics generation.

`data/` stores CSV files for student records (students.csv with enrollment flags), teacher assignments (teachers.csv, teachersubjects.csv), and authentication credentials (studentPasswords.csv).

`export/` maintains runtime-generated content organized by course, including Quiz subdirectories (quiz files and answer keys), Result subdirectories (attempt records with scores), and Time directory (quiz scheduling data).

`import/` contains question banks organized by course for quiz generation.

## Installation and Setup

Clone the repository to your local machine:

```
git clone <repository-url>
cd <repository-directory>
```

Ensure you have a C++ compiler installed. For Windows, MinGW-w64 or Microsoft Visual C++ is required due to platform-specific dependencies (Windows.h, conio.h).

Compile the application using g++:

```
g++ main.cpp -o main.exe -std=c++11
```

Verify that the data directory contains the required CSV files (students.csv, teachers.csv, studentPasswords.csv, teachersubjects.csv, studentsubjects.csv). These files must maintain the expected schema with comma-separated values.

Ensure the export and import directory structures exist with appropriate subdirectories for each course. The system expects folders named with course identifiers (1_PF, 2_OOP, 3_IICT, 4_DS, 5_ALGO, 6_SE, 7_RM, 8_BDA, 9_AI, 10_DL, 11_DIP) under export/Quiz and export/Result.

## Configuration

The system relies on hardcoded file paths within the Quiz class constructor. Course identifiers map to specific directories:

Course 1 (Programming Fundamentals): import/Quiz/1_PF/, export/Quiz/1_PF/, export/Result/1_PF/
Course 2 (Object Oriented Programming): import/Quiz/2_OOP/, export/Quiz/2_OOP/, export/Result/2_OOP/
Courses 3-11 follow the same pattern with identifiers 3_IICT through 11_DIP.

Quiz question banks in the import directories must use specific marker strings for question type identification:
- a5380ee: Topic title
- 2efcde9: Multiple choice questions
- dabfac4: Correct option indicator
- b94d27b: True/False questions
- 88f7ace: Descriptive questions

Student enrollment data in students.csv uses binary flags (0 or 1) in columns 4-14 to indicate course registration. Teacher assignments in teachersubjects.csv map teacher IDs to course numbers.

Timing data is stored in export/Time/timings.csv with format: SubjectName,Hour,Minute. The system compares current system time against these values to enforce quiz availability.

## Usage

Execute the compiled binary:

```
main.exe
```

The main menu presents three options: Student Login, Teacher Login, or Exit.

For student access, select option 1 and provide credentials stored in studentPasswords.csv. Upon successful authentication, students can view enrolled courses, access course-specific information, and attempt available quizzes. Quiz attempts are validated against timing windows and previous attempt records. Scoring is calculated automatically by comparing student responses against answer keys, with results persisted to course-specific CSV files.

For teacher access, select option 2 and authenticate using credentials from teachers.csv. Teachers can view assigned courses, create new quizzes by selecting question types and quantities from question banks, set quiz timing windows, delete existing quizzes, and access the analytics portal. The analytics interface provides options to view individual results, calculate highest/lowest scores, compute averages, generate ASCII bar graphs, and list enrolled students.

Navigation throughout the system uses single-character input captured via getch(). Users can return to home screens with 'H' or exit the application with 'Q'.

## Development Guidelines

The codebase uses inheritance to model user roles, with Student and Teacher classes extending the base User class. When extending functionality, maintain this hierarchy and avoid breaking the authentication flow in defaultRun() methods.

Quiz creation relies on parsing question banks with specific marker strings. Any modifications to question formats must update the markers array and corresponding parsing logic in storeQuestions(). Answer keys are generated simultaneously during quiz creation by extracting content following the dabfac4 marker.

CSV file operations use stringstream for parsing comma-delimited records. Ensure proper file handle management with explicit close() calls to prevent data corruption. Result files append new records without overwriting existing data.

The system uses Windows-specific functions (getch(), system("cls"), Sleep()) which limit portability. Cross-platform implementations would require conditional compilation or abstraction layers for terminal control and input handling.

Time-based quiz access control compares current system time (obtained via chrono) against stored timing data. The timingCheck() method returns false if the current time is before the scheduled quiz window, preventing premature access.

## Deployment

The application is designed for Windows environments and requires no external dependencies beyond the C++ standard library and Windows API. Deploy by distributing the compiled executable alongside the data and export directory structures.

For institutional deployment, populate students.csv with actual enrollment data maintaining the schema: S#, Roll No., Student Name, followed by 11 binary enrollment flags. Update studentPasswords.csv with authentication credentials using the format: username,password.

Populate question banks in import/Quiz subdirectories with properly formatted content using the required marker strings. Each question bank file should contain sufficient questions for quiz generation (minimum 5 MCQs, 5 True/False, and 5 Descriptive questions per course).

Ensure write permissions for the export directory tree, as the system generates quiz files, answer keys, result records, and timing configurations at runtime.

## Known Limitations

The system is tightly coupled to the Windows platform through dependencies on Windows.h, conio.h, and platform-specific functions (getch(), system("cls")). Porting to Linux or macOS requires significant refactoring of input handling and terminal control.

File paths are hardcoded within class constructors, limiting flexibility for deployment in different directory structures. A configuration file approach would improve maintainability.

CSV parsing lacks robust error handling for malformed data. Missing commas, unexpected line breaks, or encoding issues may cause parsing failures or incorrect data interpretation.

The authentication system stores passwords in plaintext within CSV files, presenting a security vulnerability. Production deployments should implement password hashing and secure credential storage.

Quiz timing enforcement relies on system clock comparison without timezone handling or daylight saving time considerations. Multi-timezone deployments may experience scheduling inconsistencies.

The analytics module assumes result files exist and contain valid data. Attempting to generate statistics for courses without quiz attempts may cause file access errors.

ASCII bar graph visualization in the analytics module provides limited visual clarity for large datasets or significant score variations. A graphical interface or export to visualization tools would improve usability.

The system lacks concurrent access control. Multiple users modifying the same quiz or result files simultaneously may cause data corruption or race conditions.

## Future Work

Implement a database backend (SQLite or MySQL) to replace CSV file storage, improving data integrity, query performance, and concurrent access handling. Migrate authentication to a secure credential management system with password hashing (bcrypt or Argon2) and session management.

Develop a cross-platform terminal abstraction layer to eliminate Windows API dependencies, enabling deployment on Linux and macOS. Consider using libraries like ncurses for portable terminal control.

Add a web-based interface using a framework like Crow or Drogon to provide browser-based access, eliminating the need for local executable distribution and improving accessibility.

Extend quiz functionality to support additional question types (fill-in-the-blank, matching, essay with manual grading), question randomization to prevent cheating, and configurable time limits per quiz attempt.

Implement comprehensive logging for audit trails, tracking user actions, quiz attempts, and administrative operations. Add error recovery mechanisms for file I/O failures and data validation.

Enhance analytics with exportable reports (PDF or Excel), trend analysis across multiple quiz attempts, and comparative performance metrics between courses or student cohorts.

Introduce role-based permissions for administrative functions, allowing designated users to manage student enrollment, course assignments, and system configuration without code modifications.

Develop automated testing infrastructure with unit tests for core business logic, integration tests for file operations, and end-to-end tests for user workflows to ensure system reliability during future enhancements.
