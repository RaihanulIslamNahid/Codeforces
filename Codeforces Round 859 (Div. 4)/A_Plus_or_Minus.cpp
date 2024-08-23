#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t; // Number of test cases

    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c; // Read the three integers

        if (a + b == c)
        {
            cout << "+" << endl; // Output "+" if a + b = c
        }
        else
        {
            cout << "-" << endl; // Output "-" if a - b = c
        }
    }

    return 0;
}
