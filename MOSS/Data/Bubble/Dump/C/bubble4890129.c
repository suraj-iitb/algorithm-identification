#include <stdio.h>
int main(int argc, char *argv[]) {
	int str[200005],n;
	int sum=0,i,j,k,temp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&str[i]);
	
	for(i=0;i<n-1;i++) {
		for(j=0; j<n-i-1;j++){
			if(str[j]>str[j+1]) {
				temp = str[j];
				str[j] = str[j+1];
				str[j+1] = temp;
				sum++;
			}
		}
	}
	
	for(k=0;k<n-1;k++){
		printf("%d ",str[k]);
	}	
	printf("%d\n",str[k]);
	printf("%d\n",sum);
	return 0;
}
