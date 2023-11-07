#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int main(void) {
    int n,k = 0;
    vector<string> names;
    cin >> n >> k;

    if (k != 0)
    {
        for (int i = 0; i < n; i++)
        {
            string name;
            cin >> name;
            names.push_back(name);
        }       
    }
    

    

    for (int i = 0; i < n; i++)
    {
        if(k == 0) cout << "Hola OICV";
        else cout << "Hola " << names[i];
        cout << endl;
    }
    
    
    return 0;
}