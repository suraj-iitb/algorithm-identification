#include <stdio.h>
int main(){
	int i,j,minj,n,a[100],tmp,cnt=0,k;
	
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	
	for(i=0;i<n;i++){
		minj=i;
		for(j=i;j<n;j++){
			if(a[j]<a[minj]){
				minj=j;
			}
		}
		k=a[minj];
		tmp=a[i];
		a[i]=a[minj];
		a[minj]=tmp;
		if(k!=a[minj]) cnt++;
	}
	
	for(i=0;i<n-1;i++) printf("%d ",a[i]);
	
	printf("%d\n%d\n",a[n-1],cnt);
	
	return 0;
}
