#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    stack<string> history;

    history.push("google.com");
    history.push("youtube.com");
    history.push("abcsc.com");
    history.push("facebook.com");

    cout << "Browser history created.\n";

    for (int i = 0; i < 2; i++)
    {
        if (!history.empty())
        {
            cout << "Back pressed. Leaving: "
                 << history.top() << endl;
            history.pop();
        }
    }

    if (!history.empty())
    {
        cout << "Current top of history: "
             << history.top() << endl;
    }

    return 0;
}
