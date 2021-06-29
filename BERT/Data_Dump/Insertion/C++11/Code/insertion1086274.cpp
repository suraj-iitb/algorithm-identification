#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void printLine(vector<int> line, int length);

int main()
{
    int length;
    cin >> length;

    vector<int> line(length);
    for (auto i = 0; i < length; i++) {
        cin >> line.at(i);
    }
    printLine(line, length);

    int key;
    for (auto i = 1; i < length; i++) {
        key = line.at(i);

        auto j = i - 1;
        while (j >= 0 && line.at(j) > key) {
            line.at(j + 1) = line.at(j);
            j--;
        }
        line.at(j + 1) = key;

        printLine(line, length);
    }

    return 0;
}

void printLine(vector<int> line, int length)
{
    for (auto i = 0; i < length; i++) {
        if (i != 0) {
            cout << " ";
        }
        cout << line.at(i);
    }
    cout << endl;
}
