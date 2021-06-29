#include<stdio.h>

int main(){

  int i,j,n,s,count=0,mini,a[101];


  //load N
  scanf("%d",&n);
  //load number
  for(i=1;i<=n;i++){
    scanf("%d",&a[i]);
  }
  //Algorithm
  for(i=1;i<=n;i++){
    mini=i;
    for(j=i;j<=n;j++){
      if(a[j]<a[mini]){
	mini=j;
      }
    }
      //swap
      s=a[i];
      a[i]=a[mini];
      a[mini]=s;
      //count
      if(a[i]!=a[mini]) count++;
  }

  //print
  for(i=1;i<=n;i++){
    printf("%d",a[i]);
    if(i!=n){
      printf(" ");
    }
  }

  printf("\n");
  printf("%d\n",count);

  return 0;
}
