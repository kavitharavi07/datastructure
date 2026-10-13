#include <iostream>
using namespace std;

struct Coach
{
    int coachNo;
    Coach* next;
};

Coach* head = NULL;

void addBeginning(int no)
{
    Coach* newCoach = new Coach;
    newCoach->coachNo = no;
    newCoach->next = head;
    head = newCoach;

    cout << "Coach added at the beginning.\n";
}

void addEnd(int no)
{
    Coach* newCoach = new Coach;
    newCoach->coachNo = no;
    newCoach->next = NULL;

    if (head == NULL)
    {
        head = newCoach;
    }
    else
    {
        Coach* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newCoach;
    }

    cout << "Coach added at the end.\n";
}

void removeCoach(int no)
{
    if (head == NULL)
    {
        cout << "Train is empty.\n";
        return;
    }

    Coach* temp = head;
    Coach* prev = NULL;

    while (temp != NULL && temp->coachNo != no)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Coach not found.\n";
        return;
    }

    if (prev == NULL)
    {
        head = head->next;
    }
    else
    {
        prev->next = temp->next;
    }

    delete temp;
    cout << "Coach removed successfully.\n";
}

// 4. Display all coaches
void display()
{
    if (head == NULL)
    {
        cout << "Train has no coaches.\n";
        return;
    }

    Coach* temp = head;

    cout << "Train: ";

    while (temp != NULL)
    {
        cout << "Coach " << temp->coachNo << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main()
{
    int choice, no;

    do
    {
        cout << "\n--- TRAIN COACH MANAGEMENT ---\n";
        cout << "1. Add coach at beginning\n";
        cout << "2. Add coach at end\n";
        cout << "3. Remove a coach\n";
        cout << "4. Display all coaches\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter coach number: ";
                cin >> no;
                addBeginning(no);
                break;

            case 2:
                cout << "Enter coach number: ";
                cin >> no;
                addEnd(no);
                break;

            case 3:
                cout << "Enter coach number to remove: ";
                cin >> no;
                removeCoach(no);
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    while (head != NULL)
    {
        Coach* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
