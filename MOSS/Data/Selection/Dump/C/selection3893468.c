#include<stdio.h>
int n, a[100], tmp, minj,c=0;

void print(){
    for(int i=0 ; i<n ; i++)
        if(i==n-1)    printf("%d\n", a[i]);
        else            printf("%d ", a[i]);
}
int select_sort(){
    for(int i=0 ; i<n-1 ; i++){
        minj=i;
        for(int j=i ; j<n ; j++)
            if(a[j]<a[minj]) minj=j;
        tmp=a[i], a[i]=a[minj] , a[minj]=tmp;
        if(i!=minj) c++;
    }
    return c;
}
int main(void){
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++)
        scanf("%d",&a[i]);
    c=select_sort();
    print();
    printf("%d\n", c);
    return 0;
}
