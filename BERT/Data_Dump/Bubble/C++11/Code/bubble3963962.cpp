# include <iostream>
using namespace std;
int main(void)
{
	int n,a[100],ans = 0;
	scanf("%d",&n);
	for(int i = 0;i < n;i++) scanf("%d",&a[i]);
	for(int i = 0;i < n-1;i++)
	{
		for(int j = n-1;j >= i+1;j--)
		{
			if(a[j] < a[j-1])
			{
				swap(a[j-1],a[j]);
				ans++;
			}
		}
	}
	for(int i = 0;i < n;i++) printf("%d%c",a[i],(i == n-1)?'\n':' ');
	printf("%d\n",ans);
	return 0;
}
