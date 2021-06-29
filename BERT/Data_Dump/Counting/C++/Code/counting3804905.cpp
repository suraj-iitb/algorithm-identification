#include"iostream"
using namespace std;
void countingsort(int a[],int b[],int k,int n)
{
	int i,j;
	int*c=new int[k + 1];
	for (i = 0; i <= k; ++i)
		c[i] = 0;
	for (j = 1; j <= n; ++j)
		++c[a[j]];
	for (i = 1; i <= k; ++i)
		c[i] = c[i] + c[i - 1];
	for(j=n;j>=1;--j)
	{
		b[c[a[j]]] = a[j];
		--c[a[j]];
	}
	cout << b[1];
	for (i = 2; i <= n; ++i)
		cout << ' ' << b[i];
	cout << endl;
}
int main()
{
	int n;
	cin >> n;
	int* a = new int[n + 1];
	int* b = new int[n + 1];
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	int max = a[1];
	for (int i = 1; i <= n; ++i)
		if (a[i] > max)max = a[i];
	countingsort(a, b,max,n );
	return 0;
}
