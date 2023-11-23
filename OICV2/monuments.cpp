#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int romantoint(string roman) {
    int out = 0;
    int largest = 0;
    for (int i = roman.size() - 1; i >= 0; i--)
    {
        int val = 0;
        if (roman[i] == 'I') val = 1;
        else if (roman[i] == 'V') val = 5;
        else if (roman[i] == 'X') val = 10;
        else if (roman[i] == 'L') val = 50;
        else if (roman[i] == 'C') val = 100;
        else if (roman[i] == 'D') val = 500;
        else if (roman[i] == 'M') val = 1000;
        if (val < largest) out -= val;
        else out += val;
        largest = largest > val ? largest : val;
    }
    return out;
}

int one(vector<string> romans) {
    int smallest = 1000000000;
    for (int i = 0; i < romans.size(); i++)
    {
        smallest = romantoint(romans[i]) < smallest ? romantoint(romans[i]) : smallest;
    }
    return smallest;
}

bool sorter(string n, string p) {
    return romantoint(n) < romantoint(p);
}

string two(vector<string> romans) {
    sort(romans.begin(), romans.end(), &sorter);
    return romans[0] + " " + romans[1];
}

int main(void) {
    int version = 0;
    cin >> version;

    vector<string> romans;

    do {
        string tmp;
        cin >> tmp;
        romans.push_back(tmp);
    } while (romans[romans.size() - 1] != "RIP");
    romans.erase(romans.end());

    if(version == 0) cout << romans.size();
    else if (version == 1) cout << one(romans);
    else if (version == 2) cout << two(romans);


    cout << endl;
    return 0;
}