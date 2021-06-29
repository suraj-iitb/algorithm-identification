#include <stdio.h>
#include <stdlib.h>

int by(void);

int i,n,q,*s,*t,aaa;

int main(){

  int cnt=0;
  
  scanf("%d",&n);
  s = malloc(sizeof(int)*(n+1));
  for(i=0;i<n;i++)scanf("%d",&s[i]);

  scanf("%d",&q); 
  t = malloc(sizeof(int)*(q+1));
  for(i=0;i<q;i++)scanf("%d",&t[i]);

  
for(i=0;i<q;i++){
  aaa=by();
  if(aaa!=-1)cnt++;
  //printf("linear:%d\n",aaa);
 }

 printf("%d\n",cnt);
 
 free(s);
 free(t);

 return 0;
}


int by(void){

  int left=0,right=n,mid;
 
  while(left<right){
    mid = (left+right)/2;
    if(s[mid]==t[i])return mid;
    else if(t[i]<s[mid])right = mid;
    else left = mid + 1;
  }
    
  return -1;

}

