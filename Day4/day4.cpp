#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
#include <math.h>

using namespace std;
unordered_map<int, int> matchCount;
unordered_map<int, int> cardCountMap;
long long int totalCards = 0;

int main()
{
    for (int i = 0; i < 198; i++) {
        matchCount[i] = 0;
        cardCountMap[i] = 1;
    }
    double total = 0;
    int matches = 0;
    string line;
    vector<string> strings;
    int winningNums[10];
    int winningCount = 0;
    string winningTemp = "";
    int test;

    ifstream textFile("Strings.txt");
    while(getline(textFile, line, '\n')) {
        strings.push_back(line);
    }
    for (int i = 0; i < strings.size(); i++) {
        for (int j = 10; j < 40; j++) {
            if (!isdigit(strings[i][j])) {
                if (winningTemp.length() == 1) {
                    winningNums[winningCount] = winningTemp[0] - '0';
                    if (j + 1 < 40 && !isdigit(strings[i][j + 1])) {
                        j++;
                    }
                    winningTemp = "";
                    winningCount++;
                }
                else if (winningTemp.length() == 2) {
                    winningNums[winningCount] = stoi(winningTemp);
                    if (j + 1 < 40 && !isdigit(strings[i][j + 1])) {
                        j++;
                    }
                    winningTemp = "";
                    winningCount++;
                }
            }
            else {
                winningTemp += strings[i][j];
            }
        }
        for (int j = 40; j < strings[i].length() + 1; j++) {
            if (!isdigit(strings[i][j])) {
                if (winningTemp.length() == 1) {
                    test = winningTemp[0] - '0';
                    if (j + 1 < strings[i].length() && !isdigit(strings[i][j + 1])) {
                        j++;
                    }
                    for (int k = 0; k < 11; k++) {
                        if (test == winningNums[k]) {
                            matches++;
                            break;
                        }
                    }
                }
                else if (winningTemp.length() == 2) {
                    test = stoi(winningTemp);
                    if (j + 1 < strings[i].length() && !isdigit(strings[i][j + 1])) {
                        j++;
                    }
                    for (int k = 0; k < 11; k++) {
                        if (test == winningNums[k]) {
                            matches++;
                            break;
                        }
                    }
                }
                winningTemp = "";
            }
            else {
                winningTemp += strings[i][j];
            }
        }
        winningCount = 0;
        if (matches > 0) {
            total += pow(2, (matches - 1));
            for (int m = cardCountMap[i]; m > 0; m--) {
                for (int j = matches; j > 0; j--) {
                    cardCountMap[i + j]++;
                }
            } 
        }
        matches = 0;
    }
    for (int i = 0; i < strings.size(); i++) {
        totalCards += cardCountMap[i];
    }
    cout << total << endl;
    cout << totalCards << endl;
}