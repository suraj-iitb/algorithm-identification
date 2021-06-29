#include <stdio.h>
int main(){
	int a,i=0,j,k,data[100],n;
	scanf("%d",&n);
	while(i != n){
		scanf("%d",&data[i]);
		i++;
	}
	for(k=0;k<n;k++){
		k != n-1 ? printf("%d ",data[k]):printf("%d\n",data[k]);
	}

	for(i=1;i<=n-1;i++){
		a = data[i];
		j = i - 1;
		while(j >= 0 && data[j] > a){
			data[j+1] = data[j];
			j--;
		}
		data[j+1] = a;
		for(k=0;k<n;k++){
			k != n-1 ? printf("%d ",data[k]):printf("%d\n",data[k]);
		}
	}		
	return 0;
}
