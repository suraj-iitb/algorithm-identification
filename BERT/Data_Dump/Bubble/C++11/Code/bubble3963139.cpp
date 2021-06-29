#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void print_vector(vector<int> v);
void sort(vector<int> &v);
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v);
}
void print_vector(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i];
        if(i!=v.size()-1)cout<<" ";
    }
    cout<<"\n";
}
void sort(vector<int> &v){
    int flag=1;
    int cnt=0;
    while(flag!=0){
        flag=0;
        for(int i=v.size()-1;i>0;i--){
            if(v[i]<v[i-1]){
                int tmp=v[i];
                v[i]=v[i-1];
                v[i-1]=tmp;
                flag=1;
                cnt++;
            }
        }
    }
    print_vector(v);
    cout<<cnt<<"\n";
}
