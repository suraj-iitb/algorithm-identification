#include <stdio.h>
#include <stdlib.h>

unsigned long long s[100000];

int binary_search(unsigned long long val_t,unsigned long long min,unsigned long long max)
{
	int i = min;
	int j = max;
	int p;
	while(i<=j){
		p = (i+j)/2;
		if(s[p] > val_t){
			j = p - 1;
		}
		else if(s[p] < val_t){
			i = p + 1;
		}
		else if(s[p] == val_t){
			return 1;
		}
	}
	return 0;
}
int main()
{
	unsigned long long i;
	unsigned long long n;
	unsigned long long q;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++){
		scanf("%lld",&s[i]);
	}

	scanf("%lld",&q);
	unsigned long long t[q];

	for(i=0;i<q;i++){
		scanf("%lld",&t[i]);
	}

	unsigned long long cnt=0;
	for(i=0;i<q;i++){
		if(binary_search(t[i],0,n) == 1){
			cnt++;
		}
	}

	printf("%lld\n",cnt);
	return 0;	
}
