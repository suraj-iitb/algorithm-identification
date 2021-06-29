#include <iostream>
using namespace std;

void prt(int A[], int N){
    for(int i=0; i<N; i++){
        if(i!=0) cout<<" ";
        cout << A[i];
    }
    cout << endl;
}

void insertion(int A[], int N){
    for(int i=1; i<N; i++){
        prt(A, N);
        int key = A[i];
        int j = i-1;
        while(j>=0&&A[j]>key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}
int main(){
    int A[100];
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    insertion(A, N);
    prt(A, N);
}
