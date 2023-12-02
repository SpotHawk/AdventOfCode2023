#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void readInput(vector<string>* inputs);
int calculate(vector<string>* inputs);

int main() {
    vector<string> inputs;

    readInput(&inputs);
    cout << calculate(&inputs) << endl;

    return 0;
}

void readInput(vector<string>* inputs) {
    ifstream file("../input.txt");
    string line;

    while(getline(file, line)) {
        inputs->push_back(line);
    }
    
    inputs->shrink_to_fit();
}

int calculate(vector<string>* inputs) {
    int firstDigit, lastDigit;
    int sum = 0;

    int i = 0;
    int j;
    while(i < (int)inputs->size()) {
        firstDigit = -1;
        lastDigit = -1;
        
        j = 0;
        while (j < (int)(*inputs)[i].length()) {
            if (isdigit((*inputs)[i][j])) {
                if (firstDigit == -1) {
                    firstDigit = static_cast<int>((*inputs)[i][j] - '0');
                    lastDigit = static_cast<int>((*inputs)[i][j] - '0');
                } else {
                    lastDigit = static_cast<int>((*inputs)[i][j] - '0');
                }
            }
            j++;
        }

        sum += (firstDigit * 10 + lastDigit);
        i++;
    }

    return sum;
}

