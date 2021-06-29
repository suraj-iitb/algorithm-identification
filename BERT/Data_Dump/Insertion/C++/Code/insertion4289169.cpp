#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

void trace(int N, int A[]) {
    for(int i = 0; i < N; i++) {
        if(i >= 1) {
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;
}
int main() {
    int N;
    cin >> N;
    int data[N];
    for(int i = 0; i < N; i++) {
        cin >> data[i];
    }
    trace(N, data);
    for(int i = 1; i < N; i++) {
        int v = data[i];
        int j = i-1;
        while(j>=0 && v < data[j]){
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = v;
        trace(N, data);
    }
    return 0;
}
