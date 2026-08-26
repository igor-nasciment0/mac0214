// https://cses.fi/problemset/task/1660/

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, x;
    cin >> n >> x;

    vector<int> array;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        array.push_back(a);
    }

    int i = 0, j = 0, sum = 0, count_arrays = 0;

    while (true)
    {
        while (j <= n && sum < x)
            sum += array[j++];

        while (i < j && sum > x)
            sum -= array[i++];

        if (sum == x) {
            count_arrays++;
            sum += array[j++];
        }
        
        if(j > n)
            break;
    }

    cout << count_arrays << "\n";
}