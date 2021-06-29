#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 13
#define pi M_PI

int main(){
    int n;
    scanf("%d",&n);
    int a[100];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int min,count;
   for(int i=0;i<n;i++){
       min=i;
        for(int j=i;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
if(min!=i){
        int tmp=a[i];
        a[i]=a[min];
        a[min]=tmp;
        count++;
        }
    }
    for(int i=0;i<n;i++){
        if(i) printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
    printf("%d\n",count);
}
