#include <bits/stdc++.h> // Everything

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

#include <random>
#include <time.h>

using namespace std;

bool sorter(int n, int p) {
    return n < p;
}

class med
{
    public:
        int volume = 0, value = 0, min = 0;
        float relativeValue = 0;
        float calcRelativeValue() {
            this->relativeValue = (float)this->value / (float)this->volume;
            return this->relativeValue;
        }
};

struct player
{
    int position = 0;
    int cards = 0;
};

int main(void) {
    vector<int> n, k;
    vector<int> q(10, 0); // Length, Value
    vector<int> board[10][10];

    n.push_back(13);
    n.insert(n.begin(), -12);
    sort(n.begin(), n.end(), &sorter);

    n.pop_back();
    n.erase(n.begin());

    int c;
    cout << "Input a number: ";
    cin >> c;
    cout << "Hi, the number is" << c << endl;

    string str = "Hi";
    str.size();

    srand(time(NULL)); // Start rand
    rand() % 10000;
    return 0;
}


