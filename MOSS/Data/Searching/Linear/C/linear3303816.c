#include<stdio.h>
#define N 10000
#define Q 500
int main()
{
  int s[N],t[Q];
  int i,q,n,l=0,j;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
    scanf("%d",&s[i]);
    }
    scanf("%d",&q);

  for(i=0;i<q;i++){

    scanf("%d",&t[i]);
    for(j=0;j<n;j++){
      if(s[j]==t[i]){
        l++;
        break;
      }
    }
  }

  printf("%d",l);
  printf("\n");
    return 0;
}

