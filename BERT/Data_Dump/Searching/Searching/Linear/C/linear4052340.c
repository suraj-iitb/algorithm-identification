#include <stdio.h>
int s[10000],n,ans=0;

void linearSearch(int a){
  int j=0;
  while(j<n){
    if(s[j]==a){
      ans++;
      break;
    }
    j++;
  }
}

int main(){
  int q,i,pass;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&pass);
    linearSearch(pass);
  }
  printf("%d\n",ans);
  return 0;
}

  



 

