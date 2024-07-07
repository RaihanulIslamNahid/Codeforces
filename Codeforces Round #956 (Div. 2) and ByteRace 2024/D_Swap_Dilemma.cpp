#include <bits/stdc++.h>
using namespace std;

int mergeAndCount(vector<int> &arr, vector<int> &temp, int left, int mid, int right)
{
    int i = left;
    int j = mid;
    int k = left;
    int inv_count = 0;

    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count += (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

int mergeSortAndCount(vector<int> &arr, vector<int> &temp, int left, int right)
{
    int mid;
    int inv_count = 0;
    if (right > left)
    {
        mid = (right + left) / 2;

        inv_count += mergeSortAndCount(arr, temp, left, mid);
        inv_count += mergeSortAndCount(arr, temp, mid + 1, right);

        inv_count += mergeAndCount(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

bool canMakeSame(vector<int> &a, vector<int> &b, int n)
{
    vector<int> sorted_a = a;
    vector<int> sorted_b = b;
    sort(sorted_a.begin(), sorted_a.end());
    sort(sorted_b.begin(), sorted_b.end());

    if (sorted_a != sorted_b)
    {
        return false;
    }

    vector<int> temp(n);
    int inv_a = mergeSortAndCount(a, temp, 0, n - 1);
    int inv_b = mergeSortAndCount(b, temp, 0, n - 1);

    return (inv_a % 2 == inv_b % 2);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> b[i];
        }
        if (canMakeSame(a, b, n))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}