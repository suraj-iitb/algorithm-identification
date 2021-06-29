#include <iostream>
using namespace std;

/*ALDS1_1_A:   Insertion Sort*/

void InsertionSort(int A[], int N);
void printArray(int A[], int N);

int main(void){
    // Here your code !
    int N;
    int A[1000];
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    
    printArray(A, N);
    InsertionSort(A, N);
    

}

void InsertionSort(int A[], int N){
    for (int i=1; i<N; i++){
        int v = A[i];
        int j= i-1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        
        
        printArray(A, N);
    }
}

void printArray(int A[], int N){
    for(int i=0; i<N; i++){
        cout << A[i];
        if ( i < N-1 ) cout << " ";
        else cout << "\n";
    }
}
