#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to check if username already exists
bool userExists(const string &username) {
    ifstream infile("users.txt");
    string u, p;
    while (infile >> u >> p) {
        if (u == username) {
            return true;
        }
    }
    return false;
}

// Function for Registration
void registerUser() {
    string username, password;

    cout << "\n--- User Registration ---\n";
    cout << "Enter username: ";
    cin >> username;

    if (userExists(username)) {
        cout << "Error: Username already exists!\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    ofstream outfile("users.txt", ios::app);
    outfile << username << " " << password << endl;
    outfile.close();

    cout << "Registration successful!\n";
}

// Function for Login
void loginUser() {
    string username, password;

    cout << "\n--- User Login ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream infile("users.txt");
    string u, p;
    while (infile >> u >> p) {
        if (u == username && p == password) {
            cout << "Login successful! Welcome, " << username << "!\n";
            return;
        }
    }
    cout << "Error: Invalid username or password!\n";
}

// Main Menu
int main() {
    int choice;

    while (true) {
        cout << "\n--- Login & Registration System ---\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registerUser(); break;
            case 2: loginUser(); break;
            case 3: cout << "Exiting program...\n"; return 0;
            default: cout << "Invalid choice! Try again.\n";
        }
    }
}
