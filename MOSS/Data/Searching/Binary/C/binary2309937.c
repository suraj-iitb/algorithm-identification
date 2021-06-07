#include <stdio.h>

int A[1000000],n;

int binarySearch(int key){
	int lef = 0;
	int rig = n;
	int mid;
	while(lef < rig){
		mid=(lef+rig)/2;
		if(key==A[mid]) return 1;
		if(key>A[mid]) lef=mid+1;
		else if (key<A[mid]) rig=mid;
			}
	return 0;
}

int main(){
	int i,q,k,sum=0;
scanf("%d",&n);
for(i=0;i<n;i++)
{
	scanf("%d",&A[i]);
}

scanf("%d",&q);
for(i=0;i<q;i++){
	scanf("%d",&k);
	if(binarySearch(k)) sum++;
}
printf("%d\n",sum);

return 0;
}
