#include<stdio.h>
int main()
{
    int n,s[10000],i,j,mini,temp,swap=0;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&s[i]);
    }
    for(i=0; i<n; i++)
    {
        mini=i;
        for(j=i; j<n; j++)
        {
            if (s[j]<s[mini])
            {
                mini=j;
            }
        }
        if(i!=mini){
        temp=s[i];
        s[i]=s[mini];
        s[mini]=temp;
        swap++;}
    }
    for(i=0; i<n; i++)
        {
            if(i<n-1)
                printf("%d ",s[i]);
            if(i==n-1)
                printf("%d\n",s[i]);
        }
    printf("%d\n",swap);
}

