#include<stdio.h>
#define N 100
int main()
{
    int a[N],i,j,k,num,tmp,cnt=0;
    scanf("%d",&num);
    for(i=0;i<num;i++){
        scanf("%d",&a[i]);
    }
    for (i = 0; i < num - 1; i++) {
           for (j = num - 1; j > i; j--) {
               if (a[j - 1] > a[j]) {
                   tmp = a[j];
                   a[j] = a[j - 1];
                   a[j - 1]= tmp;
                   cnt++;
               }
           }
        }
        for(k=0;k<num-1;k++){
            printf("%d ",a[k]);
            }
            printf("%d",a[num-1]);
            printf("\n");
            printf("%d",cnt);
            printf("\n");
            
    
    return 0;
}
