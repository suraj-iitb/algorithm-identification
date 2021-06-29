#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int n;

template <typename T>
void print(vector<T> vec)
{
    int n = vec.size();
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << (i == n - 1 ? "\n" : " ");
    }
}

template <typename T>
void bubbleSort(vector<T> &A, int &cnt)
{
    int n = A.size();
    cnt = 0;
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (int i = n - 1; i > 0; i--)
        {
            if (A[i] < A[i - 1])
            {
                swap(A[i], A[i - 1]);
                flag = true, cnt++;
            }
        }
    }
    print(A);
}

// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_A

#include <vector>
template <typename T>
void insertionSort(vector<T> &A)
{
    print(A);
    int n = A.size();
    for (int i = 1; i < n; i++)
    {
        T v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        print(A);
    }
}

int main()
{
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    insertionSort(A);
}

