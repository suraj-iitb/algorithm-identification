#include<stdio.h>
#include <stdlib.h>
int g_s_length;
void swap(int *i, int *j);
int main(void)

{
	int s_length, i,j,t,c,times = 0;
	scanf("%d", &s_length);
	g_s_length = s_length;
	int *s;
	s = (int *)malloc(sizeof(int) * s_length);
	for(i = 0;i < s_length;i++){
		scanf("%d", &s[i]);
	}
	
	for(i = 0;i < g_s_length-1;i++){
		for(j = g_s_length-1;j >= i+1;j--){
			if(s[j]<s[j-1]){
				swap(&s[j], &s[j-1]);
				times++;
			}
		}
	}
	for(i = 0;i < s_length;i++){
		if(i == 0){
			printf("%d", s[i]);
		}else{
			printf(" %d", s[i]);
		}
	}
	printf("\n");
	printf("%d\n", times);
	return 0;
}

void swap(int *i, int *j){
	int iti;
	iti = *i;
	*i = *j;
	*j = iti;
}
