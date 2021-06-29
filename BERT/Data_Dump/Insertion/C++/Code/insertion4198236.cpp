#include<iostream>
using namespace std;

int N;
int A[1007];

void visualize(int* A, int N) 
{
    for (int i = 0; i < N-1; i++) {
        cout << A[i] << " ";
    }
    cout << A[N-1] << endl;
}

void insertionSort(int* A, int N)
{
    visualize(A, N);
    
    for (int i = 1; i < N; i++) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        visualize(A, N);
    }
}

int main(void)
{
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    insertionSort(A, N);
    
    return 0;
}
