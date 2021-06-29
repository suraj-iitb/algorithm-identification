#include <cstdio> 
#include <iostream>
using namespace std;
const int  maxn = 2000007; 
typedef unsigned short uc;
const int M = 10001;
int b[maxn], c[M+3];
#define Rep(i, a, b) for (int i = a; i <= b; ++i)
// 计数排序适用于-数字很多，但范围比较集中的 数据 

int  main()
{
    int n, x; scanf("%d", &n);
    Rep(i, 0, M)  c[i] = 0;
    for (int i = 0; i < n; i++)
	{ 
        scanf("%d", &x);
        c[x]++;
    }

	for (int i = 0, j = 0; i < M; ++i)
	{// M + k
		if (c[i])
		{
			for (int k = 0; k < c[i]; ++k)
			{
				b[j++] = i;
			}
		}
	}
	
	for (int i = 0; i < n; i++)
        printf("%d%c", b[i], i==n-1 ? '\n' : ' ');
 
	return 0;
}
// 7 2 5 1 3 2 3 0
// 8 4 5 0 3 1 5 0 5 
