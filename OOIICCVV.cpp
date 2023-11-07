#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n;
    vector<int> o, ii, c, v;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int tmp1, tmp2, tmp3, tmp4;
        cin >> tmp1 >> tmp2 >> tmp3 >> tmp4;
        o.push_back(tmp1);
        ii.push_back(tmp2);
        c.push_back(tmp3);
        v.push_back(tmp4);
    }

    for (int q = 0; q < n; q++)
    {
        for (int i = 0; i < o.at(q); i++)
        {
            cout << "O";
        }

        for (int i = 0; i < ii.at(q); i++)
        {
            cout << "I";
        }

        for (int i = 0; i < c.at(q); i++)
        {
            cout << "C";
        }

        for (int i = 0; i < v.at(q); i++)
        {
            cout << "V";
        }
        cout << endl;
    }

    return 0;
}