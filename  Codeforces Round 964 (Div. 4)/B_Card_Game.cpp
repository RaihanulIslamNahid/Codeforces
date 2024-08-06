#include <iostream>
using namespace std;

int countSuneetWins(int a1, int a2, int b1, int b2)
{
    int wins = 0;

    int suneetCards[2] = {a1, a2};
    int slavicCards[2] = {b1, b2};

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            for (int k = 0; k < 2; ++k)
            {
                for (int l = 0; l < 2; ++l)
                {
                    if (i != k && j != l)
                    {
                        int suneetWins = 0, slavicWins = 0;

                        // First round
                        if (suneetCards[i] > slavicCards[j])
                            suneetWins++;
                        else if (suneetCards[i] < slavicCards[j])
                            slavicWins++;

                        // Second round
                        if (suneetCards[k] > slavicCards[l])
                            suneetWins++;
                        else if (suneetCards[k] < slavicCards[l])
                            slavicWins++;

                        // Check if Suneet wins the game
                        if (suneetWins > slavicWins)
                            wins++;
                    }
                }
            }
        }
    }

    return wins;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;

        cout << countSuneetWins(a1, a2, b1, b2) << endl;
    }

    return 0;
}
