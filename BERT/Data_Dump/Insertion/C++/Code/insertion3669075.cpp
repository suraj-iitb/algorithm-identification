#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,x,j,k,cnt=0,key=0;
    cin>>n;
    vector<int>v;
    for(i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    for(k=0;k<v.size();k++)
    {
        cout<<v[k];
        if(k!=v.size()-1)
        {
            cout<<" ";
        }
    }
    cout<<endl;
    for(i=1;i<v.size();i++)
    {
        key = v[i];
        j=i-1;
        while(j>=0&&v[j]>key)
        {

            v[j+1]=v[j];
            j--;

        }

        v[j+1]=key;
        for(k=0;k<v.size();k++)
    {
        cout<<v[k];
        if(k!=v.size()-1)
        {
            cout<<" ";
        }
    }
    cout<<endl;
    }

    return 0;

}
