#include<iostream>
using namespace std;


int num[2000005], tmp1[2000005]={0}, tmp2[2000005]={0};
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }

    for(int i=0;i<n;i++)
        tmp1[num[i]]++;

    for(int i=1;i<=2000000;i++)
        tmp1[i] += tmp1[i-1];

    for(int i=n-1;i>=0;i--)
    {
        tmp2[tmp1[num[i]]] = num[i];
        tmp1[num[i]]--;
    }

    for(int i=1;i<=n;i++)
    {
        cout<<tmp2[i];
        if(i!=n) cout<<" ";
    }
    cout<<endl;
}

