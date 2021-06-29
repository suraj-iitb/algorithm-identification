#include<stdio.h>
#include <stdlib.h>

int main(void)
{
	int s_length,left=0,mid,i,j, q_length,C = 0;
	scanf("%d", &s_length);
	int right=s_length;
	int *s, *q;
	s = (int *)malloc(sizeof(int) * s_length);
	for(i = 0;i < s_length;i++){
		scanf("%d", &s[i]);
	}
	
	scanf("%d", &q_length);
	
	q = (int *)malloc(sizeof(int) * q_length);
	for(i = 0;i < q_length;i++){
		scanf("%d", &q[i]);
	}
	
	
	for(i=0;i<q_length;i++){
		while(left<right){
			mid=(left+right)/2;
			if(s[mid]==q[i]){
				C++;
				break;
			}
			else if(s[mid]>q[i]){
				right=mid;
			}
			else{
				left=mid+1;
			}
		}
		right = s_length;
				left = 0;
	}
	printf("%d\n",C);
	return(0);
}
