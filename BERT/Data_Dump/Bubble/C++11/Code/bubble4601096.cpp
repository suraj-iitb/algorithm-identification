#include <bits/stdc++.h>
#include <sstream>
using namespace std;

typedef long long ll;
typedef pair<int, pair<int, int>> piii;
//loop
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REPD(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define FORD(i, a, b) for (ll i = a; i >= (ll)(b); i--)
//STL
#define ALL(x) (x).begin(), (x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

//const
#define MOD 1000000007 //10^9+7:合同式の法

//acronym
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first      //pairの一つ目の要素
#define S second     //pairの二つ目の要素

const int INF = 1e9;

int bubbleSort(vector<int> &A, int N)
{
    int swap_cnt = 0;
    bool flag = true;
    while (flag)
    {
        flag = false;
        FORD(j, N - 1, 1)
        {
            if (A.at(j) < A.at(j - 1))
            {
                swap(A.at(j), A.at(j - 1));
                swap_cnt++;
                flag = true;
            }
        }
    }
    return swap_cnt;
}

void Main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    REP(i, N)
    cin >> A.at(i);

    int swap_cnt = bubbleSort(A, N);

    REP(i, N)
    {
        if (i != 0)
        {
            cout << " ";
        }
        cout << A.at(i);
    }
    cout << endl;
    cout << swap_cnt << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Main();
    return 0;
}

