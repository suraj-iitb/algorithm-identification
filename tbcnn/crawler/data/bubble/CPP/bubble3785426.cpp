#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

void print_output(int* in, int N)
{
    for (int i = 0; i < N; i++)
    {
        if (i != 0)
        {
            cout << " ";
        }
        cout << in[i];
    }
    cout << endl;
}

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
#ifdef LOCAL
    // 以降 cin の入力元が 'xxx.txt' になる
    std::ifstream in("in.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;

    int A[100];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    int cnt = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = N-1; j > i; j--)
        {
            if (A[j] < A[j-1])
            {
                swap(A[j], A[j-1]);
                cnt++;
            }
        }
    }

    print_output(A, N);

    cout << cnt << endl;


    return 0;
}

