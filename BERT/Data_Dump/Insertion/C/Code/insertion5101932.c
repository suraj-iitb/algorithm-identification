#include <stdio.h>
int main(){
int n;
scanf("%d",&n);
int a[n];
int temp;
int i=0;
int j;
for(i=0;i<n;++i){
	scanf("%d",&a[i]);
}
for(i=1;i<n;++i){
for(j=0;j<n;++j){
	printf("%d",a[j]);
	if(j!=n-1)
	putchar(' ');
	if(j==n-1)
	putchar('\n');
}	
j=i-1;
temp=a[i];
while(j>=0&&a[j]>temp){
	a[j+1]=a[j];
	j--;
}
a[j+1]=temp;	
}
for(j=0;j<n;++j){
	printf("%d",a[j]);
	if(j!=n-1)
	putchar(' ');
	if(j==n-1)
	putchar('\n');
}	
return 0;
} 
