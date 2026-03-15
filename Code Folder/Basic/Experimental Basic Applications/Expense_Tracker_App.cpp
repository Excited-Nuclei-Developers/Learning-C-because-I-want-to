#include <iostream>
#include <string>
using namespace std;

const int MAX_EXPENSES = 100;

// Parallel arrays
string categories[MAX_EXPENSES];
string descriptions[MAX_EXPENSES];
double amounts[MAX_EXPENSES];
int expenseCount = 0;

// Function to pad string for table alignment
string padString(const string s, int width){
    if(s.length() >= width)
        return s.substr(0, width);
    return s + string(width - s.length(), ' ');
}

// Function to add expenses
void addExpense(){
    if (expenseCount >= MAX_EXPENSES){
        cout << "Expense Limit Reached!\n";
        return;
    }
    cout << "Enter category: ";
    getline(cin, categories[expenseCount]);

    cout << "Enter description: ";
    getline(cin, descriptions[expenseCount]);

    cout << "Enter amount: ";
    cin >> amounts[expenseCount];
    cin.ignore();

    expenseCount++;
    cout << "Expense added successfully!" << endl;
}

// Function to view expenses
void viewExpenses(){
   if (expenseCount >= MAX_EXPENSES){
        cout << "Expense Limit Reached!\n";
        return;
    }
    cout << "\n----------Expense List----------\n" ;
    cout << padString("Index", 10)
         << padString("Category",15)
         << padString("Description",25)
         << "Amount\n";

    for (int i=0; i<expenseCount; i++){
        cout << padString(to_string(i), 10)
         << padString(categories[i],15)
         << padString(descriptions[i],25)
         << amounts[i] << endl;
    }
}

// Function to delete expenses
void deleteExpense(){
    if(expenseCount == 0){
        cout << "No expenses to delete.\n";
        return;
    }
    int index;
    cout << "Enter the index of expense you want to delete: ";
    cin >> index;

    if(index < 0 || index >= expenseCount){
        cout << "Invalid index!\n";
        return;}

    for(int i = index; i < expenseCount - 1; i++){
        categories[i] = categories[i+1];
        descriptions[i] = descriptions[i+1];
        amounts[i] = amounts[i+1];
    }

    expenseCount--;

    cout << "Expense deleted successuly!" << endl;
}

// Function to show expense summary
void showSummary(){
    double total = 0;

    for (int i=0; i<expenseCount; i++){
        total += amounts[i];
    }

    cout << "\nTotal Expenses: " << total << endl;
    cout << "\nCategory-wise Summary:\n";
    for(int i = 0; i < expenseCount; i++){
        double categoryTotal = 0;
        bool counted = false;

        for(int j = 0; j < i; j++){
            if(categories[i] == categories[j]){
                counted = true;
                break;
            }
        }

        if(!counted){
            for(int j = 0; j < expenseCount; j++){
                if(categories[i] == categories[j]){
                    categoryTotal += amounts[j];
                }
            }

            cout << categories[i] << ": " << categoryTotal << endl;
        }
    }
}

// main
int main() {
    int choice;
    do {
        cout << "\n=== Expense Tracker ===\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Delete Expense\n";
        cout << "4. Show Total\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1: addExpense(); break;
            case 2: viewExpenses(); break;
            case 3: deleteExpense(); break;
            case 4: showSummary(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}