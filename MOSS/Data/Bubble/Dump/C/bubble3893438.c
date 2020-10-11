#include<stdio.h>

int n, a[100], tmp, c=0;

void print(){
    for(int i=0 ; i<n ; i++)
        if(i==n-1)    printf("%d\n", a[i]);
        else            printf("%d ", a[i]);
}

int count(){
    for(int i=0 ; i<n ; i++){
        for(int j=n-1 ; j>i ; j--){
            if(a[j]<a[j-1]){
                tmp = a[j], a[j] = a[j-1], 
                a[j-1] = tmp, c++;
            }
        }
    }
    return c;
}

int main(void){
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++)
        scanf("%d",&a[i]);
    c=count();    
    print();
    printf("%d\n",c);
    return 0;
}
