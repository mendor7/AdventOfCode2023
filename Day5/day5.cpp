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
long long int map[3];
long long int lowest;
vector<string> strings;
//unordered_map<int, bool> calculated;
bool calculated = false;
//void resetCalculated();
long long int calculateLocation(long long int);
void sendSeeds(long long int, long long int);

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
    thread th1(sendSeeds, seeds[0], seeds[1]);
    thread th2(sendSeeds, seeds[2], seeds[3]);
    thread th3(sendSeeds, seeds[4], seeds[5]);
    thread th4(sendSeeds, seeds[6], seeds[7]);
    thread th5(sendSeeds, seeds[8], seeds[9]);
    thread th6(sendSeeds, seeds[10], seeds[11]);
    thread th7(sendSeeds, seeds[12], seeds[13]);
    thread th8(sendSeeds, seeds[14], seeds[15]);
    thread th9(sendSeeds, seeds[16], seeds[17]);
    thread th10(sendSeeds, seeds[18], seeds[19]);
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
    cout << lowest << endl;
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

void getMap(string line, long long int * destination, long long int * source, long long int * range) {
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
                *destination = stoll(temp);
            }
            else if (count == 1) {
                *source = stoll(temp);
            }
            else if (count == 2) {
                *range = stoll(temp);
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

void sendSeeds(long long int start, long long int range) {
    long long int tempNum;
    for (long long int i = start; i < start + range - 1; i++) {
        tempNum = calculateLocation(i);
        if (lowest > tempNum) {
            lowest = tempNum;
        }
    }
}

long long int calculateLocation(long long int num) {
    long long int destination;
    long long int source;
    long long int range;
    for (int i = 3; i < 31; i++) { // seed-to-soil
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
    calculated = false;

    return num;
}