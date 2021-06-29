#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> &v1,int left ,int mid,int right);
void divide(vector<int> &v1,int left,int right);
int cnt=0;
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    divide(v,0,n-1);
    for(int i=0;i<n;i++){
        cout<<v[i];
        if(i!=n-1)cout<<" ";
    }
    cout<<"\n";
    cout<<cnt<<"\n";

}
void merge(vector<int> &v1,int left,int mid,int right){
    int i,j,k;
    int n1=mid+1-left;
    int n2=right-mid;
    // int cnt=0;
    vector<int> vl,vr;
    for(int i=0;i<n1;i++){
        vl.push_back(v1[left+i]);
    }
    for(int j=0;j<n2;j++){
        vr.push_back(v1[mid+1+j]);
    }

    i=0;j=0;k=left;
    while(i<n1&&j<n2){
        if(vl[i]<=vr[j]){
            v1[k]=vl[i];
            i++;
            cnt++;
        }
        else{
            v1[k]=vr[j];
            j++;
            cnt++;
        }
        k++;
    }
    while(i<n1){
        v1[k]=vl[i];
        i++;
        k++;
        cnt++;
    }
    while(j<n2){
        v1[k]=vr[j];
        j++;
        k++;cnt++;
    }
}
void divide(vector<int> &v1,int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        divide(v1,left,mid);
        divide(v1,mid+1,right);
        merge(v1,left,mid,right);
    }
}
