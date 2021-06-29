#include <stdio.h>

int main(void)
{
int n;
int i,j;
int a[101];
int temp;
int x=0;
scanf("%d",&n);
for(i=0;i<n;i++){
	scanf("%d",&a[i]);
	
}
for(i=0;i<n;i++){
	for(j=n-1;j>i;j--){
		if(a[j]<a[j-1]){
			temp=a[j-1];
			a[j-1]=a[j];
			a[j]=temp;
x++;
		}
		
		
		
		
		
		
		
		
		
		
		
		
	}
	
	
	
	
	
	
	
	
	
}
for(i=0;i<n;i++){
	
	printf("%d",a[i]);
	if(i!=n-1){
		
		printf(" ");
		
	}
	
	
	
}
printf("\n");
printf("%d\n",x);
	return 0;
}
