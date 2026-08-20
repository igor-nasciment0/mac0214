#pragma GCC optimize("O3")

// https://cses.fi/problemset/task/1164

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    struct ComparePQ
    {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b)
        {
            return a.second > b.second;
        }
    };

    auto guests = vector<tuple<int, int, int>>();
    auto room_queue = priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePQ>();

    auto org = vector<int>(n);

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        guests.push_back(tuple<int, int, int>(i, a, b));
    }

    sort(guests.begin(), guests.end(), [](const tuple<int, int, int> &a, const tuple<int, int, int> &b)
         { return (get<1>(a) <= get<1>(b)) || (get<1>(a) == get<1>(b) && get<2>(a) <= get<2>(b)); });

    int rooms_number = 0;

    for (auto guest : guests)
    {
        int guest_index = get<0>(guest);
        int arrival = get<1>(guest);
        int departure = get<2>(guest);

        int chosen_room;

        if (room_queue.empty() || room_queue.top().second >= arrival)
        {
            chosen_room = ++rooms_number;
        }
        else
        {
            chosen_room = room_queue.top().first;
            room_queue.pop();
        }
        
        room_queue.push(pair<int,int>(chosen_room, departure));
        org[guest_index] = chosen_room;
    }

    std::cout << rooms_number << "\n";

    for (int i = 0; i < org.size(); i++)
        cout << org[i] << " ";
}