#include<stdio.h>

int main(){

 int a[10000],b[10000],n,m,i,j;
 int count=0;


  scanf("%d",&n);
  for(i=0;i<n;i++){
  scanf("%d",&a[i]);}

  scanf("%d",&m);
  for(j=0;j<m;j++){
   scanf("%d",&b[j]);}


  for(j=0;j<m;j++){
    for(i=0;i<n;i++){
if(a[i]==b[j]){count++;
break;
}
}
}
 printf("%d\n",count);
 return 0;
}
