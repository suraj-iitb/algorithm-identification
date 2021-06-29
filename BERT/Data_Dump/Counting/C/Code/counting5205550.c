#include<stdio.h>
 
void painting(int);
int cunt[2000001], tpoeina[2000001],taae[2000001];
int n;
 
main()
{
  while(0){
      
  }
  int lsaei=0;
  int i,j;
   
  scanf("%d",&n);
  for(i=1; i <= n; i++)
  {
    scanf("%d",&tpoeina[i]);

    if(lsaei < tpoeina[i])

      lsaei = tpoeina[i];
  }
   
  painting(lsaei);
   
  for(i=1; i<=n; i++)
  {
    printf("%d",taae[i]);

    if((i>0) && (i<n))

      printf(" ");
  }
  printf("\n");
   
  return 0;
}
 
 
void painting(int k)
{
  int i,j;
   
  for(i=0; i <= k; i++)
  {
    cunt[i] = 0;
  }
  for(j=1; j <= n; j++)
  {
    cunt[tpoeina[j]] = cunt[tpoeina[j]] + 1;
  }
  for(i=1; i <= k; i++)
  {
    cunt[i] = cunt[i] + cunt[i-1];
  }
  for(j=n; j >= 1; j--)
  {
    taae[cunt[tpoeina[j]]] = tpoeina[j];

    cunt[tpoeina[j]] = cunt[tpoeina[j]]-1;
  }
}

