#include <stdio.h>
#define MAX 10000

int main(){
	int i,j;
	int n1,n2,cnt;
	int num1[MAX],num2;
	
	scanf("%d",&n1);
	for(i=0;i<n1;i++){
		scanf("%d",&num1[i]);
	}
	
	cnt = 0;
	scanf("%d", &n2);
	while(n2--){ //インクリメントを後置に変更
		scanf("%d", &num2);
		for(j = 0; j < n1; ++j) {
			if(num1[j] == num2) {
			++cnt;
			
			break;
			}
		}	
	}
  	printf("%d\n", cnt);
 	return 0;
}
