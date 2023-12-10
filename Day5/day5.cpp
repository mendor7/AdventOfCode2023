#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <thread>
#include <unordered_map>

using namespace std;
void getSeeds(string);
void getMap(string);
long long int seeds[20];
long long int maps[196][3];
long long int lowest;
vector<string> strings;
//unordered_map<int, bool> calculated;
//bool calculated = false;
//void resetCalculated();
long long int calculateLocation(long long int);
void sendSeeds(int);
void getMaps();
int mapCount = 0;

int main() {
    string fileName = "Strings.txt";
    ifstream inputStream(fileName);
    

    string line1;
    string num = "";
    //resetCalculated();

    while(getline(inputStream, line1)) {
        strings.push_back(line1);
    }
    getSeeds(strings[0]);
    lowest = seeds[0];
    getMaps();
    thread th1(sendSeeds, 0);
    thread th2(sendSeeds, 2);
    thread th3(sendSeeds, 4);
    thread th4(sendSeeds, 6);
    thread th5(sendSeeds, 8);
    thread th6(sendSeeds, 10);
    thread th7(sendSeeds, 12);
    thread th8(sendSeeds, 14);
    thread th9(sendSeeds, 16);
    thread th10(sendSeeds, 18);
    th1.join();
    th2.join();
    th3.join();
    th4.join();
    th5.join();
    th6.join();
    th7.join();
    th8.join();
    th9.join();
    th10.join();

    /*for (int i = 3; i < 31; i++) { // seed-to-soil
        getMap(strings[i]);
        for (int j = 0; j < 20; j++) {
            if (seeds[j] >= map[1] && seeds[j] < (map[1] + map[2]) && calculated[j] == false) {
                seeds[j] = seeds[j] - map[1] + map[0];
                calculated[j] = true;
            }
        }
    }
    //resetCalculated();

    for (int i = 33; i < 43; i++) { //soil-to-fertilizer
        getMap(strings[i]);
        for (int j = 0; j < 20; j++) {
            if (seeds[j] >= map[1] && seeds[j] < (map[1] + map[2]) && calculated[j] == false) {
                seeds[j] = seeds[j] - map[1] + map[0];
                calculated[j] = true;
            }
        }
    }
    //resetCalculated();
    
    for (int i = 45; i < 54; i++) { //fertilizer-to-water
        getMap(strings[i]);
        for (int j = 0; j < 20; j++) {
            if (seeds[j] >= map[1] && seeds[j] < (map[1] + map[2]) && calculated[j] == false) {
                seeds[j] = seeds[j] - map[1] + map[0];
                calculated[j] = true;
            }
        }
    }
    //resetCalculated();

    for (int i = 56; i < 79; i++) { // water-to-light
        getMap(strings[i]);
        for (int j = 0; j < 20; j++) {
            if (seeds[j] >= map[1] && seeds[j] < (map[1] + map[2]) && calculated[j] == false) {
                seeds[j] = seeds[j] - map[1] + map[0];
                calculated[j] = true;
            }
        }
    }
    //resetCalculated();

    for (int i = 81; i < 113; i++) { // light-to-temperature
        getMap(strings[i]);
        for (int j = 0; j < 20; j++) {
            if (seeds[j] >= map[1] && seeds[j] < (map[1] + map[2]) && calculated[j] == false) {
                seeds[j] = seeds[j] - map[1] + map[0];
                calculated[j] = true;
            }
        }
    }
    //resetCalculated();

    for (int i = 115; i < 160; i++) { // temperature-to-humidity
        getMap(strings[i]);
        for (int j = 0; j < 20; j++) {
            if (seeds[j] >= map[1] && seeds[j] < (map[1] + map[2]) && calculated[j] == false) {
                seeds[j] = seeds[j] - map[1] + map[0];
                calculated[j] = true;
            }
        }
    }
    //resetCalculated();

    for (int i = 162; i < 211; i++) { // humidity-to-location
        getMap(strings[i]);
        for (int j = 0; j < 20; j++) {
            if (seeds[j] >= map[1] && seeds[j] < (map[1] + map[2]) && calculated[j] == false) {
                seeds[j] = seeds[j] - map[1] + map[0];
                calculated[j] = true;
            }
        }
    }
    //resetCalculated();

    for (int i = 1; i < 20; i++) {
        if (lowest > seeds[i]) {
            lowest = seeds[i];
        }
    }
    */
    cout << lowest << endl; // not 74139777
}

void getSeeds(string line) {
    int index = 7;
    int count = 0;
    string temp = "";
    while (isdigit(line[index]) && count < 20) {
        if (isdigit(line[index + 1])) {
            temp += line[index];
            index++;
        }
        else {
            temp += line[index];
            seeds[count] = stoll(temp);
            count++;
            temp = "";
            index += 2;
        }
    }
}

void getMap(string line, int mapCount) {
    int index = 0;
    int count = 0;
    string temp = "";
    while (isdigit(line[index]) && count < 3) {
        if (isdigit(line[index + 1])) {
            temp += line[index];
            index++;
        }
        else {
            temp += line[index];
            if (count == 0) {
                maps[mapCount][0] = stoll(temp);
            }
            else if (count == 1) {
                maps[mapCount][1] = stoll(temp);
            }
            else if (count == 2) {
                maps[mapCount][2] = stoll(temp);
            }
            count++;
            temp = "";
            index += 2;
        }
    }
}

/*void resetCalculated() {
    for (int i = 0; i < 20; i++) {
        calculated[i] = false;
    }
}*/

void sendSeeds(int index) {
    long long int tempNum;
    long long int start = seeds[index];
    long long int range = seeds[index + 1];
    for (long long int i = start; i < start + range; i++) {
        tempNum = calculateLocation(i);
        if (lowest > tempNum) {
            lowest = tempNum;
        }
    }
}

long long int calculateLocation(long long int num) {
    for (int i = 0; i < 28; i++) { // seed-to-soil
        if (num >= maps[i][1] && num < (maps[i][1] + maps[i][2])) {
            num = num - maps[i][1] + maps[i][0];
            break;
        }
    }

    for (int i = 28; i < 38; i++) { //soil-to-fertilizer
        if (num >= maps[i][1] && num < (maps[i][1] + maps[i][2])) {
            num = num - maps[i][1] + maps[i][0];
            break;
        }
    }
    
    for (int i = 38; i < 47; i++) { //fertilizer-to-water
        if (num >= maps[i][1] && num < (maps[i][1] + maps[i][2])) {
            num = num - maps[i][1] + maps[i][0];
            break;
        }
    }

    for (int i = 47; i < 70; i++) { // water-to-light
        if (num >= maps[i][1] && num < (maps[i][1] + maps[i][2])) {
            num = num - maps[i][1] + maps[i][0];
            break;
        }
    }

    for (int i = 70; i < 102; i++) { // light-to-temperature
        if (num >= maps[i][1] && num < (maps[i][1] + maps[i][2])) {
            num = num - maps[i][1] + maps[i][0];
            break;
        }
    }

    for (int i = 102; i < 147; i++) { // temperature-to-humidity
        if (num >= maps[i][1] && num < (maps[i][1] + maps[i][2])) {
            num = num - maps[i][1] + maps[i][0];
            break;
        }
    }

    for (int i = 147; i < 196; i++) { // humidity-to-location
        if (num >= maps[i][1] && num < (maps[i][1] + maps[i][2])) {
            num = num - maps[i][1] + maps[i][0];
            break;
        }
    }
    /*for (int i = 3; i < 31; i++) { // seed-to-soil
        getMap(strings[i], &destination, &source, &range);
        if (num >= source && num < (source + range) && calculated == false) {
            num = num - source + destination;
            calculated = true;
        }
    }
    calculated = false;

    for (int i = 33; i < 43; i++) { //soil-to-fertilizer
        getMap(strings[i], &destination, &source, &range);
        if (num >= source && num < (source + range) && calculated == false) {
            num = num - source + destination;
            calculated = true;
        }
    }
    calculated = false;
    
    for (int i = 45; i < 54; i++) { //fertilizer-to-water
        getMap(strings[i], &destination, &source, &range);
        if (num >= source && num < (source + range) && calculated == false) {
            num = num - source + destination;
            calculated = true;
        }
    }
    calculated = false;

    for (int i = 56; i < 79; i++) { // water-to-light
        getMap(strings[i], &destination, &source, &range);
        if (num >= source && num < (source + range) && calculated == false) {
            num = num - source + destination;
            calculated = true;
        }
    }
    calculated = false;

    for (int i = 81; i < 113; i++) { // light-to-temperature
        getMap(strings[i], &destination, &source, &range);
        if (num >= source && num < (source + range) && calculated == false) {
            num = num - source + destination;
            calculated = true;
        }
    }
    calculated = false;

    for (int i = 115; i < 160; i++) { // temperature-to-humidity
        getMap(strings[i], &destination, &source, &range);
        if (num >= source && num < (source + range) && calculated == false) {
            num = num - source + destination;
            calculated = true;
        }
    }
    calculated = false;

    for (int i = 162; i < 211; i++) { // humidity-to-location
        getMap(strings[i], &destination, &source, &range);
        if (num >= source && num < (source + range) && calculated == false) {
            num = num - source + destination;
            calculated = true;
        }
    }
    calculated = false;*/
    
    return num;
}

void getMaps() {
    for (int i = 3; i < 31; i++) { // seed-to-soil
        getMap(strings[i], mapCount);
        mapCount++;
    }

    for (int i = 33; i < 43; i++) { //soil-to-fertilizer
        getMap(strings[i], mapCount);
        mapCount++;
    }
    
    for (int i = 45; i < 54; i++) { //fertilizer-to-water
        getMap(strings[i], mapCount);
        mapCount++;
    }

    for (int i = 56; i < 79; i++) { // water-to-light
        getMap(strings[i], mapCount);
        mapCount++;
    }

    for (int i = 81; i < 113; i++) { // light-to-temperature
        getMap(strings[i], mapCount);
        mapCount++;
    }

    for (int i = 115; i < 160; i++) { // temperature-to-humidity
        getMap(strings[i], mapCount);
        mapCount++;
    }

    for (int i = 162; i < 211; i++) { // humidity-to-location
        getMap(strings[i], mapCount);
        mapCount++;
    }
}