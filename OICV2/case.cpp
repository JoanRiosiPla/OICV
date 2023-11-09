#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

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
class volume
{
    public:
        int maxVolume = 0, volume = 0, value = 0;
        vector<med> meds;
        bool addToCase(med m) 
        {
            this->volume += m.volume;
            this->value += m.value;
            this->meds.push_back(m);
            return true;
        }
};

int medSorter(med l, med r) {
    return l.relativeValue > r.relativeValue;
}

int main(void) {
    int medN = 0;
    volume bag;

    cin >> medN >> bag.maxVolume;

    vector<med> meds;
    
    for (int i = 0; i < medN; i++)
    {
        med tmp;
        cin >> tmp.volume >> tmp.value >> tmp.min;
        tmp.calcRelativeValue();
        meds.push_back(tmp);
    }
    for (int i = 0; i < medN; i++)
    {
        for (int j = 0; j < meds[i].min; j++)
        {
            bag.addToCase(meds[i]);
            cout << to_string(bag.volume) << endl;
        }
    }

    cout << endl << endl;

    // Order meds by relativeValue
    sort(meds.begin(), meds.end(), &medSorter);

    for (int i = 0; i < meds.size(); i++)
    {
        while (bag.volume < bag.maxVolume - meds[i].volume)
        {
            bag.addToCase(meds[i]);
        }
    }

    cout << endl << bag.value << endl;
    


    return 0;
}