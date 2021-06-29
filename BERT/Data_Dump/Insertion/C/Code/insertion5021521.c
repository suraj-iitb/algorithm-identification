#include <stdio.h>

int main(){
    int n, a[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    for(int k=0; k<n-1; k++)printf("%d ",a[k]);
    printf("%d\n", a[n-1]);
    for(int i=1; i< n; i++){
        int j=i-1, temp=a[i];
        while(j>=0&&temp<a[j]){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
        for(int k=0; k<n-1; k++)printf("%d ",a[k]);
        printf("%d\n", a[n-1]);
    }
}

