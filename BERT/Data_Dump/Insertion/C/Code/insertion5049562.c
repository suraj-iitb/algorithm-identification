#include<stdio.h>
    int main(){
      int a, i, j, k, m, key;
        int n[100];
        scanf("%d", &a);
        for(i = 0;i < a;i++){
          scanf("%d", &n[i]);
        }
        for(j = 1; j <= a; j++){
                for(m = 0; m < a; m++){
                    if(m == a-1){
                        printf("%d",n[m]);
                    }
                    else{
                        printf("%d ",n[m]);
                    }
                }
                printf("\n");
                key = n[j];
                k = j-1;
                for(; n[k] > key && k >= 0;k--){
                        n[k+1] = n[k];
                }
                n[k+1] = key;
        }
        return 0;
    }
