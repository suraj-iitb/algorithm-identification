#include<stdio.h>

int main(void){
    int n,tmp,tmp_p;
    int a[1000]={};
    
    scanf("%d",&n);
    
    for(int i=0;i<n-1;i++){
        scanf("%d",&a[i]);
        printf("%d ",a[i]);
    }
    scanf("%d",&a[n-1]);
    printf("%d\n",a[n-1]);
    
    for(int i=1;i<n;i++){
        tmp_p=-1;
        for(int j=i;j>=0;j--){
            if(a[i]<a[j]){
                tmp_p=j;
            }
            if(j==0&&tmp_p==-1){
                tmp_p=i;
            }
        }
        tmp=a[i];
        for(int j=i;j>tmp_p;j--){
            a[j]=a[j-1];
        }
        a[tmp_p]=tmp;
        for(int j=0;j<n-1;j++){
            printf("%d ",a[j]);
        }
        printf("%d\n",a[n-1]);
    }
    
    
    return 0;
    
}
