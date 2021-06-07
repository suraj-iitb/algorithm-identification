#include <stdio.h>

int main(){
     int i, g, n, q, left, right, mid, flag;
     int count=0;

    scanf("%d", &n);

    int S[n];

    for(i=0;i<n;i++){
         scanf("%d", &S[i]);
         }

    scanf("%d", &q);

     int T[q], key[q];

    for(i=0;i<q;i++){
         scanf("%d", &T[i]);
         key[q] = -1;
         }

     
for(i=0;i<q;i++){
    for(g=0;g<q;g++){
          if(key[g]==-1)break;
          if(T[i]==key[g]){
             flag=1;
             break;
             }
            }
            flag=0;
            left=0;
            right=n;
     while(left<right){
              if(flag==1)break;
              mid = (left + right)/2;
              if(S[mid]==T[i]){
                  count++;
                  break;
                 }
              else if(T[i]<S[mid]) right = mid;
              else left = mid + 1;
             }
      }


printf("%d\n",count);
           
return 0;
}
