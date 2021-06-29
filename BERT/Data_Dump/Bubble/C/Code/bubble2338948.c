#include<stdio.h>

int main(void)
{
    int flg=1 ,flg2=0 ;
    int n=0 ;
    int i=0 ;
    int mem=0 ;

    scanf("%d",&n);
    int num[n] ;

    for (i=0 ;i<n ;i++){
        scanf("%d",&num[i]);
    }

    while (flg){

        flg=0;

        for (i=n-1 ;i>=1 ;i--){

            if (num[i-1] > num[i]){
                mem=num[i];
                num[i]=num[i-1];
                num[i-1]=mem;

                flg++;
                flg2++;
            }
        }

    }

    for (i=0 ;i<n-1 ;i++){
        printf("%d ",num[i]);
    }
    printf("%d\n",num[n-1]);
    printf("%d\n",flg2);

    return 0;
}
