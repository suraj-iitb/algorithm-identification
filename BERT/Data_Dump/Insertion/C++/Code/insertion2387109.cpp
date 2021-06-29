#include <bits/stdc++.h>
using namespace std;
int tag[2000005],n;
void print()
{
    for(int j=0;j<n-1;j++)
        cout<<tag[j]<<' ';
    cout<<tag[n-1]<<endl;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>tag[i];
    print();
    for(int i=1;i<n;i++)
    {
        int key=tag[i],j=i-1;
        while(key<tag[j]&&j>=0)
            tag[j+1]=tag[j--];
        tag[j+1]=key;
        print();
    }
}
