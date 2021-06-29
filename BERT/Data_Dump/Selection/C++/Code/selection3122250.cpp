#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 100

void bubbleSort(int A[], int N);

static int count = 0;

int main()
{
    int A[MAX];
    int N;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        int minj = i;
        for(int j = i; j < N; j++) {
            if(A[j] < A[minj]) minj = j;
        }
        if(A[i] != A[minj]) ::count++;
        int temp = A[i];
        A[i] = A[minj];
        A[minj] = temp;
    }

    for (int i = 0; i < N; i++) {
        cout << A[i];
        if(i < N-1) cout << " ";
    }
    cout << endl;

    cout << ::count << endl;

    return 0;
}

