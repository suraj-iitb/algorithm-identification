#include<stdio.h>
void SelectionSort(int a[],int n){
    int loop,loop2,swap,min;
    int c=0;
    for(loop=0;loop<n;loop++){
        min=loop;
        for(loop2=loop;loop2<n;loop2++){
            if(a[loop2]<a[min]){
                min=loop2;
            }
        }
        if(loop!=min){
            swap=a[loop];
            a[loop]=a[min];
            a[min]=swap;
            c++;
        }
    }
    for(loop=0;loop<n;loop++){
        printf("%d",a[loop]);
        if(loop==n-1){
            printf("\n%d\n",c);
        }else{
            putchar(' ');
        }
    }
}
int main(void){
    int n,loop,a[101];
    scanf("%d",&n);
    for(loop=0;loop<n;loop++){
        scanf("%d",&a[loop]);
    }
    SelectionSort(a,n);
    return 0;
}
