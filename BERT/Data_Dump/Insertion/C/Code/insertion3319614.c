#include <stdio.h>


void priner(int a[],int n){
    int i;
    for(i=0;i<n;i++){
        if(i==(n-1))printf("%d\n",a[i]);
        else printf("%d ",a[i]);
        }

}

void insert(int a[],int n){
    int i,j,k;
    for (i=1;i< n;i++) {
        k=a[i];
        for (j=i;0<j;j--) {
            if(a[j-1]<k)break;
            a[j]=a[j-1];

        }
        a[j]=k;
        priner(a,n);
    }
}

int main(){

    int i,n;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    }
    priner(a,n);
    insert(a,n);


 return 0;
}
