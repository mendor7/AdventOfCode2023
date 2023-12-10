#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    int total = 0;
    string fileName = "Strings.txt";
    ifstream inputStream(fileName);

    string line;
    string num = "";
    while(getline(inputStream, line)) {
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == '1' || line[i] == '2' || line[i] == '3' ||
                line[i] == '4' || line[i] == '5' || line[i] == '6' || line[i] == '7' ||
                line[i] == '8' || line[i] == '9') {
                    num += line[i];
                    break;
            }
            else if (line[i] == 'o') {
                if (line.length() > i + 2 && line[i + 1] == 'n' && line[i + 2] == 'e') {
                    num += "1";
                    break;
                }
            }
            else if (line[i] == 't') {
                if (line.length() > i + 2 && line[i + 1] == 'w' && line[i + 2] == 'o') {
                    num += "2";
                    break;
                }
                else if (line.length() > i + 4 && line[i + 1] == 'h' && line[i + 2] == 'r' && line[i + 3] == 'e' && line[i + 4] == 'e') {
                    num += "3";
                    break;
                }
            }
            else if (line[i] == 'f') {
                if (line.length() > i + 3 && line[i + 1] == 'o' && line[i + 2] == 'u' && line[i + 3] == 'r') {
                    num += "4";
                    break;
                }
                else if (line.length() > i + 3 && line[i + 1] == 'i' && line[i + 2] == 'v' && line[i + 3] == 'e') {
                    num += "5";
                    break;
                }
            }
            else if (line[i] == 's') {
                if (line.length() > i + 2 && line[i + 1] == 'i' && line[i + 2] == 'x') {
                    num += "6";
                    break;
                }
                else if (line.length() > i + 4 && line[i + 1] == 'e' && line[i + 2] == 'v' && line[i + 3] == 'e' && line[i + 4] == 'n') {
                    num += "7";
                    break;
                }
            }
            else if (line[i] == 'e') {
                if (line.length() > i + 4 && line[i + 1] == 'i' && line[i + 2] == 'g' && line[i + 3] == 'h' && line[i + 4] == 't') {
                    num += "8";
                    break;
                }
            }
            else if (line[i] == 'n') {
                if (line.length() > i + 3 && line[i + 1] == 'i' && line[i + 2] == 'n' && line[i + 3] == 'e') {
                    num += "9";
                    break;
                }
            }
        }
        for (int i = line.length() - 1; i >= 0; i--) {
            if (line[i] == '1' || line[i] == '2' || line[i] == '3' ||
                line[i] == '4' || line[i] == '5' || line[i] == '6' || line[i] == '7' ||
                line[i] == '8' || line[i] == '9') {
                    num += line[i];
                    break;
            }
            else if (line[i] == 'e') { //1 3 5 9
                if (i - 2 >= 0 && line[i - 1] == 'n' && line[i - 2] == 'o') {
                    num += "1";
                    break;
                }
                else if (i - 4 >= 0 && line[i - 1] == 'e' && line[i - 2] == 'r' && line[i - 3] == 'h' && line[i - 4] == 't') {
                    num += "3";
                    break;
                }
                else if (i - 3 >= 0 && line[i - 1] == 'v' && line[i - 2] == 'i' && line[i - 3] == 'f') {
                    num += "5";
                    break;
                }
                else if (i - 3 >= 0 && line[i - 1] == 'n' && line[i - 2] == 'i' && line[i - 3] == 'n') {
                    num += "9";
                    break;
                }
            }
            else if (line[i] == 'o') { //2
                if (i - 2 >= 0 && line[i - 1] == 'w' && line[i - 2] == 't') {
                    num += "2";
                    break;
                }
            }
            else if (line[i] == 'r') { //4
                if (i - 3 >= 0 && line[i - 1] == 'u' && line[i - 2] == 'o' && line[i - 3] == 'f') {
                    num += "4";
                    break;
                }
            }
            else if (line[i] == 'x') { //6
                if (i - 2 >= 0 && line[i - 1] == 'i' && line[i - 2] == 's') {
                    num += "6";
                    break;
                }
            }
            else if (line[i] == 'n') { //7
                if (i - 4 >= 0 && line[i - 1] == 'e' && line[i - 2] == 'v' && line[i - 3] == 'e' && line[i - 4] == 's') {
                    num += "7";
                    break;
                }
            }
            else if (line[i] == 't') { //8
                if (i - 4 >= 0 && line[i - 1] == 'h' && line[i - 2] == 'g' && line[i - 3] == 'i' && line[i - 4] == 'e') {
                    num += "8";
                    break;
                }
            }
        }
        total += stoi(num);
        num = "";
    }
    cout << total;
}