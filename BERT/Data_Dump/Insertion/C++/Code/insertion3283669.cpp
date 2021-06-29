#include <bits/stdc++.h>

using namespace std;

void out(int A[], int N)
{
    for(int i = 0; i < N; i++){
        if(i > 0){
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;
}

void insertionSort(int A[], int N) 
{
    for(int i = 1; i < N; i++){
        int a = A[i];
        int j = i - 1;
        for(; j >= 0 && A[j] > a ; j--){
            A[j + 1] = A[j];
        }
        A[j + 1] = a;
        out(A, N);
    }
}

int main()
{
    int N;
    int A[1000];
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    out(A, N);
    insertionSort(A, N);
    return 0;
}
