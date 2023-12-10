#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>

using namespace std;

int main() {
    string fileName = "Strings.txt";
    ifstream inputStream(fileName);
    vector<string> strings;

    string line1;
    string num = "";
    int total = 0;
    int totalGear = 0;
    int partCount = 0;
    int startIndex;
    bool counted = false;
    bool countedGear = false;

    while(getline(inputStream, line1)) {
        strings.push_back(line1);
    }
    for (int i = 0; i < strings.size(); i++) {
        if (i == 0) { // start - line 0
            for (int j = 0; j < strings[i].length(); j++) { //iterate through line
                if (num == "") {
                    if (!isdigit(strings[i][j])) {
                        continue;
                    }
                    else {
                        startIndex = j;
                        num += strings[i][j];
                    }
                }
                else if (isdigit(strings[i][j])) {
                    num += strings[i][j];
                }
                else {
                    if (startIndex != 0) { // left and diagonal down left
                        if (!isdigit(strings[i][startIndex - 1]) && strings[i][startIndex - 1] != '.') {
                            if (num.length() > 1) {
                                if (!counted) {
                                    total += stoi(num);
                                    counted = true;
                                }   
                            }
                            else {
                                if (!counted) {
                                    total += (num[0] - '0');
                                    counted = true;
                                }
                            }
                        }
                        else if (!isdigit(strings[i + 1][startIndex - 1]) && strings[i + 1][startIndex - 1] != '.') {
                            if (num.length() > 1) {
                                if (!counted) {
                                    total += stoi(num);
                                    counted = true;
                                }   
                            }
                            else {
                                if (!counted) {
                                    total += (num[0] - '0');
                                    counted = true;
                                }
                            }
                        }
                    }
                    if (startIndex + num.length() != strings[i].length() + 1) { //right and diagonal down right
                        if (!isdigit(strings[i][startIndex + num.length()]) && strings[i][startIndex + num.length()] != '.') {
                            if (num.length() > 1) {
                                if (!counted) {
                                    total += stoi(num);
                                    counted = true;
                                }   
                            }
                            else {
                                if (!counted) {
                                    total += (num[0] - '0');
                                    counted = true;
                                }
                            }
                        }
                        else if (!isdigit(strings[i + 1][startIndex + num.length()]) && strings[i + 1][startIndex + num.length()] != '.') {
                            if (num.length() > 1) {
                                if (!counted) {
                                    total += stoi(num);
                                    counted = true;
                                }   
                            }
                            else {
                                if (!counted) {
                                    total += (num[0] - '0');
                                    counted = true;
                                }
                            }
                        }
                    }
                    for (int k = 0; k < num.length(); k++) { // down
                        if (!isdigit(strings[i + 1][k + startIndex]) && strings[i + 1][k + startIndex] != '.') {
                            if (num.length() > 1) {
                                if (!counted) {
                                    total += stoi(num);
                                    counted = true;
                                }   
                            }
                            else {
                                if (!counted) {
                                    total += (num[0] - '0');
                                    counted = true;
                                }
                            }
                        }
                    }
                    num = "";
                    counted = false;
                }
            }
        }
        else if (i == strings.size() - 1) {// end - size - 1
            for (int j = 0; j < strings[i].length() + 1; j++) { //iterate through line
                if (num == "") {
                    if (!isdigit(strings[i][j])) {
                        continue;
                    }
                    else {
                        startIndex = j;
                        num += strings[i][j];
                    }
                }
                else if (isdigit(strings[i][j])) {
                    num += strings[i][j];
                }
                else {
                    if (startIndex != 0) { // left and diagonal up left
                        if (!isdigit(strings[i][startIndex - 1]) && strings[i][startIndex - 1] != '.') {
                            if (num.length() > 1) {
                                if (!counted) {
                                    total += stoi(num);
                                    counted = true;
                                }   
                            }
                            else {
                                if (!counted) {
                                    total += (num[0] - '0');
                                    counted = true;
                                }
                            }
                        }
                        else if (!isdigit(strings[i - 1][startIndex - 1]) && strings[i - 1][startIndex - 1] != '.') {
                            if (num.length() > 1) {
                                if (!counted) {
                                    total += stoi(num);
                                    counted = true;
                                }   
                            }
                            else {
                                if (!counted) {
                                    total += (num[0] - '0');
                                    counted = true;
                                }
                            }
                        }
                    }
                    if (startIndex + num.length() != strings[i].length() + 1) { //right and diagonal up right
                        if (!isdigit(strings[i][startIndex + num.length()]) && strings[i][startIndex + num.length()] != '.') {
                            if (num.length() > 1) {
                                if (!counted) {
                                    total += stoi(num);
                                    counted = true;
                                }   
                            }
                            else {
                                if (!counted) {
                                    total += (num[0] - '0');
                                    counted = true;
                                }
                            }
                        }
                        else if (!isdigit(strings[i - 1][startIndex + num.length()]) && strings[i - 1][startIndex + num.length()] != '.') {
                            if (num.length() > 1) {
                                if (!counted) {
                                    total += stoi(num);
                                    counted = true;
                                }   
                            }
                            else {
                                if (!counted) {
                                    total += (num[0] - '0');
                                    counted = true;
                                }
                            }
                        }
                    }
                    for (int k = 0; k < num.length(); k++) { // up
                        if (!isdigit(strings[i - 1][k + startIndex]) && strings[i - 1][k + startIndex] != '.') {
                            if (num.length() > 1) {
                                if (!counted) {
                                    total += stoi(num);
                                    counted = true;
                                }   
                            }
                            else {
                                if (!counted) {
                                    total += (num[0] - '0');
                                    counted = true;
                                }
                            }
                        }
                    }
                    num = "";
                    counted = false;
                }
            }
        }
        else { // middle
            for (int j = 0; j < strings[i].length() + 1; j++) { //iterate through line
                if (num == "") {
                    if (!isdigit(strings[i][j])) {
                        continue;
                    }
                    else {
                        startIndex = j;
                        num += strings[i][j];
                    }
                }
                else if (isdigit(strings[i][j])) {
                    num += strings[i][j];
                    if (num.length() == 3) {
                        if (startIndex != 0) { // left, diagonal up left, and diagonal down left
                            if (!isdigit(strings[i][startIndex - 1]) && strings[i][startIndex - 1] != '.') { // left
                                if (num.length() > 1) {
                                    if (!counted) {
                                        total += stoi(num);
                                        counted = true;
                                    }   
                                }
                                else {
                                    if (!counted) {
                                        total += (num[0] - '0');
                                        counted = true;
                                    }
                            }
                        }
                        else if (!isdigit(strings[i - 1][startIndex - 1]) && strings[i - 1][startIndex - 1] != '.') { // up left
                            if (num.length() > 1) {
                                if (!counted) {
                                    total += stoi(num);
                                    counted = true;
                                }   
                            }
                            else {
                                if (!counted) {
                                    total += (num[0] - '0');
                                    counted = true;
                                }
                            }
                        }
                        else if (!isdigit(strings[i + 1][startIndex - 1]) && strings[i + 1][startIndex - 1] != '.') { // down left
                            if (num.length() > 1) {
                                if (!counted) {
                                    total += stoi(num);
                                    counted = true;
                                }   
                            }
                            else {
                                if (!counted) {
                                    total += (num[0] - '0');
                                    counted = true;
                                }
                            }
                        }
                    }
                    if (startIndex + num.length() != strings[i].length()) { //right, diagonal up right, and diagonal down right
                        if (!isdigit(strings[i][startIndex + num.length()]) && strings[i][startIndex + num.length()] != '.') { // right
                            if (num.length() > 1) {
                                if (!counted) {
                                    total += stoi(num);
                                    counted = true;
                                }   
                            }
                            else {
                                if (!counted) {
                                    total += (num[0] - '0');
                                    counted = true;
                                }
                            }
                        }
                        else if (!isdigit(strings[i - 1][startIndex + num.length()]) && strings[i - 1][startIndex + num.length()] != '.') { // up right
                            if (num.length() > 1) {
                                if (!counted) {
                                    total += stoi(num);
                                    counted = true;
                                }   
                            }
                            else {
                                if (!counted) {
                                    total += (num[0] - '0');
                                    counted = true;
                                }
                            }
                        }
                        else if (!isdigit(strings[i + 1][startIndex + num.length()]) && strings[i + 1][startIndex + num.length()] != '.') { // down right
                            if (num.length() > 1) {
                                if (!counted) {
                                    total += stoi(num);
                                    counted = true;
                                }   
                            }
                            else {
                                if (!counted) {
                                    total += (num[0] - '0');
                                    counted = true;
                                }
                            }
                        }
                    }
                    for (int k = 0; k < num.length(); k++) { // up and down
                        if (!isdigit(strings[i - 1][k + startIndex]) && strings[i - 1][k + startIndex] != '.') { // up
                            if (num.length() > 1) {
                                if (!counted) {
                                    total += stoi(num);
                                    counted = true;
                                }   
                            }
                            else {
                                if (!counted) {
                                    total += (num[0] - '0');
                                    counted = true;
                                }
                            }
                        }
                        else if (!isdigit(strings[i + 1][k + startIndex]) && strings[i + 1][k + startIndex] != '.') { // down
                            if (num.length() > 1) {
                                if (!counted) {
                                    total += stoi(num);
                                    counted = true;
                                }   
                            }
                            else {
                                if (!counted) {
                                    total += (num[0] - '0');
                                    counted = true;
                                }
                            }
                        }
                    }
                    num = "";
                    counted = false;
                }
                }
                else {
                    if (startIndex != 0) { // left, diagonal up left, and diagonal down left
                        if (!isdigit(strings[i][startIndex - 1]) && strings[i][startIndex - 1] != '.') { // left
                            if (num.length() > 1) {
                                if (!counted) {
                                    total += stoi(num);
                                    counted = true;
                                }   
                            }
                            else {
                                if (!counted) {
                                    total += (num[0] - '0');
                                    counted = true;
                                }
                            }
                        }
                        else if (!isdigit(strings[i - 1][startIndex - 1]) && strings[i - 1][startIndex - 1] != '.') { // up left
                            if (num.length() > 1) {
                                if (!counted) {
                                    total += stoi(num);
                                    counted = true;
                                }   
                            }
                            else {
                                if (!counted) {
                                    total += (num[0] - '0');
                                    counted = true;
                                }
                            }
                        }
                        else if (!isdigit(strings[i + 1][startIndex - 1]) && strings[i + 1][startIndex - 1] != '.') { // down left
                            if (num.length() > 1) {
                                if (!counted) {
                                    total += stoi(num);
                                    counted = true;
                                }   
                            }
                            else {
                                if (!counted) {
                                    total += (num[0] - '0');
                                    counted = true;
                                }
                            }
                        }
                    }
                    if (startIndex + num.length() != strings[i].length()) { //right, diagonal up right, and diagonal down right
                        if (!isdigit(strings[i][startIndex + num.length()]) && strings[i][startIndex + num.length()] != '.') { // right
                            if (num.length() > 1) {
                                if (!counted) {
                                    total += stoi(num);
                                    counted = true;
                                }   
                            }
                            else {
                                if (!counted) {
                                    total += (num[0] - '0');
                                    counted = true;
                                }
                            }
                        }
                        else if (!isdigit(strings[i - 1][startIndex + num.length()]) && strings[i - 1][startIndex + num.length()] != '.') { // up right
                            if (num.length() > 1) {
                                if (!counted) {
                                    total += stoi(num);
                                    counted = true;
                                }   
                            }
                            else {
                                if (!counted) {
                                    total += (num[0] - '0');
                                    counted = true;
                                }
                            }
                        }
                        else if (!isdigit(strings[i + 1][startIndex + num.length()]) && strings[i + 1][startIndex + num.length()] != '.') { // down right
                            if (num.length() > 1) {
                                if (!counted) {
                                    total += stoi(num);
                                    counted = true;
                                }   
                            }
                            else {
                                if (!counted) {
                                    total += (num[0] - '0');
                                    counted = true;
                                }
                            }
                        }
                    }
                    for (int k = 0; k < num.length(); k++) { // up and down
                        if (!isdigit(strings[i - 1][k + startIndex]) && strings[i - 1][k + startIndex] != '.') { // up
                            if (num.length() > 1) {
                                if (!counted) {
                                    total += stoi(num);
                                    counted = true;
                                }   
                            }
                            else {
                                if (!counted) {
                                    total += (num[0] - '0');
                                    counted = true;
                                }
                            }
                        }
                        else if (!isdigit(strings[i + 1][k + startIndex]) && strings[i + 1][k + startIndex] != '.') { // down
                            if (num.length() > 1) {
                                if (!counted) {
                                    total += stoi(num);
                                    counted = true;
                                }   
                            }
                            else {
                                if (!counted) {
                                    total += (num[0] - '0');
                                    counted = true;
                                }
                            }
                        }
                    }
                    num = "";
                    counted = false;
                }
            }
        }
    }
    int part1 = 0;
    int part2 = 0;
    for (int i = 0; i < strings.size(); i++) {
        if (i != 0 && i != strings.size() - 1) { // middle
            for (int j = 0; j < strings[i].length(); j++) { //iterate through line
                if (strings[i][j] == '*') {
                    if (isdigit(strings[i - 1][j - 1]) || isdigit(strings[i - 1][j + 1]) || isdigit(strings[i - 1][j])) { // three above
                        partCount++;
                        if (isdigit(strings[i - 1][j - 1]) && isdigit(strings[i - 1][j + 1]) && !isdigit(strings[i][j])) { // checks for two parts
                            partCount++;
                            if (isdigit(strings[i - 1][j - 2])) { // checks for two characters on left part
                                if (isdigit(strings[i - 1][j - 3])) { // checks for three characters on left part
                                    string temp = "";
                                    temp += strings[i - 1][j - 3] + strings[i - 1][j - 2] + strings[i - 1][j - 1];
                                    part1 = stoi(temp);
                                }
                                else { // only two characters on left
                                    string temp = "";
                                    temp += strings[i - 1][j - 2] + strings[i - 1][j - 1];
                                    part1 = stoi(temp);
                                }
                            }
                            else { // only one character on left
                                part1 = strings[i - 1][j - 1] - '0';
                            }
                            if (isdigit(strings[i - 1][j + 2])) { // checks for two characters on right part
                                if (isdigit(strings[i - 1][j + 3])) { // checks for three characters on right part
                                    string temp = "";
                                    temp += strings[i - 1][j + 1] + strings[i - 1][j + 2] + strings[i - 1][j + 3];
                                    part1 = stoi(temp);
                                }
                                else { // only two characters on right
                                    string temp = "";
                                    temp += strings[i - 1][j + 1] + strings[i - 1][j + 2];
                                    part1 = stoi(temp);
                                }
                            }
                            else { // only one character on right
                                part1 = strings[i - 1][j + 1] - '0';
                            }
                        }
                        else { // only one part
                            if (isdigit(strings[i - 1][j]) && isdigit(strings[i - 1][j - 1]) && isdigit(strings[i - 1][j + 1])) { // all three characters
                                string temp = "";
                                temp += strings[i - 1][j - 3] + strings[i - 1][j - 2] + strings[i - 1][j - 1];
                                part1 = stoi(temp);
                            }
                            else if (isdigit(strings[i - 1][j - 1])) { // only left
                                if (isdigit(strings[i - 1][j - 2])) { // checks for two characters on left part
                                    if (isdigit(strings[i - 1][j - 3])) { // checks for three characters on left part
                                        string temp = "";
                                        temp += strings[i - 1][j - 3] + strings[i - 1][j - 2] + strings[i - 1][j - 1];
                                        part1 = stoi(temp);
                                    }
                                    else { // only two characters
                                        string temp = "";
                                        temp += strings[i - 1][j - 2] + strings[i - 1][j - 1];
                                        part1 = stoi(temp);
                                    }
                                }
                                else { // only one character
                                    part1 = strings[i - 1][j - 1] - '0';
                                }
                            }
                            else if (isdigit(strings[i - 1][j + 1])) { // only right
                                if (isdigit(strings[i - 1][j + 2])) { // checks for two characters on right part
                                    if (isdigit(strings[i - 1][j + 3])) { // checks for three characters on right part
                                        string temp = "";
                                        temp += strings[i - 1][j + 1] + strings[i - 1][j + 2] + strings[i - 1][j + 3];
                                        part1 = stoi(temp);
                                    }
                                    else { // only two characters
                                        string temp = "";
                                        temp += strings[i - 1][j + 1] + strings[i - 1][j + 2];
                                        part1 = stoi(temp);
                                    }
                                }
                                else { // only one character
                                    part1 = strings[i - 1][j + 1] - '0';
                                }
                            }
                        }
                    }
                    if (isdigit(strings[i][j - 1])) { //side left
                        partCount++;
                    }
                    if (isdigit(strings[i][j + 1])) { //side right
                        partCount++;
                    }
                    if (isdigit(strings[i + 1][j - 1]) || isdigit(strings[i + 1][j + 1])) { // three below
                        partCount++;
                        if (isdigit(strings[i + 1][j - 1]) && isdigit(strings[i + 1][j + 1]) && !isdigit(strings[i][j])) {
                            partCount++;
                        }
                    }
                }
                //if (partCount == 2) {
                    // add to totalGear
                //}
                
                /*if (num == "") {
                    if (!isdigit(strings[i][j])) {
                        continue;
                    }
                    else {
                        startIndex = j;
                        num += strings[i][j];
                    }
                }
                else if (isdigit(strings[i][j])) {
                    num += strings[i][j];
                }
                else {
                    
                }*/
                partCount = 0;
                countedGear = false;
            }
        }
    }
    cout << total << " ";
    cout << totalGear;
}