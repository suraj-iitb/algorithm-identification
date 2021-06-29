#include<iostream>
using namespace std;

int A[100];

int selectionSort(int A[], int N);

int main(){
    int N;
    cin >> N;
    for (int i=0; i<N; i++) cin >> A[i];
    int sum=selectionSort(A, N);
    for (int i=0; i<N; i++) cout << A[i] << (i != N-1 ? " " : "\n");
    cout << sum << endl;
}

int selectionSort(int A[], int N){
    int sum=0;
    for (int i=0; i<N; i++){
        int minj=i;
        bool flag = false;
        for (int j=i+1; j<N; j++){
            if (A[j] < A[minj]){
                minj = j;
                flag = true;
            }
        }
        if (flag){
            swap(A[i], A[minj]);
            sum++;
            flag = false;
        }
    }
    return sum;
}
