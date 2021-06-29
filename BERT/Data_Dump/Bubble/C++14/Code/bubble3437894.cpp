#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int n;

#include <vector>
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
void BubbleSort(vector<T> &C, int &cnt)
{
    int n = C.size();
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 2; j >= i; j--)
        {
            if (C[j] > C[j + 1])
            {
                swap(C[j], C[j + 1]);
                cnt++;
            }
        }
    }
    print(C);
}

//stabは安定ソートされたvector
template <typename T>
bool is_stable(vector<T> stab, vector<T> v)
{
    if (stab == v)
        return true;
    else
        return false;
}

int main()
{
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int c;
    BubbleSort(v, c);
    cout << c << endl;
}
