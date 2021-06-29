#include <bits/stdc++.h>
using namespace std;

int selectionSort(int A[],int N){
    int aw = 0,kl;
    for(int i = 0;i < N-1;i++){
        kl = i;
        for(int j = i;j < N;j++){
            if(A[j] < A[kl])kl = j;
        }
        swap(A[i],A[kl]);
        if(i != kl)aw++;
    }
    return aw;
}

int main(){
    int A[100],N,aw;
    cin >> N;
    for(int i = 0;i < N;i++)cin >> A[i];
    aw = selectionSort(A,N);
    for(int i = 0;i < N;i++){
        if(i > 0)cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << aw << endl;
}
