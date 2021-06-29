#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cctype>
#include<climits>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<memory>
#include<functional>
 
using namespace std;
 
#define ALL(g) (g).begin(),(g).end()
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define F(i,j,k) fill(i[0],i[0]+j*j,k)
#define P(p) cout<<(p)<<endl;
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define INF 1<<25
#define pb push_back
 
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
typedef long long ll;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    int A[N];
    int i;
    rep(i,N) cin >> A[i];
    int count = 0;
    for (int j = 0; j < N; ++j)
    {
        int minj = j;
        for (int k = j; k < N; ++k)
        {
            if(A[minj] > A[k]){
                minj = k;
            }
        }
        if (j != minj)
        {
            count++;
            int tmp = A[j];
            A[j] = A[minj];
            A[minj] = tmp;
        }
    }
    rep(i,N - 1) cout << A[i] << " ";
    P(A[N-1]);
    P(count);

    return 0;
}
