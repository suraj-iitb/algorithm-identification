#include<stdio.h>
#include<limits.h>


int merge_sort(int* begin, int* end){
	if(begin+1>=end) return 0;

	int ret = 0;
	int* mid = begin + (end-begin)/2;
	ret += merge_sort(begin, mid);
	ret += merge_sort(mid, end);
	
	int n = mid - begin, m = end - mid;
	int a[n+1], b[m+1], i, j;
	for(i=0; i<n; i++) a[i] = begin[i];
	for(i=0; i<m; i++) b[i] = mid[i];
	a[n] = b[m] = INT_MAX;
	
	i = j = 0;
	int *c;
	for(c=begin; c<end; c++){
		if(a[i]<b[j]) *c = a[i++];
		else *c = b[j++];
		ret++;
	}
	ret += end - begin;
	return ret;
}


int main(){
	int n;
	scanf("%d", &n);

	int i, a[n];
	for(i=0; i<n; i++) scanf("%d", &a[i]);

	int cnt = merge_sort(a, a+n);
	for(i=0; i<n; i++){
		if(i) putchar(' ');
		printf("%d", a[i]);
	}
	putchar('\n');
	printf("%d\n", cnt/2);
	return 0;
}

