#include<iostream>
#include<string>
#include<vector>
using namespace std;

class user_info {
private:
    string username, user_password;
public:
    user_info(string name, string pass) {
        username = name;
        user_password = pass;
    }

    // Getter methods to access private members
    string getUsername() {
        return username;
    }

    string getPassword() {
        return user_password;
    }
};

class user_management {
private:
    vector<user_info> users;  // Vector to store users
public:
    // Method to register a new user
    void registerUser() {
        string username, user_password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> user_password;

        user_info newuser(username, user_password);
        users.push_back(newuser);  // Add new user to the vector

        cout << "User registered successfully!" << endl;
    }

    // Method to log in an existing user
    bool loginUser(string name, string pass) {
        for (int i = 0; i < users.size(); i++) {
            if (users[i].getUsername() == name && users[i].getPassword() == pass) {
                cout << "Login successful!" << endl;
                return true;
            }
        }
        cout << "Invalid username or password!" << endl;
        return false;
    }
};

int main() {
    user_management userm;
    int option;
    char choice;

    do {
        // Main menu
        cout << "\n1. Register user" << endl;
        cout << "2. Login user" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
                userm.registerUser();
                break;
            case 2: {
                string username, password;
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                userm.loginUser(username, password);
                break;
            }
            case 3:
                cout << "Exiting program." << endl;
                exit(0);  // Exit the program
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        // Ask if the user wants to continue
        cout << "Do you want to continue? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');  // Continue if the user enters 'Y' or 'y'

    return 0;
}

