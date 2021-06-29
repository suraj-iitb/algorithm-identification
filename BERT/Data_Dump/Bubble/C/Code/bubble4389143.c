#include<stdio.h>
#include<stdlib.h>
#define swap(type,x,y) do{type val=x;x=y;y=val;}while(0)
int sum=0;
void BubbleSort(int a[],int n){
    int loop,loop2;
    for(loop=0;loop<n-1;loop++){
        for(loop2=n-1;loop2>loop;loop2--){
            if(a[loop2-1]>a[loop2]){
                swap(int,a[loop2-1],a[loop2]);
                ++sum;
            }
        }
    }
}
int main(void){
    int loop,n;
    int *num;
    scanf("%d",&n);
    num=calloc(n,sizeof(int));
    for(loop=0;loop<n;loop++){
        scanf("%d",&num[loop]);
    }
    BubbleSort(num,n);
    for(loop=0;loop<n;loop++){
        printf("%d",num[loop]);
        if(loop!=n-1){
            putchar(' ');
        }else{
            putchar('\n');
        }
    }
    printf("%d\n",sum);
    free(num);
    return 0;
}
