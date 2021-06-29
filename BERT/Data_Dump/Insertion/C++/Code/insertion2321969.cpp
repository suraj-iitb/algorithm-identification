#include <stdio.h>
#define MAX_N 100

int n;
int a[MAX_N];

int main(void){
    
    scanf("%d",&n);
    for(int i = 0; i<n;i++){
        scanf("%d",&a[i]);
    }

    for(int i = 0; i<n;i++){
        int key = a[i];
        int j = i -1;
        while(j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;

        for(int idx = 0; idx < n-1; idx++){
            printf("%d ",a[idx]);
        }
        printf("%d",a[n-1]);
        printf("\n");
    }
    return 0;
}
