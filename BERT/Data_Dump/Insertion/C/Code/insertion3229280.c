#include<stdio.h>

int main(){
    int n, a[100], i, j, v, k;

    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++){
        v = a[i];
        j = i -1;
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        printf("%d", a[0]);
        for(k = 1; k < n; k++){
            printf(" %d", a[k]);
        }
        printf("\n");
    }

   return 0;

}
