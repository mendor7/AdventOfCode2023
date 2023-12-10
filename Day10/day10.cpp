#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>

using namespace std;

int main() {
    string fileName = "Maze.txt";
    ifstream inputStream(fileName);
    vector<string> strings;
    int currentRow = 114; // Starts on S line
    int currentCol = 36; // Start at next character '7'
    int prevRow = 114; // Starts on S line
    int prevCol = 35; // Start at character 'S'
    int stepCount = 1;
    bool moved;

    string line1;
    while(getline(inputStream, line1)) {
        strings.push_back(line1);
    }
    // S is at row index 114 column index 35
    while (strings[currentRow][currentCol] != 'S') { // need to account for checking for S at the end
        moved = false;
        if (strings[currentRow][currentCol] == '|') {
            if ((strings[currentRow - 1][currentCol] == '|' || strings[currentRow - 1][currentCol] == '7' || strings[currentRow - 1][currentCol] == 'F' || strings[currentRow - 1][currentCol] == 'S') && moved == false) { // look for | and 7 and F in north characters
                if (currentRow - 1 != prevRow || currentCol != prevCol) { // if not backwards, go forward
                    prevRow = currentRow;
                    prevCol = currentCol;
                    currentRow = currentRow - 1;
                    currentCol = currentCol;
                    stepCount++;
                    moved = true;
                }
            }
            if ((strings[currentRow + 1][currentCol] == '|' || strings[currentRow + 1][currentCol] == 'L' || strings[currentRow + 1][currentCol] == 'J' || strings[currentRow + 1][currentCol] == 'S') && moved == false) { // look for | and L and J in south characters
                if (currentRow + 1 != prevRow || currentCol != prevCol) { // if not backwards, go forward
                    prevRow = currentRow;
                    prevCol = currentCol;
                    currentRow = currentRow + 1;
                    currentCol = currentCol;
                    stepCount++;
                    moved = true;
                }
            }
        }
        else if (strings[currentRow][currentCol] == '-') {
            if ((strings[currentRow][currentCol - 1] == '-' || strings[currentRow][currentCol - 1] == 'L' || strings[currentRow][currentCol - 1] == 'F' || strings[currentRow][currentCol - 1] == 'S') && moved == false) { // look for - and L and F in west characters
                if (currentRow != prevRow || currentCol - 1 != prevCol) { // if not backwards, go forward
                    prevRow = currentRow;
                    prevCol = currentCol;
                    currentRow = currentRow;
                    currentCol = currentCol - 1;
                    stepCount++;
                    moved = true;
                }
            }
            if ((strings[currentRow][currentCol + 1] == '-' || strings[currentRow][currentCol + 1] == 'J' || strings[currentRow][currentCol + 1] == '7' || strings[currentRow][currentCol + 1] == 'S') && moved == false) { // look for - and J and 7 in east characters
                if (currentRow != prevRow || currentCol + 1 != prevCol) { // if not backwards, go forward
                    prevRow = currentRow;
                    prevCol = currentCol;
                    currentRow = currentRow;
                    currentCol = currentCol + 1;
                    stepCount++;
                    moved = true;
                }
            }
        }
        else if (strings[currentRow][currentCol] == 'L') {
            if ((strings[currentRow - 1][currentCol] == '|' || strings[currentRow - 1][currentCol] == '7' || strings[currentRow - 1][currentCol] == 'F' || strings[currentRow - 1][currentCol] == 'S') && moved == false) { // look for | and 7 and F in north characters
                if (currentRow - 1 != prevRow || currentCol != prevCol) { // if not backwards, go forward
                    prevRow = currentRow;
                    prevCol = currentCol;
                    currentRow = currentRow - 1;
                    currentCol = currentCol;
                    stepCount++;
                    moved = true;
                }
            }
            if ((strings[currentRow][currentCol + 1] == '-' || strings[currentRow][currentCol + 1] == 'J' || strings[currentRow][currentCol + 1] == '7' || strings[currentRow][currentCol + 1] == 'S') && moved == false) { // look for - and J and 7 in east characters
                if (currentRow != prevRow || currentCol + 1 != prevCol) { // if not backwards, go forward
                    prevRow = currentRow;
                    prevCol = currentCol;
                    currentRow = currentRow;
                    currentCol = currentCol + 1;
                    stepCount++;
                    moved = true;
                }
            }
        }
        else if (strings[currentRow][currentCol] == 'J') {
            if ((strings[currentRow - 1][currentCol] == '|' || strings[currentRow - 1][currentCol] == '7' || strings[currentRow - 1][currentCol] == 'F' || strings[currentRow - 1][currentCol] == 'S') && moved == false) { // look for | and 7 and F in north characters
                if (currentRow - 1 != prevRow || currentCol != prevCol) { // if not backwards, go forward
                    prevRow = currentRow;
                    prevCol = currentCol;
                    currentRow = currentRow - 1;
                    currentCol = currentCol;
                    stepCount++;
                    moved = true;
                }
            }
            if ((strings[currentRow][currentCol - 1] == '-' || strings[currentRow][currentCol - 1] == 'L' || strings[currentRow][currentCol - 1] == 'F' || strings[currentRow][currentCol - 1] == 'S') && moved == false) { // look for - and L and F in west characters
                if (currentRow != prevRow || currentCol - 1 != prevCol) { // if not backwards, go forward
                    prevRow = currentRow;
                    prevCol = currentCol;
                    currentRow = currentRow;
                    currentCol = currentCol - 1;
                    stepCount++;
                    moved = true;
                }
            }
        }
        else if (strings[currentRow][currentCol] == '7') {
            if ((strings[currentRow + 1][currentCol] == '|' || strings[currentRow + 1][currentCol] == 'L' || strings[currentRow + 1][currentCol] == 'J' || strings[currentRow + 1][currentCol] == 'S') && moved == false) { // look for | and L and J in south characters
                if (currentRow + 1 != prevRow || currentCol != prevCol) { // if not backwards, go forward
                    prevRow = currentRow;
                    prevCol = currentCol;
                    currentRow = currentRow + 1;
                    currentCol = currentCol;
                    stepCount++;
                    moved = true;
                }
            }
            if ((strings[currentRow][currentCol - 1] == '-' || strings[currentRow][currentCol - 1] == 'L' || strings[currentRow][currentCol - 1] == 'F' || strings[currentRow][currentCol - 1] == 'S') && moved == false) { // look for - and L and F in west characters
                if (currentRow != prevRow || currentCol - 1 != prevCol) { // if not backwards, go forward
                    prevRow = currentRow;
                    prevCol = currentCol;
                    currentRow = currentRow;
                    currentCol = currentCol - 1;
                    stepCount++;
                    moved = true;
                }
            }
        }
        else if (strings[currentRow][currentCol] == 'F') {
            if ((strings[currentRow + 1][currentCol] == '|' || strings[currentRow + 1][currentCol] == 'L' || strings[currentRow + 1][currentCol] == 'J' || strings[currentRow + 1][currentCol] == 'S') && moved == false) { // look for | and L and J in south characters
                if (currentRow + 1 != prevRow || currentCol != prevCol) { // if not backwards, go forward
                    prevRow = currentRow;
                    prevCol = currentCol;
                    currentRow = currentRow + 1;
                    currentCol = currentCol;
                    stepCount++;
                    moved = true;
                }
            }
            if ((strings[currentRow][currentCol + 1] == '-' || strings[currentRow][currentCol + 1] == 'J' || strings[currentRow][currentCol + 1] == '7' || strings[currentRow][currentCol + 1] == 'S') && moved == false) { // look for - and J and 7 in east characters
                if (currentRow != prevRow || currentCol + 1 != prevCol) { // if not backwards, go forward
                    prevRow = currentRow;
                    prevCol = currentCol;
                    currentRow = currentRow;
                    currentCol = currentCol + 1;
                    stepCount++;
                    moved = true;
                }
            }
        }
    }
    cout << stepCount / 2 << endl;
}