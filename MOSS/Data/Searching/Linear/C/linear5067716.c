#include <stdio.h>
#define MAX 10000

int liner(int);

int main()
{
  int n,q,i,j,count=0;

  int s[MAX],t[MAX];

  scanf("%d",&n);

  for(i = 0;i < n;i++){

    scanf("%d",&s[i]);

  }

  scanf("%d",&q);

  for(i = 0;i < q;i++){

    scanf("%d",&t[i]);

  }

  for(j = 0; j <= q - 1;j++){

  for(i = 0;i <= n - 1;i++){

    if(t[j] == s[i]){

     count++;

     break;

   }

  }
}



printf("%d\n",count);

return 0;
}

