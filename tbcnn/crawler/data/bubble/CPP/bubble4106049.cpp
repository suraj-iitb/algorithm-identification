#include<iostream>

using namespace std;

// 整数配列Aと長さnを受け取り、バブルソートによる整列を行なう.
int bubbleSort(int A[], int n);

// 配列Aと位置i, jを受け取り配列A[i]とA[j]を交換する.
void swap(int A[], int i, int j);

// 配列Aと長さn, 交換回数を受け取り、配列と交換回数を出力する.
void Result(int A[], int n, int chg_count);

int main()
{
    int n;
    int A[100];

    // Input of instance
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int chg_count = bubbleSort(A, n);
    Result(A, n, chg_count);

    return 0;
}

int bubbleSort(int A[], int n)
{
    bool flag = true;
    int chg_count = 0;
    
    while (flag) {
        flag = false;
        for (int i = n - 1; i > 0; i--){
            if (A[i] < A[i-1]) {
                swap(A, i, i-1);
                chg_count++;
                flag = true;
            }
        }
    }

    return chg_count;
}

void swap(int A[], int i, int j)
{
    int tmp;
    tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

void Result(int A[], int n, int chg_count)
{
    for (int i = 0; i < n - 1; i++){
        cout << A[i] << ' ';
    }

    cout << A[n - 1] << endl;

    cout << chg_count << endl;
}
