#include <iostream>
#include <vector>
using namespace std;
void print_v(vector<int> v)
{
    for (auto it = v.begin(); it != v.end() - 1; it++)
    {
        cout << *it << ' ';
    }
    cout << v.back() << endl;
}
void InsertionSort(vector<int> A, int N)
{
    for (int i = 1; i < N; i++)
    {
        int v = A.at(i);
        int j = i - 1;

        while (j >= 0 && A.at(j) > v)
        {
            A.at(j + 1) = A.at(j);
            j--;
        }
        A.at(j + 1) = v;
        print_v(A);
    }
}
int main()
{
    vector<int> A;
    int N;
    cin >> N;
    A.reserve(N);
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        A.push_back(n);
    }

    print_v(A);

    InsertionSort(A, N);
}
