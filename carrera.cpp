#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

string partida(int n, int cardN, int boardL, string board, vector<string> deck) {
    vector<int> positions(n, -1);
    int winer = -1;
    int winerPos = -1;
    int cardsTaken = 0;
    for (int i = 0; i < cardN; i++)
    {
        int player = i % n;
        string card = deck[i];
        cardsTaken = i;
        int steps = card.length();
        while (steps > 0 && positions[player] < boardL - 2)
        {
            positions[player]++;
            if (card[0] == board[positions[player]]) steps--;
        }
        if (steps > 0) 
        {
            winer = player;
            winerPos = positions[player];
            break;
        }
    }
    if (n > 1) {
        string ST_winer = "";
        if (winer == -1) ST_winer = "Nadie";
        else ST_winer = "El jugador " + to_string((winer + 1));
        return ST_winer + " gana con " + to_string(cardsTaken + 1) + " cartas.";
    }
    else
    {
        return to_string(cardsTaken + 1) + " " + to_string(winerPos + 2);
    }
}

int main(void) {
    vector<int> n, casillasN, barajaL;
    vector<string> board;
    vector<vector<string>> deck;

    while (true)
    {
        int tmp_n, tmp_c, tmp_b;
        string tmp_board;
        cin >> tmp_n >> tmp_c >> tmp_b;
        if (tmp_n == 0) break;
        cin >> tmp_board;
        n.push_back(tmp_n);
        barajaL.push_back(tmp_b);
        casillasN.push_back(tmp_c);
        board.push_back(tmp_board);

        vector<string> d;

        for (int i = 0; i < tmp_b; i++)
        {
            string card;
            cin >> card;
            d.push_back(card);
        }

        deck.push_back(d);
        
    }
    

    for (int i = 0; i < n.size(); i++)
    {
        cout << partida(n[i], barajaL[i], casillasN[i], board[i], deck[i]) << endl;
    }
    

    return 0;
}