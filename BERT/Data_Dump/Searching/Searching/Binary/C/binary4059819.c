#include <stdio.h>

int binarysearch(int*,int,int);

int main(){
  int ns,nt,i=0,x,count=0;

  scanf("%d",&ns);
  
  int s[ns];
  while(i<ns){
    scanf("%d",&s[i]);
    i++;
  }
  i=0;

  scanf("%d",&nt);

  int t[nt];

  while(i<nt){
    scanf("%d",&t[i]);
    i++;
  }

  i=0;

  for(i=0;i<nt;i++){
    x=binarysearch(s,t[i],ns);
    if(x>=0){
      if(s[x]==t[i]) count++;
    }
  }
  
  printf("%d\n",count);
  return 0;
}
  
int binarysearch(int *s, int t,int ns){
  int not=-1,left=0,right=ns,mid;

  while(left<right){
    mid=(left+right)/2;
    if(s[mid]==t) return mid;

    else if(t<s[mid]) right=mid;

    else left=mid+1;
  }

  return not;
  
}

