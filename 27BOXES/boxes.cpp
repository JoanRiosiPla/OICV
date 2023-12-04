#include <iostream>
#include <vector>
#include <string.h>
#include <random>
#include <time.h>
#include <algorithm>

// TODO: gnuplot

// CSV files
#include <fstream>

using namespace std;

/*
Options:
- We check for random assortments of boxes, which one is the best. (Not optimal because it does not consider risk)
:-: We check the possibility of every number being the highest there is for every position. (Pretty optimal because then you can choose how to risk it)
*/

bool cmdOptionExists(char** begin, char** end, const std::string& option)
{
    return std::find(begin, end, option) != end;
}

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

bool sortByMaxValue(iterationResult a,iterationResult b){
    return a.maxValue > b.maxValue;
}

int main(int argc, char * argv[]) 
{
    // Options
    bool saveFile = cmdOptionExists(argv, argv+argc, "-h");

    // Start rand TODO
    srand(time(NULL));

    // Open file
    
    string filename = "";
    filename += "boxes_";
    filename += to_string(rand() % 10000);
    filename += ".csv";
    ofstream rw_file;
    rw_file.open("raw_" + filename);
    if (!rw_file.is_open()) {
        cout << "ERROR 1: Error while opening file." << endl;
        return 1;
    }

    // We have 27 boxes
    int boxes = 27;

    // For create columns
    rw_file << "MaxVal, MaxPos \n";

    // We have a range of prices (0$ - 1000000$) which we will represent as a range from 0 to 100.
    int maxPrice = 1000;
    int iterations = 1000000;

    if (!cmdOptionExists(argv, argv+argc, "-n")) {
        cout << "Insert desired max price (int): ";
        cin >> maxPrice;
        cout << "Insert desired iterations (int): ";
        cin >> iterations;
    }

    // To display percentages
    int percentageStep = iterations / 100;

    // To calculate largest numbers and averages
    vector<iterationResult> results;

    cout << "Generating raw data:" << endl;

    for (int i = 0; i < iterations; i++)
    {
        iterationResult res = iterate(boxes, maxPrice);
        rw_file << res.maxValue << "," << res.maxId << endl;
        results.push_back(res);

        // Display percentages
        if ((int)(i / percentageStep) != (int)((i-1) / percentageStep)) {cout << "\r" << i / percentageStep << "%" << std::flush;}
    }
    cout << "\r100\% DONE!" << endl;
    cout << "Saved raw to raw_" << filename << endl;

    cout << "Generating rel_" << filename << endl;
    ofstream rel_file;
    rel_file.open("rel_" + filename);
    if (!rel_file.is_open()) 
    {
        rw_file.close();
        cout << "ERROR 2: Error while opening file." << endl;
        return 2;
    }

    rel_file << "Average, Max, Min" << endl;

    // Calculate average
    cout << "Calculating Average..." << endl;
    long long int sum = 0;
    for (int i = 0; i < results.size(); i++) sum += results[i].maxValue;
    float average = (float)sum / (float)results.size();
    rel_file << average << ",";
    cout << "DONE!" << endl;

    // Max
    cout << "Sorting..." << endl;
    sort(results.begin(), results.end(), &sortByMaxValue); // OJO! results está sorted
    cout << "DONE!" << endl;
    rel_file << results.at(0).maxValue << "," << results.at(results.size() - 1).maxValue << endl;

    // Chances of winning at every price
    cout << "Calculating chances..." << endl;
    ofstream prob_file;
    prob_file.open("prob_" + filename);
    for (int i = 0; i < maxPrice; i++)
    {
        int j = 1;
        while (results[j].maxValue > i && j < results.size())
        {
            j++;
        }
        prob_file << i + 1 << "," << ((float)j/(float)results.size()) * 100.0 << endl;
    }
    cout << "Saved to prob_" << filename << endl;
    cout << "DONE!" << endl;
    

    prob_file.close();
    rw_file.close();
    rel_file.close();
    return 0;
}