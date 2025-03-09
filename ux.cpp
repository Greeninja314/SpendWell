#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Transaction {
public:
    string description;
    double amount;
    string type;

    Transaction(string desc, double amt, string t) {
        description = desc;
        amount = amt;
        type = t;
    }
};

class BudgetApp {
private:
    vector<Transaction> transactions;

public:
    void addTransaction() {
        string description, type;
        double amount;

        cout << "Enter description: ";
        getline(cin, description);
        cout << "Enter amount: ";
        cin >> amount;
        cin.ignore(); // to clear the input buffer
        cout << "Enter type (Expense/Income): ";
        getline(cin, type);

        transactions.push_back(Transaction(description, amount, type));
        cout << "Transaction added successfully!" << endl;
    }

    void showTransactions() {
        if (transactions.empty()) {
            cout << "No transactions available." << endl;
            return;
        }

        cout << "\nTransactions:\n";
        for (const auto& t : transactions) {
            cout << "Description: " << t.description
                 << ", Amount: " << t.amount
                 << ", Type: " << t.type << endl;
        }
    }

    void showMenu() {
        int choice;

        do {
            cout << "\n--- Budget App ---\n";
            cout << "1. Add Transaction\n";
            cout << "2. View Transactions\n";
            cout << "3. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore(); // to clear input buffer

            switch (choice) {
                case 1:
                    addTransaction();
                    break;
                case 2:
                    showTransactions();
                    break;
                case 3:
                    cout << "Exiting application...\n";
                    break;
                default:
                    cout << "Invalid choice! Please try again.\n";
            }
        } while (choice != 3);
    }
};

int main() {
    BudgetApp app;
    app.showMenu();
    return 0;
}

