#include<stdio.h>
#include <stdlib.h>

int main(void)
{
	int s_length, i,j, q_length,C = 0;
	scanf("%d", &s_length);
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
		for(j=0;j<s_length;j++){
			if(s[j]==q[i]){
				C++;
				break;
			}
		}
	}
	printf("%d\n",C);
	return(0);
}
