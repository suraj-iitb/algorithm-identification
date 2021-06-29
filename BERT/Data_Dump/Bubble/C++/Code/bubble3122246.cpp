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

    int flag = 1;
        while (flag) {
            flag = 0;
            for(int j = N - 1; j >= 1; j--) {
                if (A[j] < A[j-1]) {
                    int temp = A[j];
                    A[j] = A[j-1];
                    A[j-1] = temp;
                    flag = 1;
                    ::count++;
                }
            }
        }

    for (int i = 0; i < N; i++) {
        cout << A[i];
        if(i < N-1) cout << " ";
    }
    cout << endl;

    cout << ::count << endl;

    return 0;
}

