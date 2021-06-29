#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define EACH(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(c) sort((c).begin(), (c).end())
#define CLR(a) memset((a), 0, sizeof(a))
#define dump(x) cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" \
                      << " " << __FILE__ << endl;
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())

//using LL = long long;
using namespace std;

const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
const double EPS = 1e-10;
const double PI = acos(-1.0);

int main()
{
    int n, A[100], mini, count = 0;
    cin >> n;
    vector<int> v;
    int temp;
    for (; cin >> temp;)
    {
        v.push_back(temp);
    }

    for (int i = 0; i < n - 1; i++){
        mini = i;
        for (int j = i + 1; j < n; j++){
            if (v[j] < v[mini])
                mini = j;
        }

        if (i != mini){
            count++;
            swap(v[i], v[mini]);
        }
    }

    for (int i = 0; i < n; i++){
        if (i) cout << ' ';
        cout << v[i];
    }
    cout << endl << count << endl;

    return 0;
}
