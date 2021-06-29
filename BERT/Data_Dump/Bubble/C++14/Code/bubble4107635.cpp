#include <iostream>      // cout, endl, cin
#include <string>        // string, to_string, stoi
#include <vector>        // vector
#include <algorithm>     // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility>       // pair, make_pair
#include <tuple>         // tuple, make_tuple
#include <cstdint>       // int64_t, int*_t
#include <cstdio>        // printf
#include <map>           // map
#include <queue>         // queue, priority_queue
#include <set>           // set
#include <stack>         // stack
#include <deque>         // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset>        // bitset
#include <cctype>        // isupper, islower, isdigit, toupper, tolower
#include <math.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int bubbleSort(vector<int> &A, int N);

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A.at(i);
    int count = bubbleSort(A, N);
    rep(i, A.size())
    {
        cout << A.at(i);
        if (i != A.size() - 1)
        {
            cout << " ";
        }
        else
        {
            cout << endl;
        }
    }
    cout << count << endl;
}

int bubbleSort(vector<int> &A, int N) //N個の要素を含む、0オリジンの配列 A
{
    int count = 0;
    int flag = 1; //逆の隣接要素が存在する
    while (flag)
    {
        flag = 0;
        for (int j = N - 1; j > 0; j--)
        {
            if (A[j] < A[j - 1])
            {
                swap(A[j], A[j - 1]);
                flag = 1;
                count++;
            }
        }
    }
    return count;
}
