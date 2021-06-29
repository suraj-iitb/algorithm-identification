#include <iostream>
#include <math.h>
using namespace std;

void print_array(int B[], int N){
    for(int i = 0 ; i < N - 1 ; i++){
        cout << B[i] << " ";
    }
    cout << B[N - 1] << endl;   
}


int main(void){
    // Your code here!
    int N;
    int A[100];
    int key = 0;
    int j, k;
    
    cin >> N;
    
    for (int i = 0 ; i < N ; i++){
        cin >> A[i];
    }
    

    print_array(A, N);
    for (j = 1 ; j < N; j ++){
        key = A[j];
        k = j - 1;
        while(k >= 0 and A[k] > key){
            A[k + 1] = A [k];
            k--;
        }
        A[k + 1] = key;
        print_array(A, N);
    } 

}

