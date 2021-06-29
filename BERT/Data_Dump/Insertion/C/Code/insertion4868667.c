#include<stdio.h>
#include<stdlib.h>
#define N 8


void print_A(int a[],int n){
 int i ;
 for ( i = 0 ;i<n;i++) {
  if (i!=n-1 )printf("%d ",a[i]);
  else printf("%d",a[i]);
 }
 printf("\n");
 return ;
}

void insertsort(int a[], int n){
 print_A(a,n); int i;int j ;
 for(i = 1;i<n;i++){
  int temp=a[i],j=i-1;
  while(j>=0&&a[j]>temp){
   a[j+1]=a[j];
   j--;
  }
  a[j+1]=temp; print_A(a,n);
 }
 
 return ;
}
 
 main()
{
 int i,n,a[100];
 scanf("%d",&i);
 for(n=0;n<i;n++)
 {
  scanf("%d",&a[n]);
 }
 insertsort(a,n);
 return 0;
}
