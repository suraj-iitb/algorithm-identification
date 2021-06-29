#include<bits/stdc++.h>

using namespace std;


int main()
{
    int n,j,a;
    cin>>n;
    vector<int > v;
    for(int i=0;i<n;i++) {cin>>a; v.push_back(a);  }
    for(int i=0;i<n;i++)
    {

        for(j=i-1; j>=0;j--)
        {
            if (v[j]>v[j+1]) swap(v[j],v[j+1]);
        }
        for(int j=0;j<n;j++) { if (j>0) cout<<" "; cout<<v[j];}
        cout<<endl;

    }


}
