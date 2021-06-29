#include <iostream>
using namespace std;

int L[10000000],R[10000000];
int cnt;
void merge(int A[], int left, int mid, int right)
{
    // int *L = new int[mid - left + 1];
    // int *R = new int[right - mid + 1];
    for (int i = 0; i < mid - left; i++)
        L[i] = A[left + i];
    L[mid - left] = 1000000000+1;
    for (int j = 0; j < right - mid; j++)
        R[j] = A[mid + j];
    R[right - mid] = 1000000000+1;
    int k = 0, i = 0, j = 0;
    while (k != right - left)
    {
        cnt++;
        if(L[i] > R[j])
        {
            A[left+k] = R[j];
            j++;
        }
        else//这样比else if减少了一倍的比较运算
        {
            A[left+k] = L[i];
            i++;
        }
        k++;
    }
    // delete L, R;
}
void mergeSort(int A[], int left, int right)
{
    if (right - left <= 1)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
}

int main()
{
    int n;
    cnt = 0;
    cin >> n;
    int *A = new int[n];
    for(int i = 0; i < n; i++)
        cin >> A[i];
    mergeSort(A, 0, n);
    for(int i = 0; i < n; i++)
    {
        if(i)cout<<" ";
        cout << A[i];
    }
    cout << endl;
    delete A;
    return 0;
}
