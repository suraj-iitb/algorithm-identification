#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

#define MAX 2000000


void couting_sort(int A[], int B[], int n)
{
    int max_v = *max_element(A, A + n);
    vector<int> counter(10000, 0);

    for (int i = 0; i < n; i++)
        counter[A[i]]++;
    for (int i = 1; i <= max_v; i++) {
        counter[i] += counter[i - 1];
    }

    for (int i = 0; i < n; i++) {
        B[--counter[A[i]]] = A[i];
    }
}


int A[MAX];
int B[MAX];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    couting_sort(A, B, n);

    for (int i = 0; i < n - 1; i++)
        cout << B[i] << " ";
    cout << B[n - 1] << endl;

    return 0;
}

