#include <stdio.h>
int main(){
int i,j,n,temp,minj,cnt=0;
scanf("%d",&n);
int a[n];
for(i=0;i<n;++i){
	scanf("%d",&a[i]);
}	
for(i=0;i<n-1;++i){
	minj=i;
	for(j=i;j<n;++j){
		if(a[j]<a[minj]){
			minj=j;
		}
	}
			if(minj!=i){
			    temp=a[minj];
			a[minj]=a[i];
			a[i]=temp;
			cnt++;
		
			}
	
}
for(i=0;i<n;++i){
	printf("%d",a[i]);
	if(i==n-1){
		putchar('\n');
	}
	else 
	putchar(' ');
}
printf("%d\n",cnt);
return 0;
} 
