#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

vector<int> iterate(vector<int> board) {
    vector<int> out = board;
    // padd
    out.push_back(-1); 
    out.push_back(-1);
    out.insert(out.begin(), -1);
    out.insert(out.begin(), -1);

    
    for (int i = 2; i < board.size() + 2; i++)
    {
        if (board[i] == 1 && (board[i - 1] == 0 || board[i + 1] == 0)) out[i] = 2; 
        else if (board[i] == 2 && board[i+1] == 2 && board[i-1] == 0) {out[i] = 3; out[i+1] = 3; out[i-1] = 1; i++;}
        else if (board[i] == 2 && board[i+1] == 2 && board[i+2] == 0) {out[i] = 3; out[i+1] = 3; out[i+2] = 1; i++;}
        else if (board[i] == 3 && (board[i+1] == 0 || board[i+2] == 0 || board[i-1] == 0 || board[i-2] == 0)) out[i] = 2;
        else if (board[i] == 3 && !(board[i+1] == 0 || board[i+2] == 0 || board[i-1] == 0 || board[i-2] == 0)) out[i] = 0;
    }

    // unpadd
    out.pop_back(); out.pop_back();
    out.erase(out.begin());
    out.erase(out.begin());

    return out;
}

int main(void) {
    int length, iterations;
    cin >> length >> iterations;
    vector<int> board;
    for (int i = 0; i < length; i++) {
        int tmp;
        cin >> tmp;
        board.push_back(tmp);
    }
    for (int i = 0; i < iterations; i++)
    {
        board = iterate(board);
        for (int j = 0; j < board.size(); j++)
        {
            cout << board[j] << " ";
        }
        cout << endl;
    }
}