#include <stdio.h>
#define S 10000
#define T 500

int s[S];
int t[T];

int main(){
  int i,j,n,q;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
 
  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
    for(j=0;j<i;j++){
      if(t[j]==t[i]) i--;
    }
  }  
  printf("%d\n",IinearSearch(n,q));
  return 0;
}

int IinearSearch(int n,int q){
  int i,j,key,c=0;
  for(i=0;i<q;i++){
    key=t[i];
    for(j=0;j<n;j++){
      if(key==s[j]){
	c++;
	break;
      }
    }
  }
  return c;
}
