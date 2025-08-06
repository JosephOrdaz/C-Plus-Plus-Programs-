// Ordaz, Joseph
// CIS-5 35132
// 07/19/25
// This program allows the user to manage their grocery list.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void addItem(vector<string>& list);
void displayList(const vector<string>& list);
void removeItem(vector<string>& list);
void clearList(vector<string>& list);

const int MAX_ITEMS = 10; // Max of 10 items allowed

int main()
{
    vector<string> groceryList;
    int choice;

    do
    {
        // Menu display
        cout << "\n==== Grocery List Menu ====\n";
        cout << "1. Add an item\n";
        cout << "2. Display the list\n";
        cout << "3. Remove an item\n";
        cout << "4. Clear the list\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Valid choices not choosen in the menu
        while (choice < 1 || choice > 5)
        {
            cout << "Invalid choice. Please enter a number between 1 and 5: ";
            cin >> choice;
        }

        // Choices given 
        switch (choice)
        {
        case 1:
            addItem(groceryList);
            break;
        case 2:
            displayList(groceryList);
            break;
        case 3:
            removeItem(groceryList);
            break;
        case 4:
            clearList(groceryList);
            break;
        case 5:
            cout << "Exiting program. Goodbye!\n";
            break;
        }

    } while (choice != 5);

    return 0;
}

// New item to the list
void addItem(vector<string>& list)
{
    if (list.size() >= MAX_ITEMS)
    {
        cout << "Error: Grocery list already has 10 items. Cannot add more.\n";
        return;
    }

    string item;
    cout << "Enter the item to add: ";
    cin.ignore(); 
    getline(cin, item);

    if (item.empty())
    {
        cout << "Item cannot be empty.\n";
        return;
    }

    list.push_back(item);
    cout << "Item added successfully!\n";
}

// All items in the list
void displayList(const vector<string>& list)
{
    if (list.empty())
    {
        cout << "Your grocery list is empty.\n";
    }
    else
    {
        cout << "\n==== Your Grocery List ====\n";
        for (int i = 0; i < list.size(); i++)
        {
            cout << i + 1 << ". " << list[i] << endl;
        }
    }
}

// Removes an item 
void removeItem(vector<string>& list)
{
    if (list.empty())
    {
        cout << "The list is empty. Nothing to remove.\n";
        return;
    }

    string item;
    cout << "Enter the name of the item to remove: ";
    cin.ignore(); 
    getline(cin, item);

    bool found = false;

    for (int i = 0; i < list.size(); i++)
    {
        if (list[i] == item)
        {
            // Shift to the left to avoid duplicate item or space
            for (int j = i; j < list.size() - 1; j++)
            {
                list[j] = list[j + 1];
            }
            list.pop_back(); // Remove last item 
            found = true;
            cout << "Item removed successfully!\n";
            break;
        }
    }

    if (!found)
    {
        cout << "Item not found in the list.\n";
    }
}

// Clears the entire list
void clearList(vector<string>& list)
{
    list.clear();
    cout << "Grocery list cleared.\n\n";
}
