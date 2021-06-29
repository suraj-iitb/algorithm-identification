#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int s_length, q_length, i, z = 0, x, j;
	int *s, *q;
	scanf("%d", &s_length);
	s = (int *)malloc(sizeof(int) * s_length);
	
	for(i = 0;i < s_length;i++){
		scanf("%d", &s[i]);
	}
	
	scanf("%d", &q_length);
	
	q = (int *)malloc(sizeof(int) * q_length);
	
	for(x = 0;x < q_length;x++){
		scanf("%d", &q[x]);
	}
		
	for(i = 0;i < q_length;i++){
		for(j = 0;j < s_length;j++){
			if(q[i] == s[j]){
				z++;
				break;
			}
		}
		
	}
	
	printf("%d\n", z);
			
	return 0;
	
	
}
