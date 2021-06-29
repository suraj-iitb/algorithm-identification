#include<iostream>
#include<algorithm>
using namespace std;

void insertionSort(int A[],int N){
    int j,i,v;
    for (i=1 ; 1<=i && i<N ;i++){
        v = A[i];
        j = i - 1;
        while (j >=0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1]=v;
        for (int p=0; p<=N-1;p++){
            cout << A[p];
            if (p < N-1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main(){
    int N,i,j;
    int A[100];
    cin >> N;
    for (i=0;i<=N-1;i++){
        cin >> A[i];
    }
    for (int p=0; p<=N-1;p++){
        cout << A[p];
        if (p < N-1) {
        cout << " ";
        }
    }
    cout << endl;    
    insertionSort(A,N);
    return 0;
}
