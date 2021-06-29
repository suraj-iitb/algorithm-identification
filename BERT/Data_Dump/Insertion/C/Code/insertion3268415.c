#include<stdio.h>
#define N 100
void insertionSort(int *,int);
int main()
{
   int n,i;
   int a[N];
   scanf("%d",&n);
   for(i=0;i<n;i++)
   scanf("%d",&a[i]);
   insertionSort(a,n);
   return 0;
}
void insertionSort(int *a,int n){
  int i,j,x=0,k;
  for(i=0;i<n;i++){
    x=a[i];
    j=i-1;
    while(j>=0&&a[j]>x){
	a[j+1]=a[j];
	j--;
	a[j+1]=x;
      }
    for(k=0;k<n;k++){
	if(k>0)printf(" ");
	printf("%d",a[k]);
      }
    printf("\n");
  }
}
      
   
	 
   
   

