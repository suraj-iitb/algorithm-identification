#include <iostream>
using namespace std;

void printArray(int A[], int N){
    for(int i = 0; i < N; i++){
        if(i == 0){
            cout << A[i];
        }else{
            cout << " " << A[i];
        }
    }
    
    cout << endl;
}
void bubbleSort(int A[], int N){
    bool flag = true;
    int inversion = 0; //反転数
    
    
    while(flag){
        flag = false;
        for(int j = N-1; j >= 1; j--){
            if(A[j] < A[j-1]){
                inversion++;
                int tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                flag = true;
            }
        }
    }
    
    printArray(A,N);
    cout << inversion << endl;
    
}

int main(void){
    int N;
    cin >> N;
    
    int A[N];
    
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    bubbleSort(A, N);
    
}
