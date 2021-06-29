#include<stdio.h>

int n,a[100];

void print(){
    for(int i=0;i<n;i++){
        if(i)printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
}

void InsertionSort(){
    int v;
    for(int i=1;i<n;i++){
        int j=i-1;
        v=a[i];
        while(j>=0&&v<a[j]){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
        print();
    }
}

int main(){
    scanf("%d",&n);

    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    print();
    InsertionSort();
    return 0;
}
