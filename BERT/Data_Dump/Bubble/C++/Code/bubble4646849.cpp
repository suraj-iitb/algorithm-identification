#include <iostream>
#include <vector>
#include <string>

using namespace std;

void trace(int A[], int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (i > 0)
            cout << " ";
        cout << A[i] ;
    }
    cout << endl;
}


void bubbleSort(int A[], int N,int *c)
{
    // N 個の要素を含む 0-オリジンの配列 A
    bool flag = true; // 逆の隣接要素が存在する
    while (flag)
    {
        flag = false;
        for (int j = N - 1; j > 0; j--)
        { // j が N-1 から 1 まで
        if (A[j] < A[j - 1]) {
				(*c)++;
                int v = A[j];
                A[j] = A[j - 1];
                A[j - 1] = v;
                //         A[j] と A[j-1] を交換
                flag = 1;
            }
        }
    }
}
int main()
{
    int A[100], N,c;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
c=0;
	bubbleSort(A,N,&c);
    trace(A,N);
cout << c << endl;
}

