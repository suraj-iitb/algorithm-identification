#include<stdio.h>
#define MAXs 10000
#define MAXt 500

int linearSearch(int S[], int T, int n)
{
	int i = 0;
	int key = T;
	while(S[i] != key) {
		i++;
		if(i == n)
			return 0;
	}
	return 1;
}

int main()
{	
	int i;
	int s, q;
	int count = 0;
	int S[MAXs], T[MAXt];

	scanf("%d", &s);
	for(i = 0; i < s; ++i)
		scanf("%d", &S[i]);

	scanf("%d", &q);
	for (i = 0; i < q; ++i)
	{
		scanf("%d", &T[i]);
		count += linearSearch(S, T[i], s);
	}

	printf("%d\n", count);
    return 0;
}
