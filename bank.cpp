#include <iostream>
using namespace std;

const int SIZE = 10;
int hashTable[SIZE];

void initialize()
{
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}


void insert(int x)
{
    int index = x % SIZE;

    for (int i = 0; i < SIZE; i++)
    {
        int pos = (index + i) % SIZE;

        if (hashTable[pos] == x)
        {
            cout << "Account already exists!\n";
            return;
        }

        if (hashTable[pos] == -1)
        {
            hashTable[pos] = x;
            cout << "Account inserted successfully.\n";
            return;
        }
    }

    cout << "Hash table is full!\n";
}

void search(int x)
{
    int index = x % SIZE;

    for (int i = 0; i < SIZE; i++)
    {
        int pos = (index + i) % SIZE;

        if (hashTable[pos] == -1)
        {
            cout << "Account not found.\n";
            return;
        }

        if (hashTable[pos] == x)
        {
            cout << "Account found at index "
                 << pos << ".\n";
            return;
        }
    }

    cout << "Account not found.\n";
}

void display()
{
    cout << "\nHash Table:\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Index " << i << " : ";

        if (hashTable[i] == -1)
            cout << "Empty";
        else
            cout << hashTable[i];

        cout << endl;
    }
}

int main()
{
    initialize();

    int choice, x;

    do
    {
        cout << "\n--- BANK HASH TABLE ---\n";
        cout << "1. INSERT\n";
        cout << "2. SEARCH\n";
        cout << "3. DISPLAY\n";
        cout << "4. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter account number: ";
                cin >> x;
                insert(x);
                break;

            case 2:
                cout << "Enter account number to search: ";
                cin >> x;
                search(x);
                break;

            case 3:
                display();
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
