#include <stdio.h>
int main(){
    int n,a[100],temp;
    bool f;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<n;i++){
        f=true;
        for(int j=0;j<i&&f;j++){
            if(a[i]<a[j]){
                temp=a[i];
                for(int k=0;k<=i-j;k++){
                    a[i-k]=a[i-k-1];
                }
                a[j]=temp;
                f=false;
            }
        }
        printf("%d",a[0]);
        for(int j=1;j<n;j++)printf(" %d",a[j]);
        printf("\n");
    }
}
