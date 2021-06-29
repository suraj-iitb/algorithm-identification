#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<int> v(N);

    for (auto &&x : v)
    {
        cin >> x;
    }

    for (int k = 0; k < N; ++k)
    {
        cout << v[k] << (k != N - 1 ? " " : "\n");
    }

    for (int i = 1; i < N; i++)
    {
        int tmp = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > tmp)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = tmp;
        for (int k = 0; k < N; ++k)
        {
            cout << v[k] << (k != N - 1 ? " " : "\n");
        }
    }

    return 0;
}

