#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> parking;
    int choice, carNo;

    do
    {
        cout << "\n--- PARKING GARAGE MENU ---\n";
        cout << "1. Park a car\n";
        cout << "2. Remove a car\n";
        cout << "3. Display parked cars\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter car number: ";
                cin >> carNo;
                parking.push(carNo);
                cout << "Car " << carNo
                     << " parked successfully.\n";
                break;

            case 2:
                if (parking.empty())
                {
                    cout << "Parking garage is empty!\n";
                }
                else
                {
                    cout << "Car " << parking.top()
                         << " leaves the garage.\n";
                    parking.pop();
                }
                break;

            case 3:
                if (parking.empty())
                {
                    cout << "No cars parked.\n";
                }
                else
                {
                    stack<int> temp = parking;

                    cout << "Cars in the garage "
                         << "(leaving order):\n";

                    while (!temp.empty())
                    {
                        cout << temp.top() << " ";
                        temp.pop();
                    }

                    cout << endl;
                }
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
