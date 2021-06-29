#include<iostream>
#include<string>
using namespace std;





void SelectionSort(int A[],int N){
    int minj;
    int sw = 0;
    for (int i =0; i < N; i++){
        minj = i;
        for (int j = i; j < N; j++){
            if (A[j] < A[minj]){
                minj = j;
            }
        }
        if (i !=minj){
            swap(A[i],A[minj]);
            sw++;
        }
    }
    for (int i = 0; i < N-1; i++) cout << A[i] << " ";
    cout << A[N-1] << endl;
    cout << sw << endl;
}


int main(){
    int N;
    int A[100];
    
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    SelectionSort(A,N);  
    
    
}
