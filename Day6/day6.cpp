#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>

using namespace std;

int main() {
    string fileName = "Races.txt";
    ifstream inputStream(fileName);
    vector<string> strings;
    int times[4];
    int distances[4];
    int wins[4] = {0,0,0,0};

    string temp = "";
    string line1;
    while(getline(inputStream, line1)) {
        strings.push_back(line1);
    }
    temp += strings[0][13]; // times
    temp += strings[0][14];
    times[0] = stoi(temp);
    temp = "";

    temp += strings[0][20];
    temp += strings[0][21];
    times[1] = stoi(temp);
    temp = "";

    temp += strings[0][27];
    temp += strings[0][28];
    times[2] = stoi(temp);
    temp = "";

    temp += strings[0][34];
    temp += strings[0][35];
    times[3] = stoi(temp);
    temp = "";

    temp += strings[1][12]; //distances
    temp += strings[1][13];
    temp += strings[1][14];
    distances[0] = stoi(temp);
    temp = "";

    temp += strings[1][18];
    temp += strings[1][19];
    temp += strings[1][20];
    temp += strings[1][21];
    distances[1] = stoi(temp);
    temp = "";

    temp += strings[1][25];
    temp += strings[1][26];
    temp += strings[1][27];
    temp += strings[1][28];
    distances[2] = stoi(temp);
    temp = "";

    temp += strings[1][32];
    temp += strings[1][33];
    temp += strings[1][34];
    temp += strings[1][35];
    distances[3] = stoi(temp);
    temp = "";

    int remaining;
    remaining = times[0];
    while (remaining !=0) {
        int held = times[0] - remaining;
        if (held * remaining >= distances[0]) {
            wins[0]++;
        }
        remaining --;
    }

    remaining = times[1];
    while (remaining !=0) {
        int held = times[1] - remaining;
        if (held * remaining >= distances[1]) {
            wins[1]++;
        }
        remaining --;
    }

    remaining = times[2];
    while (remaining !=0) {
        int held = times[2] - remaining;
        if (held * remaining >= distances[2]) {
            wins[2]++;
        }
        remaining --;
    }

    remaining = times[3];
    while (remaining !=0) {
        int held = times[3] - remaining;
        if (held * remaining >= distances[3]) {
            wins[3]++;
        }
        remaining --;
    }

    cout << wins[0] * wins[1] * wins[2] * wins[3] << endl;
}