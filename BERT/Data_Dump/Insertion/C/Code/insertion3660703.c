#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a[100]={0};
    int n=0;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
        if(i!=n-1){
        printf("%d ", a[i]);
        }
        else{printf("%d", a[i]);}
    }
    printf("\n");
    for(int j=1;j<=n-1;j++)
    {
        int key=a[j];
        int m=j-1;
        while(m>=0&a[m]>key)
        {
            a[m+1]=a[m];
            m=m-1;
            a[m+1]=key;
        }
        for(int e=0;e<n;e++)
        {
            if(e!=n-1)
            {
                printf("%d ", a[e]);
            }
            else{printf("%d", a[e]);}
        }
        printf("\n");
    }
    return 0;
}


