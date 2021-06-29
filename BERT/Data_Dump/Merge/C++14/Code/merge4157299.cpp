#include <iostream> // cout, endl, cin
#include <string>   // string, to_string, stoi
#include <vector>   // vector
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define MAX 500000
#define SENTINEL 2000000000 //番兵

vector<int> L(MAX / 2 + 2), R(MAX / 2 + 2);
int cnt = 0;

void merge(vector<int> &A, int n, int left, int mid, int right)
{
    int n1 = mid - left;  //midから左の個数
    int n2 = right - mid; //midから右の個数
    rep(i, n1) L[i] = A[left + i];
    rep(i, n2) R[i] = A[mid + i];
    L[n1] = R[n2] = SENTINEL;
    int i = 0, j = 0;
    for (int k = left; k < right; k++)
    {
        cnt++;
        if (L[i] <= R[j])
        {
            A[k] = L[i++];
        }
        else
        {
            A[k] = R[j++];
        }
    }
}

void mergeSort(vector<int> &A, int n, int left, int right)
{
    if (left + 1 < right)
    {
        int mid = (left + right) / 2;
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }
}

int main()
{
    vector<int> A(MAX);
    int n, i;
    cin >> n;
    rep(i, n) cin >> A[i];

    mergeSort(A, n, 0, n);

    rep(i, n)
    {
        if (i)
            cout << " ";
        cout << A[i];
    }
    cout << endl;

    cout << cnt << endl;
    return 0;
}
