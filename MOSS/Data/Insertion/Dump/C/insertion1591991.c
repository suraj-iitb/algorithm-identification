#include<stdio.h>

void print(int a[],int n){ 
    int i;
    printf("%d",a[0]);
    for(i=1;i<n;i++){
        printf(" %d",a[i]);
    }   
    puts("");
}

void insertionsort(int a[],int n){ 
    int temp,i,j;
    print(a,n);
    for(i=1;i<n;i++){
        temp=a[i];
        j=i-1;
        while(j>=0&&a[j]>temp){
            a[j+1]=a[j];
            j--;
        }   
        a[j+1]=temp;
        print(a,n);
    }   
}

int main(){
    int n,a[100]={0},i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }   
    insertionsort(a,n);
    return 0;
}
