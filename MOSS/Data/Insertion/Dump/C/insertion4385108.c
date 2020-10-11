#include<stdio.h>
void InsertionSort(int a[],int n){
    int loop,loop2,swap;
    for(loop=1;loop<n;loop++){
        for(loop2=0;loop2<n;loop2++){
            printf("%d",a[loop2]);
            if(loop2!=n-1){
                putchar(' ');
            }else{
                putchar('\n');
            }
        }
        swap=a[loop];
        loop2=loop-1;
        while(loop2>=0 && a[loop2]>swap){
            a[loop2+1]=a[loop2];
            loop2--;
        }
        a[loop2+1]=swap;
    }
}
int main(void){
    int n,a[101],loop;
    scanf("%d",&n);
    for(loop=0;loop<n;loop++){
        scanf("%d",&a[loop]);
    }
    InsertionSort(a,n);
    for(loop=0;loop<n;loop++){
        printf("%d",a[loop]);
        if(loop!=n-1){
            putchar(' ');
        }else{
            putchar('\n');
        }
    }
    return 0;
}
