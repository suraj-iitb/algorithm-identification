#include <iostream>
#include <vector>

using namespace std;

void output(vector<int> arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        cout << arr[i] << " ";
    }
    cout << arr[arr.size() - 1] << endl;
}

void step(vector<int>& arr, int step) {
    int i = step, pick = arr[step + 1];
    while (0 <= i && arr[i] > pick) {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = pick;
}

void insertionSort(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        output(arr);
        step(arr, i);
    }
}

int main() {
    vector<int> arr;
    int size;
    cin >> size;
    for (int i = 0; i < size; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
    }
    insertionSort(arr);
    return 0;
}

