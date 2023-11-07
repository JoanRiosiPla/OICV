#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

char chars[] = {' ', 'X', 'O'};

int main(void) {
    int n;
    cout << "Tamaño del tablero (n x n): ";
    cin >> n;
    cout << endl << n;

    vector<int> board[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << '|' << chars[board[i][j]] << '|';
        }
        
    }
    

    cout << endl;
    return 0;
}

