#include <stdio.h>
int linearSearch(int S[], int n, int key);

int main(void)
{
    int i, sum=0, n, q;
    
    scanf("%d", &n);
    
    int S[n];
    for(i=0; i<n; i++)
    {
        scanf("%d", &S[i]);
    }
    
    scanf("%d", &q);
    
    int T[q];
    for(i=0; i<q; i++)
    {
        scanf("%d", &T[i]);
        if(linearSearch(S, n, T[i])==1) sum++;
    }
    
    printf("%d\n", sum);
	
	return 0;
}

int linearSearch(int S[], int n, int key)
{
	int i=0;
	S[n]=key;
	while (S[i]!=key) i++;
	if(i!=n) return 1;
	else return 0;
}

