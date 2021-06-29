#include<stdio.h>
#include<utility>

int main(){
    int n,c=0;
    scanf("%d",&n);
    int a[n];
    for(int i = 0;i < n;i++){
        scanf("%d",&a[i]);
    }
    bool flag = 1;
    while(flag){
        flag = 0;
        for(int i = n-1; i >= 1;i--){
            if(a[i] < a[i-1]){
                std::swap(a[i],a[i-1]);
                c++;
                flag =1;
            }
        }
    }
    
    for(int i = 0;i < n;i++){
        if(i != n-1){
            printf("%d ",a[i]);
        } else {
            printf("%d\n",a[i]);
        }
    }
    printf("%d\n",c);
    
}

