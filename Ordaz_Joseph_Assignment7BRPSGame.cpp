// Ordaz, Joseph
// CIS-5 35132
// 07/13/25
// This program allows user to play Rock, Paper, Scissors game 

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype> // for toupper()

using namespace std;

// Function Prototypes
int getComputerChoice();
int getUserChoice();
bool isValidChoice(string input);
string convertChoice(int choice);
int determineWinner(int user, int computer);
void displayResult(int winner, int user, int computer);
bool playAgain();

int main() 
{
    srand(time(0));         // Set random seed

    int userWins = 0;
    int computerWins = 0;
    int ties = 0;
    bool keepPlaying = true;

    while (keepPlaying) 
    {
        int computer = getComputerChoice();
        int user = getUserChoice();

        int winner = determineWinner(user, computer);
        displayResult(winner, user, computer);

        if (winner == 0) 
        {
            ties++;
        }
        else if (winner == 1) 
        {
            userWins++;
        }
        else 
        {
            computerWins++;
        }

        keepPlaying = playAgain();
    }

    // Game stats
    cout << "\nThanks for playing!" << endl;
    cout << "Your wins: " << userWins << endl;
    cout << "Computer wins: " << computerWins << endl;
    cout << "Ties: " << ties << endl;

    return 0;
}

// Random number 1–3 for computer's choice
int getComputerChoice() 
{
    return rand() % 3 + 1;
}

// Ask user for choice and convert to 1, 2, or 3
int getUserChoice() 
{
    string input;
    while (true) 
    {
        cout << "\nEnter rock, paper, or scissors: ";
        cin >> input;

        // Convert input to lowercase
        for (int i = 0; i < input.length(); i++) 
        {
            input[i] = tolower(input[i]);
        }

        if (isValidChoice(input)) 
        {
            if (input == "rock") 
                return 1;
            if (input == "paper") 
                return 2;
            if (input == "scissors") 
                return 3;
        }
        else 
        {
            cout << "Invalid input. Try again." << endl;
        }
    }
}

// Checks if the string is rock, paper, or scissors
bool isValidChoice(string input) 
{
    return input == "rock" || input == "paper" || input == "scissors";
}

// Turns number into a word
string convertChoice(int choice) 
{
    if (choice == 1) 
        return "Rock";
    else if (choice == 2) 
        return "Paper";
    else 
        return "Scissors";
}

// 0 = tie, 1 = user wins, 2 = computer wins
int determineWinner(int user, int computer) 
{
    if (user == computer) 
        return 0;

    if ((user == 1 && computer == 3) ||
        (user == 2 && computer == 1) ||
        (user == 3 && computer == 2)) 
    {
        return 1;
    }
    else 
    {
        return 2;
    }
}

// Display what happened
void displayResult(int winner, int user, int computer) 
{
    string userWord = convertChoice(user);
    string computerWord = convertChoice(computer);

    cout << "You chose: " << userWord << endl;
    cout << "Computer chose: " << computerWord << endl;

    if (winner == 0) 
    {
        cout << "You both chose " << userWord << ". It's a tie!" << endl;
    }
    else if (winner == 1) 
    {
        cout << userWord << " beats " << computerWord << ". You win!" << endl;
    }
    else 
    {
        cout << computerWord << " beats " << userWord << ". You lose!" << endl;
    }
}

// Ask if the user wants to play again
bool playAgain() 
{
    char choice;
    cout << "\nDo you want to play again? (Y/N): ";
    cin >> choice;
    return toupper(choice) == 'Y';
}
