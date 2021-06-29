#include <stdio.h>
void Insertion_Sort(int *a,int n);
int main(){
    int i=0,n,a[100];
    for(scanf("%d",&n);i<n;i++)
    scanf("%d",a+i);
    Insertion_Sort(a,n);
    return 0;
}
void Insertion_Sort(int *a,int n){
    int i=0,j=0,t=0;
    for(i=0;i<n;i++)
    printf(i<n-1?"%d ":"%d\n",a[i]);
    for(i=1;i<n;i++){
        t=a[i];
        for(j=i-1;j>=0&&a[j]>t;j--){
            a[j+1]=a[j];
        }
        a[j+1]=t;
        for(j=0;j<n;j++)
        printf(j<n-1?"%d ":"%d\n",a[j]);
    }
}
