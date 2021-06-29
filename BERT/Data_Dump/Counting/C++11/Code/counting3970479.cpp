# include <iostream>
# include <cstring>
using namespace std;
int *b,n,*a;
void Count_Sort(int *a,int n)
{
	int c[10001];
	memset(c,0,sizeof(c));
	b = new int [n];
	for(int i = 0;i < n;i++) c[a[i]]++;
	for(int i = 1;i <= 10000;i++) c[i] += c[i-1];
	for(int i = n-1;i >= 0;i--)
	{
		b[c[a[i]]-1] = a[i];
		c[a[i]]--;
	}
}
int main(void)
{
	scanf("%d",&n); a = new int [n];
	for(int i = 0;i < n;i++) scanf("%d",&a[i]);
	Count_Sort(a,n);
	for(int i = 0;i < n;i++) printf("%d%c",b[i],(i == n-1)?'\n':' ');
	return 0;
} 
