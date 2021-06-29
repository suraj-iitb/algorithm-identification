#include<cstdio>
#include<functional>
#include<algorithm>
using namespace std;
void func(int);

int main(void)
{
	int n,i,j,a[100],flg,cnt;
	scanf("%d",&n);
	for(i=0;i<n;i++)	scanf("%d",&a[i]);
	cnt=0;
	flg=1;
	while(flg==1)	{
		flg=0;
		for(j=n-1;j>0;j--)	{
			if(a[j]<a[j-1])	{
				swap(a[j],a[j-1]);
				cnt++;
				flg=1;
			}
		}
	}
	printf("%d",a[0]);
	for(i=1;i<n;i++)printf(" %d",a[i]);
	printf("\n");
	printf("%d\n",cnt);
	return 0;
}
