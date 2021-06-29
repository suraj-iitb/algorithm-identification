#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <limits>
using namespace std;

//static const int MAX = 1000;
void trace(int A[], int N){
    cout << A[0];
    for (int i=1;i<N;i++) cout << " " << A[i];
    cout << endl;
}
void insert(int A[], int N){
    for (int i=1;i<N;i++){
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        trace(A, N);
    }
}

int main(){
    int N;
    cin >> N;
    int A[100];
    for (int i=0;i<N;i++) cin >> A[i];
    trace(A, N);
    insert(A, N);
}
