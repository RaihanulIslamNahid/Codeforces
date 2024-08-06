#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

long long power(long long x, long long y, long long p)
{
    long long res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

long long modInverse(long long n, long long p)
{
    return power(n, p - 2, p);
}

void precomputeFactorials(vector<long long> &fact, vector<long long> &invFact, int maxN, long long p)
{
    fact[0] = 1;
    for (int i = 1; i <= maxN; i++)
        fact[i] = fact[i - 1] * i % p;
    invFact[maxN] = modInverse(fact[maxN], p);
    for (int i = maxN - 1; i >= 0; i--)
        invFact[i] = invFact[i + 1] * (i + 1) % p;
}

long long binomialCoeff(int n, int r, const vector<long long> &fact, const vector<long long> &invFact, long long p)
{
    if (r > n || r < 0)
        return 0;
    return fact[n] * invFact[r] % p * invFact[n - r] % p;
}

int main()
{
    int t;
    cin >> t;

    int maxN = 200000;
    vector<long long> fact(maxN + 1), invFact(maxN + 1);
    precomputeFactorials(fact, invFact, maxN, MOD);

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        int threshold = (k + 1) / 2;
        int countOnes = 0;

        for (int i = 0; i < n; ++i)
        {
            if (a[i] == 1)
            {
                countOnes++;
            }
        }

        long long sumOfMedians = 0;
        for (int i = threshold; i <= countOnes; ++i)
        {
            sumOfMedians = (sumOfMedians + binomialCoeff(countOnes, i, fact, invFact, MOD) * binomialCoeff(n - countOnes, k - i, fact, invFact, MOD)) % MOD;
        }

        cout << sumOfMedians << endl;
    }

    return 0;
}
