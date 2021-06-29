#include<iostream>
using namespace std;

int selectionSort(int A[],int N){
    int minj,b;
    int c = 0;
    for(int i = 0 ; i < N-1 ; i++){
        minj = i;
        for(int j = i ; j < N ; j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        b = A[i];
        A[i] = A[minj];
        A[minj] = b;

        if(i != minj){
            c += 1;
        }       
    }
    return c;
}

int main(){
    int A[100];
    int N , c;

    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> A[i];
    }

    c = selectionSort(A , N);

    for(int i = 0 ; i < N ; i++){
        if(i > 0 ){
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;
    cout << c << endl;
    
    return 0;
}
