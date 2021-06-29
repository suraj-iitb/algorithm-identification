
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include<vector>
#include<cstring>
#include<set>
#include <cstdio>
#include<queue>
#include<map>
#define WHITE 0
#define GRAY  1
#define BLACK 2
#define endl '\n'
#define forup(i,a,n) for( int i =a; i < n; i++)
#define llforup(i,a,n) for( ll i =a; i < n; i++)
#define fordown(i,a,n) for( int i =a; i >= n; i--)
#define fornot(i,a,n) for( int i=a;!n;i++)
#define mod  (ll)(1e9+7)
#define ifempty(a)  if(!a)
using namespace std;
typedef long long ll;
inline int readnum()
{
	int p, data = 0; char ch = 0;
	while ((ch != '-') &&( ch < '0' || ch>'9') )//注意运算优先级，逻辑与大于逻辑非
		ch = getchar();//相当于正则表达式的搜索，跳过不需要的字符
	if (ch == '-')
		p = -1, ch = getchar();//不能与if平行放置，不懂为什么，可能是bug
	else p = 1;
	while (ch >= '0' && ch <= '9') data = data * 10 + ch - '0', ch = getchar();//搜索需要的字符
	return data * p;
}
inline int ReadPossitive()
{
	char ch; int data = 0;
	ch = getchar();
	while (ch == ' ' || ch == '\n')ch = getchar();
	while (ch != ' ' && ch != '\n' && ch != EOF)
	{
		data = data * 10 + ch - '0';
		ch = getchar();
	}
	return data;
}
//E-mail 374656045@qq.com
#define MAX 100
#define INFTY (1LL<<32)
class solve {
private:
    ll edge[MAX][MAX];
	int n, e;
public:
	solve()
	{
		initial();
		Floyd();
		bool negative = false;
		forup(i, 0, n)
			if (edge[i][i] < 0)negative = true;//任意两点间如果存在负环，则两点间最小成本可以无限小，因此无法定义最短路径。
		//用弗洛伊德算法判断时只需判断edge[i][i]是否为负数就可以了，edge[i][i]表示多次插点后的最小成本，也表示去外面转一圈回来后的权值.
		//将edge[i][i]初始值设置为0可以加速判断的过程。只需一次Floyd算法即可判断。环上有多少个点，edge[i][i]就会被计算多少次，插点法的概念
		if (negative)printf("NEGATIVE CYCLE\n");
		else
		{
			forup(i, 0, n)
			{
				forup(j, 0, n)
				{
					if (j)printf(" ");
					if (edge[i][j] != INFTY)
						printf("%lld", edge[i][j]);
					else
						printf("INF");
				}
				printf("\n");
			}
		}
	}
	void initial()
	{
		n = ReadPossitive(); e = ReadPossitive();
		forup(i, 0, n)
			forup(j, 0, n)
			edge[i][j] = ((i == j) ? 0 : INFTY);
		int u, v, value;
		forup(i, 0, e)
		{
			u = ReadPossitive(); v = ReadPossitive(); value = readnum();
			edge[u][v] = value;//无向图不用ver[v][u]在连边。
		}
	}
	void Floyd()
	{
		forup(k, 0, n)
			forup(i, 0, n)
		{
			if(edge[i][k]!=INFTY)//小优化，插点失败就跳过
				forup(j, 0, n)
			{
				if (edge[k][j] != INFTY)
					if (edge[i][j] > edge[i][k] + edge[k][j])//避免使用min函数，用布尔运算代替赋值提高速度
						edge[i][j] = edge[i][k] + edge[k][j];
			}
		}
	}

};
int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0);//慎用，cin和scanf混用会导致非MSC++WA
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve solution;
#ifdef DEBUG
	fclose(stdin);//关闭文件 
	fclose(stdout);//关闭文件 
#endif
	return 0;

}


