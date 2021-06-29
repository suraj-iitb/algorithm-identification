#include<stdio.h>
int main(){
	int n,i,j,cnt=0;
	int tmp,m,a[101];
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	for(i=0;i<n-1;i++){
		m=i;
		for(j=i;j<=n-1;j++){
			if(a[j]<a[m]){
				m=j;
			}
		}
		if(m!=i)cnt++;
		tmp=a[i];
		a[i]=a[m];
		a[m]=tmp;
	}
	for(i=0;i<n-1;i++)printf("%d ",a[i]);
	printf("%d\n",a[i]);
	printf("%d\n",cnt);
	return 0;
}
