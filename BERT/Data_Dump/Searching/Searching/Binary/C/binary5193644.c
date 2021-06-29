#include<stdio.h>

int main(void){
	int n,q,count=0;
	
	scanf("%d",&n);
	int S[n];//Sの要素は昇順に整列されている
	for(int i=0;i<n;i++)
	scanf("%d",&S[i]);
	scanf("%d",&q);
    int T[q];//Tの要素は互いに異なる
	for(int i=0;i<q;i++)
	scanf("%d",&T[i]);
	for(int i=0;i<q;i++){
		int right=n,left=0,mid;
		while(left<right){
			mid=(right+left)/2;
			if(T[i]==S[mid]){
				count++;
				break;
			}
			if(T[i]>S[mid])
			left=mid+1;
			else if(T[i]<S[mid])
			right=mid;
		}
	}
	printf("%d\n",count);
	return 0;
}

