// Carrera de lletres 
// Per Joan Rios i Pla

#include <iostream>
using namespace std;
#include <string.h>

// Change to modify number of games possible (default 10).
const int maxGames = 10;
const int maxPlayers = 4;

bool runGame(int playerNumber, int boardSize, int deckSize, string board, string *deck);


int main(void)
{
    // For each game, there is one of each variable (using arrays)
    // decks is bidimensional, for each game, there are 200 slots.
    int n[maxGames], c[maxGames], b[maxGames]; 
    string boards[maxGames]; 
    string decks[maxGames][200];

    // Input
    int nGames = 0;
    while (true)
    {
        // Input
        cin >> n[nGames] >> c[nGames] >> b[nGames];
        if (n[nGames] == 0) break;
        cin >> boards[nGames];
        for (int i = 0; i < b[nGames]; i++)
        {
            cin >> decks[nGames][i];
        }

        // Prepare for next while
        nGames++;
        if (nGames >= maxGames) break;
    }

    // Run games
    for (int i = 0; i < nGames; i++)
    {
        if (false == runGame(n[i], c[i], b[i], boards[i], decks[i])) return 1;
    }
}

bool runGame(int playerNumber, int boardSize, int deckSize, string board, string deck[]) 
{
    int winner = -1;
    int cards = 0;

    // Not really necessary, but I like it :)
    struct player
    {
        int position = 0;
        int cards = 0;
    };
    
    player players[maxPlayers];

    // For each card
    for (int i = 0; i < deckSize; i++)
    {   
        bool stop = false;

        // 1rst letter in a card
        // players[i % playerNumber]  (current player)
        // deck[i] current card
        while (board.at(players[i % playerNumber].position) != deck[i].at(0))
        {
            players[i % playerNumber].position++;

            // cout << "-debug1 player " << i % playerNumber << " pos " << players[i % playerNumber].position << " card " << i << endl;

            // If the player won
            if (players[i % playerNumber].position >= boardSize) 
            {
                winner = i % playerNumber; 
                stop = true;
                break;
            }
        }
        
        // 2nd letter in a card
        if (deck[i].length() == 2 && stop == false)
        {
            // Check at the end because we are surely on a card with our 
            do
            {
                players[i % playerNumber].position++;

                // cout << "-debug2 player " << i % playerNumber << " pos " << players[i % playerNumber].position << " card " << i << " letter 2" << endl;

                // If the player won
                if (players[i % playerNumber].position >= boardSize) 
                {
                    winner = i % playerNumber;
                    stop = true;
                    break;
                }

            } while (board.at(players[i % playerNumber].position) != deck[i].at(1));
        }
        // Increment global cards and player-specific cards
        players[i % playerNumber].cards = i + 1;
        cards = i + 1;
        if (stop == true) break;
    }

    // Print winner
    if (playerNumber == 1)
    {
        cout << cards << " " << players[0].position;
        return true;
    }
    
    if (winner >= 0)
    {
        cout << "El jugador " << winner + 1 << " gana con " << cards << " cartas." << endl;
        return true;
    }
    else
    {
        cout << "Nadie gana con " << cards << " cartas." << endl;
        return true;
    }
    
    return false;
}