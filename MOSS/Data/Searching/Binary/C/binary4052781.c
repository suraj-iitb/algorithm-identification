#include<stdio.h>

int search(int s[],int n,int t)
{
  int lef=0,rig=n,mid;

  while(lef<rig){
    mid=(lef+rig)/2;
    if(s[mid]==t) return 1;
    
    if(s[mid]>t){
      rig=mid;
    }else{
      lef=mid+1;
    }
  }
  return 0;
  
}
  

int main(){

  int i,n,s[100001],q,t,count=0,flag;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t);
    flag=search(s,n,t);
    if(flag==1){
      count++;
      flag=0;
    }
  }

  printf("%d\n",count);
  
  return 0;
}

