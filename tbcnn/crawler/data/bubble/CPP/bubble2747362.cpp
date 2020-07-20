#include<iostream>
using namespace std;

int  bubblesort(int A[], int N);

int main(){
    int N, ans;
    int A[100];
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i];
    }
    ans = bubblesort(A, N);
    for (int i=0; i<N; i++){
        cout << A[i];
        cout << (i != N-1 ? " " : "\n");
    }
    cout << ans << endl;
}

int bubblesort(int A[], int N){
    int tmp;
    int sum=0;
    int end=0;
    for (int i=0; i<N; i++){
        for (int j=N-1; j>i; j--){
            if (A[j] < A[j-1]){
                swap(A[j], A[j-1]);
                sum++;
            }
        }
        end++;
    }
    return sum;
}
