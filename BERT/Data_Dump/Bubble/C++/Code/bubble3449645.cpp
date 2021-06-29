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

void bubbleSort(int A[], int N){
    
    int flip_count = 0;
    
    bool flag = true;
    while(flag){
        flag = false;
        for(int j=N-1; j>0; j--){
            if(A[j] < A[j-1]){
                flip(&A[j], &A[j-1]);
                flip_count++;
                flag = true;
            }
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
    
    bubbleSort(A, N);
    
    return 0;
}

