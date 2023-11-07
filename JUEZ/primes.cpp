#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

bool checkPrime(int n) {
    for (int i = 2; i < n-1; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main(void) {
    int c;
    vector<int> n, k;

    cin >> c;

    for (int i = 0; i < c; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        n.push_back(tmp1);
        k.push_back(tmp2);
    }

    for (int p = 0; p < c; p++)
    {
        if (k.at(p) == 0)
        {
            if (checkPrime(n.at(p))) cout << "SI";
            else cout << "NO";
            cout << endl;
            continue;
        }

        int primes = 0;
        int i = 1;

        while (primes < k.at(p))
        {
            if(checkPrime(n.at(p) + i)) {
                primes++;
                cout << (n.at(p) + i) << " ";
            }
            i++;
        }        
        cout << endl;
    }
    return 0;
}