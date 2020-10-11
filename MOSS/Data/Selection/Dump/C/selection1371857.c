#include <stdio.h>

int main(){
	int tmp,i=0,j,data[100],n,c=0,minj;
	scanf("%d",&n);
	while(i!=n){
		scanf("%d",&data[i]);
		i++;
	}

	for(i=0;i<=n-1;i++){
		minj = i;
		for(j=i;j<=n-1;j++){
			if(data[j] < data[minj]){
				minj = j;
			}
		}
		if(data[i] != data[minj])c++;
		tmp = data[i];
		data[i] = data[minj];
		data[minj] = tmp;
	}
	for(i=0;i<=n-1;i++){
		i <n-1 ? printf("%d ",data[i]):printf("%d\n",data[i]);
	}
	printf("%d\n",c);
	return 0;
}
