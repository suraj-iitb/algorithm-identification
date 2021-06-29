#include <stdio.h>

int binarySearch(int n,int *s,int k){
	int r,l = 0;
	r = n;
	while(r > l+1)
	{
		int m = (r + l)/2;
		if (s[m] > k)
		{
			r = m;
		}
		else 
		{
			l = m;
		}
	}
	
	return s[l] == k;
}

int main(void){
	int n,i,s[100000];
	int cnt = 0;
	scanf("%d",&n);
	for(i = 0;i < n;i++){
		scanf("%d",&s[i]);
	}
	int p,t;
	scanf("%d",&p);
	for(i = 0; i < p; i++){
		scanf("%d",&t);
		cnt += binarySearch(n,s,t);
	}
	
	printf("%d\n",cnt);
	return 0;
}
