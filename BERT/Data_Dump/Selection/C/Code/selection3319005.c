#include <stdio.h>


int main(){
    int i,j,k,n;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    }
    int min,x,change=0;
    for (int i = 0; i < n; ++i) {
        min=i;
        for (int j = i;j<n; ++j) {if(a[min]>a[j])min=j;}

        if(i != min){
        x=a[i];
        a[i]=a[min];
        a[min]=x;
        change++;}
    }

    for(i=0;i<n;i++){
        if(i==(n-1))printf("%d",a[i]);
        else printf("%d ",a[i]);
    }
    printf("\n");
    printf("%d\n",change);
    return 0;
}
