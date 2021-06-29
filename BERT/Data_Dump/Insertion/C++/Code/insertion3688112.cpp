#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0;i < n;i++){
        scanf("%d",&a[i]);
    }
    int v,j;
    for(int i =1;i <= n-1;i++){
        for(int k = 0;k < n;k++){
                if(k != n-1){
                    printf("%d ",a[k]);
                } else {
                    printf("%d\n",a[k]);
                }
        }
        v = a[i];
        j = i-1;
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        
    }
    for(int k = 0;k < n;k++){
                if(k != n-1){
                    printf("%d ",a[k]);
                } else {
                    printf("%d\n",a[k]);
                }
            }
}

