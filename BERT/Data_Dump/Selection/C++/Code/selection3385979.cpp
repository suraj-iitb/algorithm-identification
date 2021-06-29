#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100;

int main(){

    int n, minj;
    int num = 0;
    int A[N];

    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) {
       minj = i; 
       for (int j = i; j < n; j++) {
           if(A[minj] > A[j]) minj = j;
       }
       swap(A[i],A[minj]);
       if(i != minj) num++;
    }

    for (int i = 0; i < n - 1; i++) cout << A[i] << " ";
    cout << A[n - 1] << "\n" << num << "\n";
    
    return 0;
}

