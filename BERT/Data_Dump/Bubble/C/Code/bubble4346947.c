/*
 * FileName:     bubble
 * CreatedDate:  2020-04-12 14:03:02 +0900
 * LastModified: 2020-04-12 14:10:23 +0900
 */

#include <stdio.h>
int count=0;
void bubble(int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            if(a[j]<a[j-1]){
                int tmp=a[j-1];
                a[j-1]=a[j];
                a[j]=tmp;
                count++;
            }
        }
    }
}
int main(void){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    bubble(a,n);
    printf("%d",a[0]);
    for(int i=1;i<n;i++){
        printf(" %d",a[i]);
    }
    printf("\n%d\n",count);

    return 0;
}

