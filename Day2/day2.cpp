#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>

using namespace std;

int main() {
    int total = 0;
    int totalPower = 0;
    string fileName = "Strings.txt";
    ifstream inputStream(fileName);

    string line;
    unordered_map<int, bool> accept;
    for (int i = 1; i < 101; i++) {
        accept[i] = true;
    }
    unordered_map<int, int> acceptPower;
    for (int i = 1; i < 101; i++) {
        acceptPower[i] = 0;
    }
    int gameNum = 0;
    string tempNum = "";
    int offset = 0;
    int redMax = 0;
    int blueMax = 0;
    int greenMax = 0;
    while(getline(inputStream, line)) {
        gameNum++;
        for (int i = 0; i < line.length(); i++) {
            if (i + offset < line.length() && (line[i + offset] == '0' || line[i + offset] == '1' || line[i + offset] == '2' || line[i + offset] == '3' ||
                line[i + offset] == '4' || line[i + offset] == '5' || line[i + offset] == '6' || line[i + offset] == '7' ||
                line[i + offset] == '8' || line[i + offset] == '9')) {
                    tempNum += line[i + offset];
                    offset++;
            }
            if (i + offset < line.length() && (line[i + offset] == '0' || line[i + offset] == '1' || line[i + offset] == '2' || line[i + offset] == '3' ||
                line[i + offset] == '4' || line[i + offset] == '5' || line[i + offset] == '6' || line[i + offset] == '7' ||
                line[i + offset] == '8' || line[i + offset] == '9')) {
                    tempNum += line[i + offset];
                    offset++;
            }
            if (i + offset + 1 < line.length() && line[i + offset] == ' ' && line[i + offset + 1] == 'r') {
                if (tempNum.length() > 1) {
                    if (stoi(tempNum) > 12) {
                        accept[gameNum] = false;
                    }
                    if (stoi(tempNum) > redMax) {
                        redMax = stoi(tempNum);
                    }
                }
                else {
                    if (redMax < tempNum[0] - '0') {
                        redMax = tempNum[0] - '0';
                    }
                }
            }
            else if (i + offset + 1 < line.length() && line[i + offset] == ' ' && line[i + offset + 1] == 'g') {
                if (tempNum.length() > 1) {
                    if (stoi(tempNum) > 13) {
                        accept[gameNum] = false;
                    }
                    if (stoi(tempNum) > greenMax) {
                        greenMax = stoi(tempNum);
                    }
                }
                else {
                    if (greenMax < tempNum[0] - '0') {
                        greenMax = tempNum[0] - '0';
                    }
                }
            }
            else if (i + offset + 1 < line.length() && line[i + offset] == ' ' && line[i + offset + 1] == 'b') {
                if (tempNum.length() > 1) {
                    if (stoi(tempNum) > 14) {
                        accept[gameNum] = false;
                    }
                    if (stoi(tempNum) > blueMax) {
                        blueMax = stoi(tempNum);
                    }
                }
                else {
                    if (blueMax < tempNum[0] - '0') {
                        blueMax = tempNum[0] - '0';
                    }
                }
            }
            offset = 0;
            tempNum = "";
        }
        acceptPower[gameNum] = redMax * blueMax * greenMax;
        redMax = 0;
        blueMax = 0;
        greenMax = 0;
    }
    for (int i = 1; i < 101; i++) {
        if (accept[i] == true) {
            total += i;
        }
        totalPower += acceptPower[i];
    }
    //cout << total;
    cout << totalPower;
}