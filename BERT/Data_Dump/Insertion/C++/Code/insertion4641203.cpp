#include <iostream>
#include <cstring>

using namespace std;
int n, A[100];

void print() {
    for (int i = 0; i < n; i++) {
        cout << A[i];
        if (i != n - 1) cout << ' ';
    }
    cout << endl;
}

void insertionSort(int A[], int N) {
    for (int i = 1; i < N; i++) {
        //从第一个元素开始处理，到第n-1个元素结束
        int v = A[i], j = i - 1;
        while (j >= 0 && A[j] > v) {//当j>=0并且前一个元素大于当前元素的值时进入循环
            A[j + 1] = A[j];
            j--;
        }//前一个元素不大于当前元素的时退出循环
        A[j + 1] = v;
        print();
    }
}

int main() {
    cin >> n;
    memset(A, 0, sizeof(A));
    for (int i = 0; i < n; i++)
        cin >> A[i];
    print();
    insertionSort(A, n);
    return 0;
}
