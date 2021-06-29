#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> counting_sort(vector<int> *A)
{
    map<int, long> M;

    for (int a : *A)
    {
        if (M.find(a) == M.end())
        {
            M.insert(make_pair(a, 1));
        }
        else
        {
            M.at(a)++;
        }
    }

    vector<int> B;

    for (int i = 0; i <= 10000; i++)
    {
        if (M.find(i) == M.end())
        {
            continue;
        }

        for (long j = 0; j < M.at(i); j++)
        {
            B.push_back(i);
        }
    }

    return B;
}

int main()
{
    long n;
    cin >> n;
    vector<int> A(n);
    for (long i = 0; i < n; i++)
    {
        cin >> A.at(i);
    }

    vector<int> B = counting_sort(&A);
    cout << B.at(0);
    for (long i = 1; i < B.size(); i++)
    {
        cout << ' ' << B.at(i);
    }
    cout << endl;
}

