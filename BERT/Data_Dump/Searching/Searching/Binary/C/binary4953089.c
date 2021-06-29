#include <stdio.h>
#define N 1000000

int n, S[N];

bS(int key)
{
    int l = 0;
    int r = n;
	
	while(l<r)
	{
        int m = (l + r) / 2;
		
		if(S[m] == key)
		{
			return 1;
		}
		else if( key < S[m])
		{
			r = m;
		}
		
        else
		{
			l = m + 1;
		}
	}
    return 0;
}
	
int main()
{
	int q;
	int key;
	int i, b, c=0;
	
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
	{
		scanf("%d", &S[i]);
	}
	
	scanf("%d", &q);
	
	for(i=0; i<q; i++)
	{
		scanf("%d", &key);
		
		b=bS(key);
		
		if(b==1)
		{
			c++;
		}
	}
	printf("%d\n",c);
	
	return 0;
}
