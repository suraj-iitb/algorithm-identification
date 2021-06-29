#include <iostream>
#include <vector>
using namespace std;

int bubbleSort(vector<int>& v) {
    int counter = 0;
    for (int i = 0; i < v.size() - 1; ++i)
        for (int j = v.size() - 1; j > i; --j)
            if (v[j - 1] > v[j]) {
                v[j - 1] = v[j - 1] ^ v[j];
                v[j] = v[j - 1] ^ v[j];
                v[j - 1] = v[j - 1] ^ v[j];

                counter++;
            }
    return counter;
}

void printVector(vector<int>& v, int counter) {
    for (int i = 0; i < v.size(); ++i)
        if (i + 1 != v.size()) {cout << v[i] << " ";}
        else {cout << v[i] << endl;}
    cout << counter << endl;
}

int main() {
    int N, tmp, counter;
    cin >> N;
    vector<int> v;

    for (int i = 0; i < N; ++i) {
        cin >> tmp;
        v.push_back(tmp);
    }

    counter = bubbleSort(v);
    printVector(v, counter);
}

