#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <complex>
#include <stack>
#include <queue>
#include <list>
#include <utility>
#include <map>
#include <set>
using namespace std;

void insertionSort(int *A, int N){
    int i, j, k;
    int v;
    for(i = 1; i < N; i++){
        v = A[i];
        j = i-1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        
        for(k = 0; k < N-1; k++){
            cout << A[k] << " ";
        }
        cout << A[N-1] << endl;
    }
}

int main(){
    int n;
    cin >> n;
    int i = 0;
    int a[n];
    
    for(i = 0; i < n; i++){
        cin >> a[i];
    }
    
    for(i = 0; i < n-1; i++){
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
    
    insertionSort(a, n);
}

