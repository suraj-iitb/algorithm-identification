#include<bits/stdc++.h>
using namespace std;
using lint = long long;
template<typename T = lint>inline T in() { T x; cin >> x; return x; }
#define INF           1e9
#define INFL          static_cast<lint>(INF)
#define REP(i,n)      for(lint i=0,i##_len=(n);i<i##_len;++i)
#define REP1(i,n)     for(lint i=1,i##_len=(n);i<=i##_len;++i)
#define REPR(i,n)     for(lint i=n-1;i>=0;--i)
#define REPR1(i,n)    for(lint i=n;i>0;--i)
#define REPI(i,ini,n) for(lint i=(ini),i##_len=(n);i<i##_len;++i)
#define REPC(i,obj)   for(auto i:obj)
#define R_UP(a,b)     (((a)+(b)-1)/(b))
#define ALL(obj)      (obj).begin(),(obj).end()
int main()
{
	int n = in();
	vector<int>a(n);
	REPC(&i, a)i = in();
	int cnt = 0;
	bool flag;
	do
	{
		flag = false;
		REP(i, n - 1)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				cnt++;
				flag = true;
			}
		}
	} while (flag);
	REP(i, n)
	{
		if (i != 0)cout << ' ';
		cout << a[i];
	}
	cout << endl;
	cout << cnt << endl;
}
