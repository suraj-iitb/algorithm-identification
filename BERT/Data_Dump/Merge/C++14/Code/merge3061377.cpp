#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define INF            1e9
#define REP(i,n)       for(lint i=0,i##_len=(n);i<i##_len;++i)
#define REP1(i,n)      for(lint i=1,i##_len=(n);i<=i##_len;++i)
#define REPI(i,ini,n)  for(lint i=(ini),i##_len=(n);i<i##_len;++i)
#define REPR(i,n)      for(lint i=(n)-1;i>=0;--i)
#define REPR1(i,n)     for(lint i=(n);i>0;--i)
#define REPRI(i,ini,n) for(lint i=(ini)-1,i##_len=(n);i>=i##_len;--i)
#define REPC(i,obj)    for(auto i:obj)
#define R_UP(a,b)      (((a)+(b)-1)/(b))
#define ALL(obj)       (obj).begin(),(obj).end()
using namespace std;
using lint = long long;
template<typename T = lint>inline T in() { T x; cin >> x; return x; }
int ans = 0;
void merge_sort(vector<int>&s, int left, int right)
{
	static int workspace[500000];
	if (left == right)return;
	int medium = (left + right) / 2;
	merge_sort(s, left, medium);
	merge_sort(s, medium + 1, right);
	for (int i = left; i <= medium; ++i)workspace[i] = s[i];
	for (int i = medium + 1, j = right; i <= right; ++i, --j)workspace[j] = s[i];
	for (int i = left, j = right, k = left; k <= right; ++k, ++ans)s[k] = workspace[i] <= workspace[j] ? workspace[i++] : workspace[j--];
}
signed main()
{
	int n = in();
	vector<int>s(n);
	REP(i, n)scanf("%d", &s[i]);
	merge_sort(s, 0, n - 1);
	REP(i, n)
	{
		if (i != 0)cout << ' ';
		cout << s[i];
	}
	cout << endl;
	cout << ans << endl;
}
