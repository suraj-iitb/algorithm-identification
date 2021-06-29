#include <iostream>
#include <math.h>
#include<iomanip>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    int A[100];
    int x;

    for (int i=0;i<N;i++){
        cin >> A[i];
    }

    for (int i=0;i<N;i++) {
        int minj = i;
        for (int j=i;j<N;j++) {
            if (A[j] < A[minj]) { //Get the smallest place
                minj = j;
            }
        }
        if (A[i] > A[minj]) {
            int v = A[i];
            A[i] = A[minj];
            A[minj] = v;
            x++;
        }
    }

    for (int k=0;k<N-1;k++){
        if (k == (N-1)) {
            break;
        }
        else {
            cout << A[k] << " ";
        }
    }
    cout << A[N-1] << endl;
    cout << x << endl;
}
