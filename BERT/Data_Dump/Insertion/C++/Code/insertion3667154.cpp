#include<iostream>
using namespace std;
void Sort(int A[], int N){
    int i, j, v;
    for(i = 1; i < N; i++){
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j --;
        }
        A[j+1] = v;
        for(int i = 0; i < N; i++){
            cout <<A[i];
            if(i!=N-1){
                cout<<" ";
            }
            else cout<<endl;
        }
    }
}
int main(){
    int N;
    int A[1000];
    cin >>N;
    for (int i = 0; i < N; i++){
        cin >>A[i];
    }
    for(int i = 0; i < N; i++){
            cout <<A[i];
            if(i!=N-1){
                cout<<" ";
            }
            else cout<<endl;
        }
    Sort(A, N);
    
    return 0;
}

