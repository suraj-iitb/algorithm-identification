#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void counting_sort(vector<int> a,vector<int> &ans,int k);
void print_vector(vector<int> a);
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        int tmp;
        cin>>a[i];
    }
    vector<int> ans(a.size());
    for(int i=0;i<ans.size();i++){
        ans[i]=-1;
    }
    int max=*std::max_element(a.begin(),a.end());
    // cout<<"max:"<<max<<"\n";
    counting_sort(a,ans,max);
    print_vector(ans);
}
void counting_sort(vector<int> a,vector<int> &ans,int k){
    // cout<<"-----sorting-----\n";
    vector<int> c(k+1);
    vector<int> offset(k+1);
    for(int i=0;i<=k;i++){
        c[i]=0;
    }
    // cout<<"----- step1 -----\n";
    for(int i=0;i<a.size();i++){
        c[a[i]]++;
    }
    // print_vector(c);
    // cout<<"----- step2 -----\n";
    offset[0]=0;
    for(int i=1;i<=k;i++){
        offset[i]=offset[i-1]+c[i-1];
    }
    // print_vector(offset);
    // cout<<"----- step3 -----\n";
    for(int i=0;i<a.size();i++){
        ans[offset[a[i]]]=a[i];
        offset[a[i]]++;
    }
    // print_vector(offset);
    // cout<<"----- sorted -----\n";
}
void print_vector(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i];
        if(i!=a.size()-1)cout<<" ";
    }
    cout<<"\n";
}
