#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>

using namespace std;

int main() {
    string fileName = "Hands.txt";
    ifstream inputStream(fileName);
    vector<string> strings;

    string line1;
    while(getline(inputStream, line1)) {
        strings.push_back(line1);
    }
}