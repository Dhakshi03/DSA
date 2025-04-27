// Merging two ascending ordered lists into a third list and displaying them

#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    List l1, l2, l3;
    int choice, num;
    int exit = 0;

    while(exit != 1)
    {
        cout << "\nMenu:";
        cout << "\n1. Insert in List 1";
        cout << "\n2. Insert in List 2";
        cout << "\n3. Merge Lists";
        cout << "\n4. Display List 1";
        cout << "\n5. Display List 2";
        cout << "\n6. Display Merged List";
        cout << "\n7. Exit";
        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "\nEnter number to insert in List 1: ";
                cin >> num;
                l1.insert_ascending(num);
                break;

            case 2:
                cout << "\nEnter number to insert in List 2: ";
                cin >> num;
                l2.insert_ascending(num);
                break;

            case 3:
                l3 = l3.merge(l1, l2);
                cout << "\nLists merged successfully.\n";
                break;

            case 4:
                cout << "\nList 1: ";
                l1.display();
                break;

            case 5:
                cout << "\nList 2: ";
                l2.display();
                break;

            case 6:
                cout << "\nMerged List: ";
                l3.display();
                break;

            case 7:
                exit = 1;
                cout << "\nExiting program...\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    }
    return 0;
}
