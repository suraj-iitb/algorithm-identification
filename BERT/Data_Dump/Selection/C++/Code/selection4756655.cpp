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
void selectionSort(int A[], int N){
    int change = 0; //交換回数
    int minj;
    
    for(int i = 0; i < N; i++){
        minj = i;
        for(int j = i; j < N; j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        
        if(i != minj) change++;
            int tmp = A[i];
            A[i] = A[minj];
            A[minj] = tmp;
    }
    
    printArray(A,N);
    cout << change << endl;
    
}

int main(void){
    int N;
    cin >> N;
    
    int A[N];
    
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    selectionSort(A, N);
    
}
