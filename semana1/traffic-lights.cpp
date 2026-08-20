// https://cses.fi/problemset/task/1163
#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;

struct Comparator
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
    {
        if(a.second - a.first == b.second - b.first)
            return a.first < b.first;

        return a.second - a.first < b.second - b.first;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x, n;
    cin >> x >> n;
    set<pair<int, int>, Comparator> ranges;
    set<int> lights;

    ranges.insert(pair<int, int>(0, x));

    for (int i = 0; i < n; i++)
    {
        int pos;
        cin >> pos;

        int prev;

        if (lights.lower_bound(pos) != lights.begin())
            prev = *(--lights.lower_bound(pos));
        else
            prev = 0;

        int next;

        if (lights.upper_bound(pos) != lights.end())
            next = *(lights.upper_bound(pos));
        else
            next = x;

        lights.insert(pos); // O(log n)

        ranges.erase(pair<int, int>(prev, next)); // O(log n)

        ranges.insert(pair<int, int>(prev, pos)); // O(log n)
        ranges.insert(pair<int, int>(pos, next)); // O(log n)

        pair<int, int> max_range = *(--ranges.end());

        cout << max_range.second - max_range.first << " ";
    }
}