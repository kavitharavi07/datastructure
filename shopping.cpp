#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> shoppingList;
    int choice;
    string item;

    do
    {
        cout << "\n===== SHOPPING LIST MENU =====\n";
        cout << "1. Store items in shopping list\n";
        cout << "2. Add an item\n";
        cout << "3. Remove an item\n";
        cout << "4. Search for an item\n";
        cout << "5. Display all items\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                shoppingList.clear();
                int n;
                cout << "Enter the number of items: ";
                cin >> n;

                for (int i = 0; i < n; i++)
                {
                    cout << "Enter item " << i + 1 << ": ";
                    cin >> item;
                    shoppingList.push_back(item);
                }
                cout << "Items stored successfully!\n";
                break;

            case 2:
                cout << "Enter the item to add: ";
                cin >> item;
                shoppingList.push_back(item);
                cout << "Item added successfully!\n";
                break;

            case 3:
                cout << "Enter the item to remove: ";
                cin >> item;

                {
                    auto it = find(shoppingList.begin(),
                                   shoppingList.end(), item);

                    if (it != shoppingList.end())
                    {
                        shoppingList.erase(it);
                        cout << "Item removed successfully!\n";
                    }
                    else
                    {
                        cout << "Item not found!\n";
                    }
                }
                break;

            case 4:
                cout << "Enter the item to search: ";
                cin >> item;

                if (find(shoppingList.begin(),
                         shoppingList.end(), item)
                    != shoppingList.end())
                {
                    cout << "Item found in the shopping list.\n";
                }
                else
                {
                    cout << "Item not found!\n";
                }
                break;

            case 5:
                if (shoppingList.empty())
                {
                    cout << "Shopping list is empty.\n";
                }
                else
                {
                    cout << "\nShopping List:\n";
                    for (int i = 0; i < shoppingList.size(); i++)
                    {
                        cout << i + 1 << ". "
                             << shoppingList[i] << "\n";
                    }
                }
                break;

            case 6:
                cout << "Exiting the program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
