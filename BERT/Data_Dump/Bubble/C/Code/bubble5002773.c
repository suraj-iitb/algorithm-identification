#include <stdio.h>

int main(){
    int n, a[100], cnt=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(a[j]>a[j+1]){
                a[j]=a[j]+a[j+1];
                a[j+1]=a[j]-a[j+1];
                a[j]=a[j]-a[j+1];
                cnt++;
            }
        }
    }
    for(int i=0; i<n-1; i++){
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n-1]);
    printf("%d\n", cnt);
}
