// https://cses.fi/problemset/task/1090

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, x;

    cin >> n >> x;

    vector<int> children;

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        children.push_back(a);
    }

    sort(children.begin(), children.end());

    int gondolas = 0;
    int j = 0;

    for(int i = children.size() - 1; i >= 0 && i >= j; i--)
    {
        if (children[i] + children[j] <= x)
            j++;
        
        gondolas++;
    }

    cout << gondolas << "\n";
}