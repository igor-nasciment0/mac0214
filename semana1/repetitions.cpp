// https://cses.fi/problemset/task/1069

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string input;
    cin >> input;


    if(input.length() == 0)
    {
        cout << 0;
        return 0;
    }

    int max = 1;
    int current = 1;

    for (int i = 1, size = input.length(); i < size; i++) 
    {
        if (input[i] == input[i - 1])
        {
            current += 1;

            if (current > max)
                max = current;
        }
        else
            current = 1;
    }

    cout << max;
    return 0;
}