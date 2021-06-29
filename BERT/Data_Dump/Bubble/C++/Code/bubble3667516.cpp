#include<iostream>
using namespace std;

int bubbleSort(int A[], int N){
    bool frag = 1;
    int x=0;
    for(int i = 0; frag; i++){
        frag = 0;
        for (int j = N-1; j > 0; j--){
            if (A[j] < A[j-1]){
                swap(A[j-1],A[j]);
                frag = 1;
                x ++ ;
            }
        }
        
    }return x;
}
int main(){
    int x;
    int N;
    int A[1000];
    cin >>N;
    for (int i = 0; i < N; i++){
        cin >>A[i];
    }
    
    x = bubbleSort(A, N);
    for(int i = 0; i < N; i++){
        cout <<A[i];
        if(i!=N-1){
            cout<<" ";
        }
        else cout<<endl;
    }
    cout <<x<<endl;
    return 0;
}
