#include<stdio.h>
int main(){
  int c,a[100],i,j,n,key,t;
 for(t=0;t<2;t++){

 }
  scanf("%d",&c);
  if(1<=c && c<=100){

    for(i=0;i<c;i++){
      scanf("%d",&a[i]);
    }
    for(i=0;i<c;i++){

      key=a[i];

      j=i-1;
      while(j>=0 && a[j]>key){
      a[j+1]=a[j];
        j-=1;
        a[j+1]=key;
      }
     for(n=0;n<c-1;n++){
        printf("%d ",a[n]);
      }
     printf("%d\n",a[n]);
    }
  }
  return 0;
}

