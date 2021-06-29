#include <iostream>
using namespace std;

int insertion_sort(int N, int A[]){
    for (int i=1; i<N; i++){
        int v = A[i];
        int j = i-1;
        while (j>=0 && A[j]>v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        for (int k=0; k<N; k++){
         if (k==N-1) cout << A[k] << "\n";
         else cout << A[k] << " ";
        }
    }
}

int main(){
    int N;
    cin >> N;
    int A[N] = {};
    for (int i=0; i<N; i++){
        cin >> A[i];
        if (i==N-1) cout << A[i] << "\n";
        else cout << A[i] << " ";
    }
    insertion_sort(N,A);
    
    return 0;
}
