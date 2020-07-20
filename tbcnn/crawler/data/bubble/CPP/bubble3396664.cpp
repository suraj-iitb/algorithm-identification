#include <iostream>
using namespace std;

int bubblesort(int A[], int N);
int main(){
    int N, n;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    n = bubblesort(A, N);
    for(int i = 0; i < N; i++){
        if(i>0) cout << ' ';
        cout << A[i];
    }
    cout << endl << n << endl;
}

int bubblesort(int A[], int N){
    bool flag = 1;
    int n = 0;
    int k = 0;
    while(flag){
        flag = 0;
        for(int j = N - 1; j > k; j--){
            if(A[j] < A[j-1]){
                swap(A[j], A[j-1]);
                flag = 1;
                n++;
            }
        }
        k++;
    }
    return n;
}
