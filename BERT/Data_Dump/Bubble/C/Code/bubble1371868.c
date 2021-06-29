#include <stdio.h>

int main(){
	int c=0,flag,i=0,j,tmp,data[100],n;
	scanf("%d",&n);
	while(i != n){
		scanf("%d",&data[i]);
		i++;
	}
	flag = 1;
    while(flag){
   		flag = 0;
		for(j=n-1; j>=1; j--){
			if(data[j] < data[j-1]){
				tmp = data[j];
				data[j] = data[j-1];
				data[j-1] = tmp;
				flag = 1;
				c++;
			}
		}
	}
	for(i=0;i<n;i++){
		i != n-1 ? printf("%d ",data[i]):printf("%d\n",data[i]);
	}
	printf("%d\n",c);
	return 0;
}
