#include <iostream>
#include <vector>
#include <string.h>
#include <random>

// CSV files
#include <fstream>

using namespace std;

/*
Options:
- We check for random assortments of boxes, which one is the best. (Not optimal because it does not consider risk)
:-: We check the possibility of every number being the highest there is for every position. (Pretty optimal because then you can choose how to risk it)
*/

struct iterationResult
{
    int maxValue = 0;
    int maxId = 0;
};


iterationResult iterate(int boxN, int maxPrice) 
{
    vector<int> boxes;

    for (int i = 0; i < boxN; i++)
    {
        boxes.push_back(rand() % maxPrice);
    }
    int max = 0;
    int maxId = 0;
    for (int i = 0; i < boxN; i++)
    {
        if (boxes[i] > max)
        {
            max = boxes[i];
            maxId = i;
        }
        
    }

    iterationResult res;
    res.maxId = maxId;
    res.maxValue = max;
    return res;
}

int main(void) 
{
    // Start rand
    rand

    // Open file
    string filename = "";
    filename += "boxes_";
    filename += to_string(rand() % 10000);
    filename += ".csv";
    ofstream file;
    file.open(filename);
    if (!file.is_open()) {
        cout << "ERROR 1: Error while opening file." << endl;
        return 1;
    }

    // We have 27 boxes
    int boxes = 27;

    // For create columns
    file << "MaxVal, MaxPos \n";

    // We have a range of prices (0$ - 1000000$) which we will represent as a range from 0 to 100.
    int maxPrice = 100;
    int iterations = 1000;

    // To display percentages
    int percentageStep = iterations / 100;

    for (int i = 0; i < iterations; i++)
    {
        iterationResult res = iterate(boxes, maxPrice);
        file << res.maxValue << "," << res.maxId << endl;

        // Display percentages
        if (iterations % percentageStep == 0) cout << i / percentageStep << "%" << endl;
    }
    cout << "100\% DONE!" << endl;
    file.close();
    cout << "Saved to " << filename << endl;
    
    return 0;
}