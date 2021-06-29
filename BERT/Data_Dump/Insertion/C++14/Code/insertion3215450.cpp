#include <iostream>

using namespace std;

void print(int *p, int n)
{
    cout << p[0];
    for (int i = 1; i < n; i++) cout << " " << p[i];
    cout << endl;
}

int main(void)
{
    int A[100];
    int N;
    int i, j, v;
    cin >> N;
    for (i = 0; i < N; i++) cin >> A[i];
    print(A, N);
    for (i = 1; i < N; i++)
    {
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        print(A, N);
    }
    return 0;
}
