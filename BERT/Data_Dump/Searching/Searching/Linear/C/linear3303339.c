#include<stdio.h>
void swap(int *,int*);
void bable(int *,int );
int main() {
	int a[10000], b[10000],an,bn,key = -1,cnt=0,i,j;
	scanf("%d", &an);
	for ( i = 0; i <an; i++)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &bn);
	for (i = 0; i < bn; i++)
	{
		scanf("%d", &b[i]);
	}
	bable(a, an);
	bable(b, bn);
	for ( i = 0; i < bn; i++)
	{
		for (j = 0; j < an; j++)
		{
			if (a[j] != key) {
				if (b[i] == a[j])
				{
					cnt++;
					key = b[i];
				}
			}
		}
	}
	printf("%d", cnt);
	printf("\n");
	return 0;
}
void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void bable(int *x, int y) {
	int i,j;
	for ( i = 0; i < y-1 ; i++)
	{
		for ( j = y-1; j > i; j--)
		{
			if (x[j -1] > x[j] )
			{
				swap(&x[j - 1], &x[j]);
			}
		}
	}

}
