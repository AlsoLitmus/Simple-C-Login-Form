#include <iostream>
#include <fstream>
#include <string>
#include "fns.h"
#include <vector>

using namespace std;

int main()
{
	int choice;
	std::vector<string> registeredUsers;
	bool onLoginMenu = true;
	bool userAlreadyExists = true;
	int numUsers = 0;

	while (onLoginMenu) {

		displayMenu();
		choice = getInput();

		if (choice == 1) {
			string username, password;
			cout << "Select a username: ";
			cin >> username;

			while (userAlreadyExists) {
				int counter = 0;
				if (numUsers == 0) {
					userAlreadyExists = false;
					break;
				}
				for (string user : registeredUsers) {
					counter++;
					if (user == username) {
						cout << "Username already taken. Please choose a different username." << endl;
						cout << "Select a username: ";
						cin >> username;

					}
					else if (counter == numUsers) {
				
						userAlreadyExists = false;
					}
				}
			}

			userAlreadyExists = true;

			cout << "Select a password: ";
			cin >> password;

			registeredUsers.push_back(username);
			numUsers++;

			ofstream file;
			file.open(username + ".txt");
			file << username << endl << password;
			file.close();
		}
		else if (choice == 2) {
			bool status = LoggingIn();
			while (!status) {
				cout << "Incorrect Information, Try Again!" << endl;
				system("PAUSE");
				status = LoggingIn();
			}
			if (status) {
				cout << "Login Successful!" << endl;
				system("PAUSE");
				return 1;

			}
		}
	}
}

