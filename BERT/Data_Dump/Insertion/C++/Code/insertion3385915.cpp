#include <iostream>
using namespace std;

const int MAX_N = 100;

int main(){
    int A[MAX_N];
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];

    for (int k = 0; k < n - 1; k++) cout << A[k] << " ";
    cout << A[n - 1] << "\n";

    for (int i = 1; i < n; i++) {

       int v = A[i];
       int j = i - 1;

       while(j >= 0 && A[j] > v){
           A[j + 1] = A[j];
           j--;
       }
       
       A[j + 1] = v;

       for (int k = 0; k < n - 1; k++) {
           cout << A[k] << " ";
       }
       cout << A[n - 1] << "\n";
    }
}

