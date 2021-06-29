#include<stdio.h>
int main()
{
    int i,j,n,hairetsu[105],min,t,num=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&hairetsu[i]);
    for(i=0;i<n;i++){
        min=i;
        for(j=i;j<n;j++){
            if(hairetsu[j]<hairetsu[min])
                min=j;
        }
        if(hairetsu[min]!=hairetsu[i]){
            t=hairetsu[i];
            hairetsu[i]=hairetsu[min];
            hairetsu[min]=t;
            num++;
        }
    }
    for(i=0;i<n-1;i++)
        printf("%d ",hairetsu[i]);
    printf("%d\n",hairetsu[i]);
    printf("%d\n",num);
    return 0;
}
