#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
long long partition(pair<long long,char> *a,long long p,long long r){
    long long x=a[r].first;
    long long i=p-1;
    f(j,p,r){
        if(a[j].first<=x){
            i=i+1;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}
void qq(pair<long long,char> *a,long long p,long long r){
    if(p<r){
        long long q=partition(a,p,r);
        qq(a,p,q-1);
        qq(a,q+1,r);
    }
}
int main(){
    long long n;
    cin>>n;
    pair<long long,char> aa[n];
    f(i,0,n){
        cin>>aa[i].second>>aa[i].first;
    }
    map<long long,string> m1,m2;
    f(i,0,n){
        m1[aa[i].first]+=aa[i].second;
    }
    qq(aa,0,n-1);
    f(i,0,n){
        m2[aa[i].first]+=aa[i].second;
    }
    bool flag=true;
    f(i,0,n){
        if(m1[aa[i].first]!= m2[aa[i].first]){
            flag=false;
            break;
        }
    }
    if(flag){
        cout<<"Stable"<<endl;
    }
    else{
        cout<<"Not stable"<<endl;
    }
    f(i,0,n){
        cout<<aa[i].second<<" "<<aa[i].first<<endl;
    }
    return 0;
}

