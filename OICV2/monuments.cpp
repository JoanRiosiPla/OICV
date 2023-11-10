#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int romantoint(string roman) {
    int out = 0;
    for (int i = roman.size() - 1; i >= 0; i--)
    {
        if (roman[i] == 'I') out += 1;
        else if (roman[i] == 'V') out += 5;
        else if (roman[i] == 'X') out += 10;
        else if (roman[i] == 'L') out += 50;
        else if (roman[i] == 'C') out += 100;
        else if (roman[i] == 'D') out += 500;
        else if (roman[i] == 'M') out += 1000;
    }
    return out;
}

void one() {

}

void two() {

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
    else if (version == 1) cout << romantoint(romans[0]);
    else if (version == 2) two();


    cout << endl;
    return 0;
}