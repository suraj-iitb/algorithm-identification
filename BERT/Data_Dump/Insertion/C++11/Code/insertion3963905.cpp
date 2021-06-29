# include <iostream>
# include <cstdio>
using namespace std;
int main(void)
{
	int n,a[100],j;
	scanf("%d",&n);
	for(int i = 0;i < n;i++) scanf("%d",&a[i]);
	for(int i = 0;i < n;i++)
	{
		int tem = a[i];
		for(j = i-1;j >= 0;j--)
		{
			if(tem >= a[j]) break;
			a[j+1] = a[j];
		}
		a[j+1] = tem;
		for(int w = 0;w < n;w++) printf("%d%c",a[w],(w == n-1?'\n':' '));
	}
	return 0;
}
