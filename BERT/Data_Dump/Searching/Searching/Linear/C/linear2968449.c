#include<stdio.h>
int main(){
  int i,j,count=0,n,q,key;
  int a[10000],b[10000];
  scanf("%d",&n);
  for(i=0;i<n;i++){
  scanf("%d",&a[i]);
}
scanf("%d",&q);
for(i=0;i<q;i++){
scanf("%d",&b[i]);
}
for(j=0;j<q;j++){
  i=0;
  key=b[j];
  a[n]=key;
while(1){
  if(a[i]==b[j]){
    count++;
    break;
  }
  i++;
  if(i==n){
    break;
  }
}
}
printf("%d\n",count);
return 0;
}
