#include<stdio.h>
#include<stdlib.h>
void InsertSort(int *a,int n){
    int i,j,v,k;

    for (k = 0; k <n; k++) {
        if (k==n-1) {
            printf("%d\n",a[k]);
        }
        else printf("%d ",a[k]);
    }


    for (i = 1; i < n; i++) {
        v=a[i];
        j=i-1;
        while (j!=-1&&a[j]>v) {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
        for (k = 0; k <n; k++) {
            if (k==n-1) {
                printf("%d\n",a[k]);
            }
            else printf("%d ",a[k]);
        }
    }

}


int main(int argc, char const *argv[]) {
    int *a,i,N;
    scanf("%d",&N);
    a=malloc(N*sizeof(int));
    for (i = 0; i < N; i++) {
    scanf("%d",&a[i]);
    }
    InsertSort(a,N);
    return 0;
}
