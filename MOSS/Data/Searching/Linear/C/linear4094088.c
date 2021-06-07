#include<stdio.h>
    #define N 10000
    int main(void)
    {
      int i,j,s_total,t_total,k=0;
      int S[N],T[N];
      scanf("%d",&s_total);
      for(i=0;i<s_total;i++){
        scanf("%d",&S[i]);
      }
      
      scanf("%d",&t_total);
      for(j=0;j<t_total;j++){
        scanf("%d",&T[j]);
      }
     for(j=0;j<t_total;j++){
      for(i=0;i<s_total;i++){  
          if(S[i]==T[j]){
        	k++;
        	break;
          }
        }
      }
      printf("%d\n",k);
      return 0;
    }
    
      

