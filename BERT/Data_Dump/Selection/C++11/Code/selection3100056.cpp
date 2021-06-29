#include <iostream>
#include <vector>
using namespace std;

int SelectionSort(vector<int>& v) {
    int mini;
    int counter = 0;
    for (int i = 0; i < v.size(); ++i) {
        mini = i;
        for (int j = i + 1; j < v.size(); ++j) {
            if (v[j] < v[mini]) {
                mini = j;
            }
        }
        if (i != mini) {
            v[i] = v[i] ^ v[mini];
            v[mini] = v[i] ^ v[mini];
            v[i] = v[i] ^ v[mini];

            counter++;
        }
    }

    return counter;
}

int main() {
    int N, tmp, counter;
    vector<int> v;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> tmp;
        v.push_back(tmp);
    }
    counter = SelectionSort(v);
    for (int i = 0; i < v.size(); ++i) {
        if (i + 1 != v.size())
            cout << v[i] << " ";
        else
            cout << v[i] << endl;
    }
    cout << counter << endl;
}

