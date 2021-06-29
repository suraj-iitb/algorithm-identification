#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print_num(int A[], int N){
    for(int i=0; i<N; i++){
        if(i != N-1){
            cout << A[i] << " ";
        }else{
            cout << A[i] << endl;
        }
    }
}

void insertionSort(int A[], int N){
    for(int i=0; i<N; i++){
        int v = A[i];
        int j = i-1;
        while(j >= -1 && A[j] > v){
            A[j+1] = A[j];
            j--;
            A[j+1] = v;
        }
        print_num(A, N);
    }

}

int main(){
    int n;
    cin >> n;
    int vec[n];
    for(int i=0; i<n; i++) cin >> vec[i];

    insertionSort(vec, n);


    return 0;
}
