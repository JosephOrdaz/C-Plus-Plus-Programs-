// Ordaz, Joseph
// CIS-5 35132
// 6/28/25
// This program calculates the gross and box office profits for a movie night.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() 
{

    // Named constants and do not change
    const double ADULT_TICKET_PRICE = 18.00;       // Cost per adult
    const double CHILD_TICKET_PRICE = 10.00;       // Cost per child
    const double BOX_OFFICE_PERCENT = 0.18;        // 18% Tax

    // Variables
    string movieName;
    int adultTicketsSold, childTicketsSold;

    // Input of what user sees
    cout << "Enter the movie name: ";
    getline(cin, movieName);

    cout << "Enter the number of adult tickets sold: ";
    cin >> adultTicketsSold;

    cout << "Enter the number of child tickets sold: ";
    cin >> childTicketsSold;

    cout << endl;

    // Calculations
    double grossProfit = (adultTicketsSold * ADULT_TICKET_PRICE) +
        (childTicketsSold * CHILD_TICKET_PRICE);

    double netProfit = grossProfit * BOX_OFFICE_PERCENT;

    double distributorAmount = grossProfit - netProfit;

    // Output
    cout << fixed << setprecision(2);                                  // 2 decimal places 

    cout << left << setw(30) << "Movie Name:" << movieName << endl;   // Rough guess for how much space to cover

    cout << left << setw(30) << "Adult Tickets Sold:" << right << setw(10) 
        << adultTicketsSold << endl;

    cout << left << setw(30) << "Child Tickets Sold:" << right << setw(10) 
        << childTicketsSold << endl;

    cout << left << setw(30) << "Gross Box Office Profit:" << "$" << right << setw(10) 
        << grossProfit << endl;

    cout << left << setw(30) << "Net Box Office Profit:" << "$" << right << setw(10) 
        << netProfit << endl;

    cout << left << setw(30) << "Amount Paid to Distributor:" << "$" << right << setw(10) 
        << distributorAmount << endl;

    system("pause");
    return 0;
}
