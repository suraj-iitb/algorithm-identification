#include <iostream>
#include <math.h>
#include<iomanip>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    int A[100];

    for (int i=0;i<N;i++){
        cin >> A[i];
    }

    bool flag=1;
    int i = 0, x = 0;
    while(flag){
        flag = 0;
        for (int j=N-1;j>=i+1;j--){
            if (A[j]<A[j-1]){
                int v = A[j];
                A[j] = A[j-1];
                A[j-1] = v;
                flag = 1;
                x++;
            }
        }
        i++;
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

//    for (int k=0;k<N-1;k++){
//        cout << A[k] << " ";
//    }
//    cout << A[N-1] << endl;
}
