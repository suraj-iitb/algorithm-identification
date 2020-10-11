#include<stdio.h>

int main(void)
{
	int i,j,n,temp,count;
	int a[100];
	int flag = 1;

	scanf("%d",&n);
	for(i = 0;i < n;i++){
		scanf("%d",&a[i]);
	}
        i = 0;
	count = 0;
	while(flag){
		flag = 0;
		for(j = n - 1;j > i;j--){
			if(a[j] < a[j - 1]){
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
				flag = 1;
				count++;
			}
		}
		i++;
	}
	for(i = 0;i < n;i++){
		if(i != 0 && i < n)printf(" ");
		printf("%d",a[i]);
	}
	printf("\n");
	printf("%d\n",count);
        return 0;
}
