#include <stdio.h>
#include <stdlib.h>

int linear(void);

int i,j=0,n,q,*s,*t,aaa;

int main(){

  int cnt=0;
  
  scanf("%d",&n);
  s = malloc(sizeof(int)*(n+1));
  for(i=0;i<n;i++)scanf("%d",&s[i]);

  scanf("%d",&q); 
  t = malloc(sizeof(int)*(q+1));
  for(i=0;i<q;i++)scanf("%d",&t[i]);

  
for(i=0;i<q;i++){
  aaa=linear();
  if(aaa!=-1)cnt++;
  //printf("linear:%d\n",aaa);
 }

 printf("%d\n",cnt);

 free(s);
 free(t);
 return 0;
}


int linear(void){

  s[n]=t[i];
  for(j=0;s[j]!=t[i];j++){
    //printf("s:%d t:%d j:%d n:%d\n",s[j],t[i],j,n);
  }
  
   if(j==n) return -1;
    
  return j;

}

