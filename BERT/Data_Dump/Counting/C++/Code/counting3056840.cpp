#include<bits/stdc++.h>

using namespace std;

int cnt[10010];

int main()
{

    int n;

    while(scanf("%d",&n)!=EOF)
    {
        memset(cnt,0,sizeof(cnt));
        int a;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a);
            cnt[a]++;
        }

        bool flag=false;
        for(int i=0;i<10010;i++)
        {
            while(cnt[i])
            {
                if(flag)
                {
                    printf(" ");
                }
                printf("%d",i);
                flag=true;
                cnt[i]--;
            }
        }
        printf("\n");
    }



    return 0;
}

