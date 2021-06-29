#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;

int main() {
    int count, A[1000];
    cin >> count;
    for (int i = 0; i < count; i++) {
        cin >> A[i];
    }
   
    for (int i = 0; i < count; i++) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;

        for (int j = 0; j < count; j++) {
            if (j > 0) cout << " ";
            cout << A[j];
        }
        cout << endl;
    }
}
