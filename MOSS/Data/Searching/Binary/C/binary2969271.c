#include<stdio.h>
int main(){
  int i,j,count=0,n,q,key,l,r,mid;
  int a[100000],b[100000];
  scanf("%d",&n);
  for(i=0;i<n;i++){
  scanf("%d",&a[i]);
}
scanf("%d",&q);
for(i=0;i<q;i++){
scanf("%d",&b[i]);
}
for(j=0;j<q;j++){
  key=b[j];
  a[n]=key;
  l=0;
  r=n;
while(l<=r){
  mid=(l+r)/2;
  if(a[mid]==key){
    count++;
    break;
  }
  else if(a[mid]<key){
    l=mid+1;
  }
  else{
    r=mid-1;
  }
}
}
printf("%d\n",count);
return 0;
}

