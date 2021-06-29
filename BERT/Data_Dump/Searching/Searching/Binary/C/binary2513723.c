#include<stdio.h>
#define MAXs 100000
#define MAXt 50000

int binarySearch(int S[], int key, int left, int right)
{

	while(left < right) {
		int mid = (left + right) / 2;
		if(S[mid] == key)
			return 1;
		else if(key < S[mid])
			right = mid;
		else
			left = mid + 1;
	}
	return 0;
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
		count += binarySearch(S, T[i], 0, s);
	}

	printf("%d\n", count);
    return 0;
}
