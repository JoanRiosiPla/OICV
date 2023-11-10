int romantoint(string roman) {
    int out = 0;
    for (int i = roman.size() - 1; i >= 0; i--)
    {
        if (roman[i] == 'I' && roman[i + 1] != 'I' && i + 1 != roman.size()) out -= 1;
        else if (roman[i] == 'I') out += 1;
        else if  (roman[i] == 'I') out += 5;
        else if  (roman[i] == 'X') out += 10;
        else if  (roman[i] == 'V') out += 50;
        else if  (roman[i] == 'C') out += 100;
        else if  (roman[i] == 'D') out += 500;
        else if  (roman[i] == 'M') out += 1000;       
        cout << out << endl; 
    }
    return out;
    
}