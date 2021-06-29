#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(void){
    int i,j,k,n;
    scanf("%d", &n);
    int a[n];
    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    int min_index, count=0;
    for(i=0; i<n-1; i++){
        min_index = i;
        for(j=i+1; j<n; j++){
            if(a[min_index]>a[j]){
                min_index = j;
            }
        }
        if(min_index!=i){
            count++;
        }
        k = a[min_index];
        a[min_index] = a[i];
        a[i] = k;
    }

    for(i=0; i<n; i++){
        if(i)printf(" ");
        printf("%d", a[i]);
    }

    printf("\n%d\n", count);

    return 0;

}
