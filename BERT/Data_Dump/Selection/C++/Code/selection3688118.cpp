#include<stdio.h>
#include<utility>
#define rep(n) for(int i = 0;i < (n);i++)
int main(){
    int n,c=0,min;
    scanf("%d",&n);
    int a[n];
    rep(n) scanf("%d",&a[i]);
    for(int i = 0;i <= n-1;i++){
        min = i;
        for(int j = i; j <= n-1;j++)  if(a[min] > a[j]) min = j;
        if(i != min){
            std::swap(a[i],a[min]);
            c++;
        }
    }
    rep(n){
        if(i != n-1){
            printf("%d ",a[i]);
        } else{
            printf("%d\n",a[i]);
        }
    }
    printf("%d\n",c);
}

