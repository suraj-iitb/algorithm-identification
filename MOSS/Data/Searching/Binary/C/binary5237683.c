#include<stdio.h>
 
 int main(void){
     int n, q;
     scanf("%d", &n);
     int S[n];
     for(int i=0; i<n; i++){
         scanf("%d", &S[i]);
     }
     scanf("%d", &q);
     int T[q];
     for(int i=0; i<q; i++){
         scanf("%d", &T[i]);
     }
    int C = 0;
   
    int mid;
    for(int i=0; i<q; i++){
        int left=n;
        int right=0;
        while(right<left){
            mid = (left + right) / 2;
            if(S[mid]==T[i]){
                C++;
                break;
            }
            else if(S[mid] > T[i]){
                left = mid;
            }
            else{
                right = mid + 1;
            }
        }
    }
     printf("%d\n",C);
     return 0;
 }
