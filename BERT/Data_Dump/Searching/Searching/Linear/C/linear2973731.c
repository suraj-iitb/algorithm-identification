




#include <stdio.h>
int search(int S[],int n,int t){
  int i=0;
  S[n]=t;
  while (S[i]!=t)i++;
  return i!=n;
}


int main(){
  int n,i,ans=0,S[10001],q,t;

  scanf("%d",&n);

  for(i=0;i<n;i++)
        scanf("%d",&S[i]);

  scanf("%d",&q);

   for(i=0;i<q;i++){
          scanf("%d",&t);
          if(search(S,n,t))
              ans++;

     }

printf("%d\n",ans);
  return 0;
}

