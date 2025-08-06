// Ordaz, Joseph
// CIS-5 35132
// 07/30/25
// This program lets students practice math problems and records their scores.
// URL: https://youtu.be/j7xxIFE8E60

#include <iostream>  
#include <iomanip>   
#include <string>    
#include <cstdlib>   
#include <ctime>     
#include <cctype>    
using namespace std;

// Holds all the information 
struct MathStudentInfo
{
    string fullName;        // Students name
    int gradeLevel;         // Grade level (1st to 6th)
    int scoreAdd;           // Correct addition problems
    int scoreSub;           // Correct subtraction problems
    int scoreMul;           // Correct multiplication problems
    int scoreDiv;           // Correct division problems
};

// Function declarations
void showMainMenu();                                           // Menu options
int getChoice();                                               // Menu input 
void inputPlayers(MathStudentInfo players[], int& count);      // Add student info
void playGame(MathStudentInfo players[], int count);           // Student play
void showResults(MathStudentInfo players[], int count);        // All results
void doAddition(MathStudentInfo& p);                           // 1 addition problem
void doSubtraction(MathStudentInfo& p);                        // 1 subtraction problem
void doMultiplication(MathStudentInfo& p);                     // 1 multiplication problem
void doDivision(MathStudentInfo& p);                           // 1 division problem

int main()
{
    srand(time(0));             // Seed random number generator 

    MathStudentInfo players[3]; // Hold up to 3 students
    int studentCount = 0;       // Keep track of added students
    int choice;                 // Store users menu choice

    // Loop for the menu 
    do
    {
        showMainMenu();       // Display options
        choice = getChoice(); // Ask user for input

        if (choice == 1)
            inputPlayers(players, studentCount); // Add student info
        else if (choice == 2)
            playGame(players, studentCount);     // Start math game
        else if (choice == 3)
            showResults(players, studentCount);  // Display scores
        else if (choice == 4)
            cout << "Thank you for using Math Tutor!" << endl;
        else
            cout << "Please enter a number from 1 to 4.\n"; // Invalid choice

    } while (choice != 4);

    system("pause"); 
    return 0;
}

// Displays the main menu
void showMainMenu()
{
    cout << "\n----- MATH TUTOR MENU -----\n";
    cout << "1. Input student(s) info\n";
    cout << "2. Play Math Game\n";
    cout << "3. Show Results\n";
    cout << "4. Exit Program\n\n";
}

// Gets users menu choice
int getChoice()
{
    int choice;
    cout << "Enter your choice (1-4): ";
    cin >> choice;
    return choice;
}

// Add 1 to 3 students
void inputPlayers(MathStudentInfo players[], int& count)
{
    if (count >= 3)
    {
        cout << "You already entered the maximum of 3 players.\n";
        return;
    }

    cout << "How many students would you like to add (1-3)? ";
    int num;
    cin >> num;

    while (num < 1 || num > 3 || (count + num > 3))
    {
        cout << "Please enter a number between 1 and " << (3 - count) << ": ";
        cin >> num;
    }

    cin.ignore(); 

    for (int i = 0; i < num; i++)
    {
        cout << "\nEnter full name for student #" << (count + 1) << ": ";
        getline(cin, players[count].fullName);

        cout << "Enter grade level (1-6): ";
        cin >> players[count].gradeLevel;

        // All math scores to 0
        players[count].scoreAdd = 0;
        players[count].scoreSub = 0;
        players[count].scoreMul = 0;
        players[count].scoreDiv = 0;

        count++;       // Move up next student 
        cin.ignore(); 
    }
}

// Student pick an operation 
void playGame(MathStudentInfo players[], int count)
{
    if (count == 0)
    {
        cout << "No students available. Please enter student info first.\n";
        return;
    }

    // Show list of students
    cout << "\nWhich student is playing?\n";
    for (int i = 0; i < count; i++)
    {
        cout << (i + 1) << ". " << players[i].fullName << " (Grade " << players[i].gradeLevel << ")\n";
    }

    int choice;
    cout << "Enter number of student (1-" << count << "): ";
    cin >> choice;

    // Input validation
    while (choice < 1 || choice > count)
    {
        cout << "Invalid selection. Choose between 1 and " << count << ": ";
        cin >> choice;
    }

    MathStudentInfo& current = players[choice - 1]; 

    // Choose what kind of problem to solve
    int operation;
    cout << "\nWhat do you want to practice?\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "Choose (1-4): ";
    cin >> operation;

    if (operation == 1)
        doAddition(current);
    else if (operation == 2)
        doSubtraction(current);
    else if (operation == 3)
        doMultiplication(current);
    else if (operation == 4)
        doDivision(current);
    else
        cout << "Invalid choice.\n";
}

// Everyones results
void showResults(MathStudentInfo players[], int count)
{
    cout << "\n====================== STUDENT RESULTS ====================\n";
    cout << left << setw(20) << "Name"
        << setw(10) << "Grade"
        << setw(8) << "Add"
        << setw(8) << "Sub"
        << setw(8) << "Mul"
        << setw(8) << "Div" << endl;
    cout << "-----------------------------------------------------------\n";

    for (int i = 0; i < count; i++)
    {
        cout << left << setw(20) << players[i].fullName
            << setw(10) << players[i].gradeLevel
            << setw(8) << players[i].scoreAdd
            << setw(8) << players[i].scoreSub
            << setw(8) << players[i].scoreMul
            << setw(8) << players[i].scoreDiv << endl;
    }

    cout << "===========================================================\n";
}

// All the functions realated to math
void doAddition(MathStudentInfo& p)
{
    int a = rand() % 100 + 1;
    int b = rand() % 100 + 1;
    int correct = a + b;
    int answer, tries = 0;

    cout << "\n   " << setw(3) << a << endl;
    cout << "+  " << setw(3) << b << endl;
    cout << "______" << endl;
    cout << "  ";
    cin >> answer;

    while (answer != correct && ++tries < 3)
    {
        cout << "Nope, try again, you got this: ";
        cin >> answer;
    }

    if (answer == correct)
    {
        cout << "Good job, that is correct!\n";
        p.scoreAdd++;
    }
    else
    {
        cout << "Sorry, the answer was " << correct << ", but do not give up.\n";
    }
}

void doSubtraction(MathStudentInfo& p)
{
    int a = rand() % 100 + 1;
    int b = rand() % a + 1; //  positive result
    int correct = a - b;
    int answer, tries = 0;

    cout << "\n   " << setw(3) << a << endl;
    cout << "-  " << setw(3) << b << endl;
    cout << "______" << endl;
    cout << "  ";
    cin >> answer;

    while (answer != correct && ++tries < 3)
    {
        cout << "Nope, try again, you got this: ";
        cin >> answer;
    }

    if (answer == correct)
    {
        cout << "Good job, that is correct!\n";
        p.scoreSub++;
    }
    else
    {
        cout << "Sorry, the answer was " << correct << ", but do not give up.\n";
    }
}

void doMultiplication(MathStudentInfo& p)
{
    int a = rand() % 12 + 1;
    int b = rand() % 12 + 1;
    int correct = a * b;
    int answer, tries = 0;

    cout << "\n   " << setw(3) << a << endl;
    cout << "x  " << setw(3) << b << endl;
    cout << "______" << endl;
    cout << "  ";
    cin >> answer;

    while (answer != correct && ++tries < 3)
    {
        cout << "Nope, try again, you got this: ";
        cin >> answer;
    }

    if (answer == correct)
    {
        cout << "Good job, that is correct!\n";
        p.scoreMul++;
    }
    else
    {
        cout << "Sorry, the answer was " << correct << ", but do not give up.\n";
    }
}

void doDivision(MathStudentInfo& p)
{
    int a, b, correct;
    int answer, tries = 0;

    do
    {
        b = rand() % 12 + 1;
        correct = rand() % 12 + 1;
        a = b * correct;
    } while (b == 0);

    cout << "\n   " << setw(3) << a << endl;
    cout << "/  " << setw(3) << b << endl;
    cout << "______" << endl;
    cout << "  ";
    cin >> answer;

    while (answer != correct && ++tries < 3)
    {
        cout << "Nope, try again, you got this: ";
        cin >> answer;
    }

    if (answer == correct)
    {
        cout << "Good job, that is correct!\n";
        p.scoreDiv++;
    }
    else
    {
        cout << "Sorry, the answer was " << correct << ", but do not give up.\n";
    }
}
