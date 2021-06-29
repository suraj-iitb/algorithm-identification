#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
void pa(int a[],int n){
    for(int i=0;i<n;i++){
        if(i>0){
            printf(" ");
        }
        printf("%d",a[i]);
    }
    printf("\n");
}
void pe(int a[],int n){
    for(int i=1;i<n;i++){
        int v=a[i];
        int j=i-1;
        while(j>=0&&a[j]>v){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
        pa(a,n);
    }
}
int main(){
    int n;
    int a[110];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);  
    }
    pa(a,n);
    pe(a,n);
    return 0;
}
