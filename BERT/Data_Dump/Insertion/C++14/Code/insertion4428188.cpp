#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <set>
#include <list>

using namespace std;

void print(vector<int> A) {
    for(int i; i<A.size(); i++){
        cout << A[i];
        if (i != A.size() - 1) cout << " ";
    }
    cout << endl;
}

void insertionSort(vector<int> A, int N) {
    int v, j;
    for (int i = 0; i < N; i++) {

        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        print(A);
    }
}

int main() {
    int N, a;
    vector<int> A;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        A.push_back(a);
    }
    insertionSort(A, N);
}
