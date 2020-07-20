#include<stdio.h>
#include<math.h>
int main(){
	int n,r,c=0;
	int A[100];
	int flag = 1;
	int i = 0;
	int temp;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	i=0;
	while (flag){
		flag = 0;
		for(int j = n-1; j>=i+1 ;j--){
			if (A[j] < A[j-1]){
				temp=A[j];
				A[j]=A[j-1];
				A[j-1]=temp;
				flag = 1;
				r++;
			}

		}
		i++;
	}
	for(i=0;i<n;i++){
		if(c==1){
			printf(" ");
		}
		printf("%d",A[i]);
		c=1;
	}
	printf("\n%d\n",r);
	return 0;
}
