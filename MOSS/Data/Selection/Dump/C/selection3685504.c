#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a[100]={0};
    int n=0;
    int min=0;
    int temp=0;
    int counter=0;
    scanf("%d", &n);
    for(int e=0;e<n;e++){scanf("%d", &a[e]);}
    for(int i=0;i<n-1;i++)
    {
        min=i;
        for(int j=i;j<n;j++)
        {
            if(a[min]>a[j])
            {min=j;}
        }
        if(min!=i)
        {
            temp=a[min];
            a[min]=a[i];
            a[i]=temp;
            counter++;
        }
    }
    for(int m=0;m<n;m++)
    {
        if(m!=n-1)
        {printf("%d ", a[m]);}
        else{printf("%d\n", a[m]);}
    }
    printf("%d\n", counter);
    return 0;
}

