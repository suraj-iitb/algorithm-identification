#include<bits/stdc++.h>
using namespace std;

void print(vector<int>& a)
{
    int N=a.size();
    for(int i=0;i<N;i++) cout<<a[i]<<(i==N-1? '\n':' ');
}

int main()
{
    int N; cin>>N;
    vector<int> a(N);
    for(int i=0;i<N;i++) cin>>a[i];

    print(a);
    for(int i=1;i<N;i++){
        int j=i,val=a[i];
        while(j-1>=0 and a[j-1]>val) a[j]=a[j-1],j--;
        a[j]=val;
        print(a);
    }
    return 0;
}
