#include <stdio.h>

int main(){
    int i, g, n, q, p, flag;
    int count=0;
    flag=0;



    scanf("%d", &n);

    int S[n],key[n];


    for(i=0;i<n;i++){
        scanf("%d", &S[i]);
        key[i]=-1;
        }

    scanf("%d", &q);

    int T[q];

    for(i=0;i<q;i++){
        scanf("%d", &T[i]);
        }

    for(g=0;g<q;g++){
      for(i=0;i<n;i++){
            flag=0;
        for(p=0;p<n;p++){
              if(key[p]==-1)break;
              if(S[i]==key[p]){
                 flag=1;
                 break;
                 }
                }
              if(S[i]==T[g]&&flag==0){
                 key[count]=S[i];
                 count++;
                }
               }
              }

printf("%d\n",count);

return 0;
}

