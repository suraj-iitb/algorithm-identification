#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[101]={0},N,flag=1,num=0;
    cin>>N;
    for(int i=1;i<=N;i++) cin>>a[i];

    while(flag)
    {
        flag=0;
        for(int j=N;j>1;j--)//不执行这个循环中的IF语句时退出
        {
            if(a[j-1]>a[j])
            {
                swap(a[j-1],a[j]);
                num++;
                flag=1;
            }
        }
    }

    for(int i=1;i<=N;i++)
    {
        cout<<a[i];
        if(i<N) cout<<" ";
        else cout<<endl<<num<<endl;
    }

}
