#include<stdio.h>

int search(int a[], int n, int key)
{
	int i = 0;
	a[n] = key;
	while(a[i] != key) i++;
	return i != n;
}
int main(void)
{
	int n, q, i, key;
	int c = 0;
	
	scanf("%d", &n);
	
	int a[n];
	
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	scanf("%d", &q);
	
	for(i = 0; i < q; i++)
	{
		scanf("%d", &key);
		if(search(a, n, key)) c++;
	}
	
	printf("%d\n", c);
	return 0;
}
