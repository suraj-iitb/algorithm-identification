#include<stdio.h>

int n,a[1000],i,j,v;

void print(){
    for(int i=0 ; i<n ; i++)
        if(i==n-1)    printf("%d\n", a[i]);
        else            printf("%d ", a[i]);
}

int main(void){
    scanf("%d", &n);
    for(i=0 ; i<n ; i++) 
        scanf("%d", &a[i]);
    print();
    for(i=1 ; i<n ; i++){
        j=i;
        while(j>0 && a[j-1] > a[j]){
            v=a[j-1], a[j-1]=a[j], 
            a[j]=v, j--;
        }
        print();
    }
    return 0;
}
