#include <stdio.h>

int main()
{

  int S[10000],T[500],checked[500],n,q,i,j,number_of_coresspond=0;

  scanf("%d",&n);
  for(i = 0 ; i< n ; i++)scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i = 0 ; i < q; i++)scanf("%d",&T[i]);

  for(i = 0; i<q ; i++)
    {
      for(j = 0 ; j <n ; j++)
        {
          if(T[i] == S[j])
            {
              number_of_coresspond++;
              break;
            }
          
        }

    }
  printf("%d\n",number_of_coresspond);
    
  
}