#include <iostream>
using namespace std;

void insertionSort(int A[], int N){
    int v;
    int i, j;
    
    for(int k = 0; k < N; k++){
            if(k == 0){
                cout << A[k];
            }else{
                cout << " " << A[k];
            }
        }
    
    cout << endl;
    
    for(i = 1; i < N; i++){
        v = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
            A[j+1] = v;
        }
        
        for(int k = 0; k < N; k++){
            if(k == 0){
                cout << A[k];
            }else{
                cout << " " << A[k];
            }
        }
        
        cout << endl;
    }
}

int main(void){
    int N;
    
    cin >> N;
    
    int A[N];
    
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    insertionSort(A, N);
    
}

