#include <stdio.h>
int bubbleSort(int a[],int n){
    int flag =1,i,tmp,ct =0;
    while(flag ==1){
        flag = 0;
        for(i = n-1;i>0;i--){
            if(a[i] < a[i-1]){
                tmp = a[i];
                a[i] = a[i-1];
                a[i-1] = tmp;
                flag = 1;
                ct++;
            }
        }
    }
    return ct;
}
int main(){
    int a[100];
    int n,i,ct;
    scanf("%d",&n);
    for(i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    ct = bubbleSort(a,n);
    for(i =0;i<n-1;i++){
        printf("%d ",a[i]);
    }
    printf("%d\n%d\n",a[n-1],ct);
    return 0;
}
