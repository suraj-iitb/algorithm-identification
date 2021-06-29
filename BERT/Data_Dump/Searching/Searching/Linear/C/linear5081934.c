    #include<stdio.h>
    #define N 10000
    #define Q 500
    int main ()
   {
     int S[N],T[Q],n,q,i,j,cnt=0;

     scanf("%d",&n);

     for(i=0;i<n;i++)
     {
      scanf("%d",&S[i]);
     }

      scanf("%d",&q);

     for(i=0;i<q;i++)
     {
      scanf("%d",&T[i]);
     }

       if(n>q)
       {
         for(i=0;i<q;i++)
         {
          for(j=0;j<n;j++)
          {
            if(S[j]==T[i])
            {
            cnt++;
            break;
            }
          }
         }
       }else if(n<q)
        {
         for(i=0;i<n;i++)
         {
          for(j=0;j<q;j++)
          {
           if(S[j]==T[i])
           {
           cnt++;
           break;
           }
          }
         }
        }
     printf("%d\n",cnt);
   }
