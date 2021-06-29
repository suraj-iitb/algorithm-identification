#include <stdio.h>
#include <stdlib.h>

int n;
int lse(int,int S[]);

int main()
{
    /*n,qを変数宣言*/
    int q,i,j,count=0;
    /*n,q,S,Tの値代入*/
    scanf("%d",&n);
    int S[n];
    for(i=0;i<n;i++){
        scanf("%d",&S[i]);
    } 
    scanf("%d",&q);
    int T[q];
    for(i=0;i<q;i++){
        scanf("%d",&T[i]);
    } 
    
    for ( i = 0; i < q; i++)
    {
      count=count+lse(T[i],S);
    }
    printf("%d\n",count);
    
    return 0;
}

  /*線形探索*/
int lse(int key,int S[]){
   int i;
   for ( i = 0; i < n; i++)
   {
       if(key==S[i]){
           return 1;
       }
   }
   return 0;
    
}

