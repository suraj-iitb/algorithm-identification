#include<cstdio>
#include<cstring>

int main()
{
    int a[1000],n;
    while(~scanf("%d",&n))
    {
        memset(a,0,sizeof(a));
        int l = 0;
        while(n--) scanf("%d",&a[l++]);
        int i,j;
        for(i=0;i<l;i++)
        {
            for(j=0;j<i;j++)
            {
                if(a[j]>a[i])
                {
                    int temp;
                    temp = a[j];
                    a[j] = a[i];
                    a[i] = temp;
                }
            }
            for(j=0;j<l;j++) printf("%d%c",a[j],(j==l-1)?'\n':' ');
        }
    }
    return 0;
}
