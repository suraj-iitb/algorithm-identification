//挿入ソート(insertion sort)
#include"bits/stdc++.h"
using namespace std;

void insertionsort(int *N, int A[]){
    int v;
    for(int i=0; i<*N; i++){
        v = A[i];
        int j = i-1;
        while(j >= 0 && A[j]>v){
            A[j+1] = A[j];
            j --;
        }
        A[j+1] = v;
        for(int c=0; c<*N-1; c++){
            cout << A[c] << " ";
        }
        
        cout << A[*N-1] <<"\n";
    }
}

int main(){
    int N;
    int A[1000];
    cin >> N;
    for(int i = 0; i<N; i++ ){
        cin >> A[i];   
    }
    insertionsort(&N, A);
    return 0;
}
