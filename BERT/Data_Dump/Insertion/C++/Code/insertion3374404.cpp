#include <iostream>
using namespace std;

void insertionSort(int* A, int N){
    int i,j,v;
    for(i=1;i<N;i++){
        v = A[i];
        j = i - 1;
        while(j>=0&&A[j]>v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        for(j=0;j<N;j++){
            cout << A[j];
            if(j!=N-1){
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main(){
    int N,*A,i;
    cin >> N;
    A = new int[N];
    for(i=0;i<N;i++){
        cin >> A[i];
    }
    for(i=0;i<N;i++){
        cout << A[i];
        if(i!=N-1){
            cout << " ";
        }
    }
    cout << endl;
    insertionSort(A,N);
    return 0;
}
