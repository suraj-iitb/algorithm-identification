#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int N,minj,a,c;
    cin >> N;
    int A[N];
    c = 0;
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    
    for(int i=0;i<N-1;i++){
        minj = i;
        for(int j=i;j<N;j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        if(A[i] != A[minj]){
            c++;
        }
        a = A[i];
        A[i] = A[minj];
        A[minj] = a;
    }
    
    cout << A[0];
    for(int i=1;i<N;i++){
        cout << " " << A[i];
    }
    cout << endl;
    cout << c << endl;
}
