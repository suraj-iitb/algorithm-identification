#include<stdio.h>

int main(void){
    int n;
    scanf("%d",&n);
    int a[n];
    int i, minj, j, temp;
    int c = 0;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(i=0;i<n;i++){
        minj = i;
        for(j=i;j<n;j++){
            if(a[j]<a[minj]){
                minj = j;
            }
        }
        temp = a[i];
        a[i] = a[minj];
        a[minj] = temp;
        if(i!=minj) c++;
    }
    for(i=0;i<n-1;i++){
        printf("%d ",a[i]);
    }
    printf("%d\n%d\n",a[n-1],c);
    return 0;
    
}
