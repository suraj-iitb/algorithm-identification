#include <iostream>
using namespace std;

void printArray(int A[], int N){
    
    for(int i=0; i<N; i++){
        cout << A[i];
        if(i<N-1) cout << " ";
    }
    
    cout << endl;
    
}

void flip(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selectionSort(int A[], int N){
    
    int flip_count = 0;
    
    for(int i=0; i<N; i++){
        int minj = i;
        for(int j=i; j<N; j++){
            if( A[j] < A[minj] ){
                minj = j;
            }
        }
        if( i != minj ){
            flip(&A[i], &A[minj]);
            flip_count++;
        }
    }
    
    printArray(A, N);
    cout << flip_count << endl;
    
}

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    int A[N];
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    
    selectionSort(A, N);
    
    return 0;
}

