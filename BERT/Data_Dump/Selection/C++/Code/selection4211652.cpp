/*
selectSort(A, N)
    for i from 0 to N - 2
        minIndex = i
        j = i + 1
        while j < N
            if (A[j] < A[minIndex])
                minIndex = j
            ++j
        if i != minIndex
            A[i] 和 A[minIndex] 互换
      ++i
*/
#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void selectSort(int A[], int N, int &count) {
    for(int i = 0 ; i < N; ++i) {
        int minIndex = i;
        int j = i;
        while (j < N) {
            if (A[j] < A[minIndex])
                minIndex = j;
            ++j;
        }
        
        if (i != minIndex) {
            swap(A[i], A[minIndex]);
            count += 1;
        }
    }
}

int main() {
    int N = 0;
    int A[100];
    int count = 0;
    cin >> N;
    for(int i = 0; i < N; ++i) {cin >> A[i];}
    selectSort(A, N, count);
    for(int i = 0; i < N; ++i) {
        if (i > 0)
            cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;
    return 0;
}
