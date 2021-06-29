#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <limits>
using namespace std;

//static const int MAX = 1000;
void selectionsort(int A[], int N){
    int count = 0;
    for (int i=0;i<N;i++){
        int mini = i;
        for (int j=i+1;j<N;j++){
            if (A[j] < A[mini]){
                mini = j;
            }
        }
        if (i != mini){
            swap(A[i], A[mini]);
            count++;
        }
    }
    cout << A[0];
    for (int i=1;i<N;i++) cout << " " << A[i];
    cout << endl;
    cout << count << endl;
}

int main(){
    int N;
    cin >> N;
    int A[100];
    for (int i=0;i<N;i++) cin >> A[i];
    selectionsort(A, N);
}

