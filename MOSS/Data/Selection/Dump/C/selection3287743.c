#include<stdio.h>
int main(){
  int b,c,d,i,j,k,e,f=0,g=0;

  scanf("%d",&b);
  int a[b];
  for(k=0;k<b;k++){
    scanf("%d",&a[k]);
  }

  for(i=0;i<b-1;i++){
    c=a[i];
    d=i;
    for(j=i+1;j<b;j++){
      if(a[j]<c){
	c=a[j];
	d=j;
      }
    }
    if(a[i]!=c){
    e=a[i];
    a[i]=a[d];
    a[d]=e;
    f++;
    }
 
  }
   for(k=0;k<b-1;k++){
      printf("%d ",a[k]);
  }
    printf("%d\n",a[b-1]);
    printf("%d\n",f);
    return 0;
}
  

