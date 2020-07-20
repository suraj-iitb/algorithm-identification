#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 100;

int main(){
    bool flag = 1;
    int A[MAX_N];
    int n, num = 0;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> A[i];

    while(flag){
        flag = 0;
        for (int j = n - 1; j >= 1; j--) {
           if(A[j] < A[j - 1]){
               swap(A[j],A[j - 1]);
               num++;
               flag = 1;
           }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        cout << A[i] << " ";
    }
    cout << A[n - 1] << "\n" << num << "\n";

    return 0;
}

