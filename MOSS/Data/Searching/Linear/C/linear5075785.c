#include <stdio.h>
#define N 10000
#define L 500
int linearsearch(int,int*,int);

int main(){
  int s[N],t[L];
  int n,m;
  int i,count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){scanf("%d",&s[i]); }
  
  scanf("%d",&m);
  for(i=0;i<m;i++){scanf("%d",&t[i]); }

  for(i=0;i<m;i++){
    if(linearsearch(t[i],s,n) )count++;

  }
  printf("%d\n",count);



  
return 0;
}

int linearsearch(int key,int s[],int n){
  int j;

  for(j=0;j<n;j++){if(key==s[j])break; }
  
  if(j<n)return 1;
  else return 0;
}

