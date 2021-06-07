#include<stdio.h>
#define max 100000
int f[max];
int search(int key,int n){
  int le=0,ri,mid;
  ri=n;
  while(le<ri){
    mid=(le+ri)/2;
    if(key == f[mid])
      return 0;
    if(key>f[mid])
      le=mid+1;
    else if(key<f[mid])
      ri=mid;
  }
  return 1;  
}


main(){
  int i,j,n1,n2,s[max],count=0; 
  scanf("%d",&n1);
  for(i=0;i<n1;i++)
    scanf("%d",&f[i]);
  scanf("%d",&n2);
  for(i=0;i<n2;i++)
    scanf("%d",&s[i]);
  
  
  
  
  for(i=0;i<n2;i++)
    if(search(s[i],n1)==0)
      count++;
  printf("%d\n",count);
  return 0;
}
