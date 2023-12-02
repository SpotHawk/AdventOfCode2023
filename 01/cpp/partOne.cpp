#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void readInput(vector<string>* input);
int calculate(vector<string>* input);

int main() {
    vector<string> input;

    readInput(&input);
    cout << calculate(&input) << endl;

    return 0;
}

void readInput(vector<string>* input) {
    ifstream file("../input.txt");
    string line;

    while(getline(file, line)) {
        input->push_back(line);
    }
    
    input->shrink_to_fit();
}

int calculate(vector<string>* input) {
    int firstDigit, lastDigit;
    int sum = 0;

    int i = 0;
    int j;
    while(i < (int)input->size()) {
        firstDigit = -1;
        lastDigit = -1;
        
        j = 0;
        while (j < (int)(*input)[i].length() && firstDigit == -1) {
            if (isdigit((*input)[i][j])) {
                    firstDigit = static_cast<int>((*input)[i][j] - '0');
            }
            j++;
        }
        j = (int)(*input)[i].length();
        while (j >= 0 && lastDigit == -1) {
            if (isdigit((*input)[i][j])) {
                    lastDigit = static_cast<int>((*input)[i][j] - '0');
            }
            j--;
        }

        sum += (firstDigit * 10 + lastDigit);
        i++;
    }

    return sum;
}
