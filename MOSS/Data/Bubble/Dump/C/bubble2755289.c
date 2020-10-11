#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 13
#define pi M_PI

int main(){
    int n;
    scanf("%d",&n);
    int a[100];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int flag=1,count;
    while(flag){
        flag=0;
        for(int j=n-1;j>0;j--){
            if(a[j]<a[j-1]){
                int tmp=a[j];
                a[j]=a[j-1];
                a[j-1]=tmp;
                flag=1;
                count++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(i) printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
    printf("%d\n",count);
}
