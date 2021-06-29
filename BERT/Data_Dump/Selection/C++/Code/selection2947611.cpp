#include <bits/stdc++.h>
using namespace std;
void solve(int a[],int num)
{
    int mini=0,tmp=0;
    for(int i=0;i<num;i++)
    {
        mini = i;
        for(int j=i;j<num;j++)
            if(a[j]<a[mini]) {
                mini = j;
            }

            if(i!=mini) {
                swap(a[i], a[mini]);
                tmp++;
            }

    }
    for(int i=0;i<num;i++)
        if(i==num-1)     cout<<a[i]<<endl;
        else  cout<<a[i]<<" ";
    cout<<tmp<<endl;
}
int main()
{
    int num;
    cin>>num;
    int a[num];
    for(int i=0;i<num;i++)
        cin>>a[i];
    solve(a,num);
    return 0;
}
