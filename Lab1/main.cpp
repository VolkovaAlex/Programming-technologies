#include <iostream>
#include <locale>
#include "Keeper.h"
#include "Fish.h"
#include "Bird.h"
#include "Cat.h"
#include "Exceptions.h"

using namespace std;

static void showMenu() {
    cout << "1. Add a fish\n";
    cout << "2. Add a bird\n";
    cout << "3. Add a cat\n";
    cout << "4. Print all\n";
    cout << "5. Delete an object\n";
    cout << "6. Save to file\n";
    cout << "7. Load from file\n";
    cout << "8. Show menu\n";
    cout << "0. Exit\n";
}

int main() {
    Keeper keeper;
    int choice;
    showMenu();

    while (true) {
        cout << "\nSelect an action: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice, please try again.\n";
            continue;
        }
        cin.ignore();

        if (choice == 1) {
            string breed, color, diet;

            cout << "Enter fish breed: ";
            getline(cin, breed);
            cout << "Enter fish color: ";
            getline(cin, color);
            cout << "Enter fish diet: ";
            getline(cin, diet);

            keeper.addObj(new Fish(breed, color, diet));
            cout << "Fish added successfully.\n";
        }
        else if (choice == 2) {
            string breed, color, diet, habitat;

            cout << "Enter bird breed: ";
            getline(cin, breed);
            cout << "Enter bird color: ";
            getline(cin, color);
            cout << "Enter bird diet: ";
            getline(cin, diet);
            cout << "Enter bird habitat: ";
            getline(cin, habitat);

            keeper.addObj(new Bird(breed, color, diet, habitat));
            cout << "Bird added successfully.\n";
        }
        else if (choice == 3) {
            string breed, color, owner_name, pet_name;

            cout << "Enter cat breed: ";
            getline(cin, breed);
            cout << "Enter cat color: ";
            getline(cin, color);
            cout << "Enter cat owner's name: ";
            getline(cin, owner_name);
            cout << "Enter cat pet name: ";
            getline(cin, pet_name);

            keeper.addObj(new Cat(breed, color, owner_name, pet_name));
            cout << "Cat added successfully.\n";
        }
        else if (choice == 4) {
            keeper.printAll();
        }
        else if (choice == 5) {
            int index;
            cout << "Enter the index of the object you want to delete: ";
            cin >> index;
            try {
                keeper.removeObject(index);
                cout << "Object successfully deleted.\n";
            }
            catch (const IndexOutOfRangeException& ex) {
                cout << ex.what() << endl;
            }
            cin.ignore();
        }
        else if (choice == 6) {
            keeper.saveToFile("data_1.txt");
            cout << "Objects saved to file successfully.\n";
        }
        else if (choice == 7) {
            keeper.loadFromFile("data_1.txt");
            cout << "Objects loaded successfully.\n";
        }
        else if (choice == 8) {
            showMenu();
        }
        else if (choice == 0) {
            break;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}