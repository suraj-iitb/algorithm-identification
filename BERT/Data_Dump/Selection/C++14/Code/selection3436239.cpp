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

#include <vector>

//cnt:sawpの回数
template <typename T>
void selectionSort(vector<T> &A, int &cnt)
{
    int n = A.size();
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int minj = i;
        for (int j = i; j < n; j++)
        {
            if (A[j] < A[minj])
                minj = j;
        }
        if (A[i] != A[minj])
        {
            cnt++;
            swap(A[i], A[minj]);
        }
    }
}

int main()
{
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int c = 0;
    selectionSort(A, c);
    print(A);
    cout << c << endl;
}
