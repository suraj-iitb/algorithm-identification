#include<stdio.h>
int a[105];
int main(voide){

  int n;
  scanf("%d",&n);
 
  for(int i=0;i<n;i++)
    scanf("%d",&a[i]);

  for(int i=0;i<n;i++){
    int x=a[i];
    int j=i-1;

    while(j>=0&&a[j]>x){
      a[j+1]=a[j];
       j--;
    }

  a[j+1]=x;
    for(int i=0;i<n;i++)
      if(i==0) printf("%d",a[i]);
      else printf(" %d",a[i]);
    
      printf("\n");
    }
 
    return 0;

  }
