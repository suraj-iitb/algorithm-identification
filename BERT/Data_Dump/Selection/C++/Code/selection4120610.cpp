#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,j,k;
    int num=0;
    vector<int> a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k;
        a.push_back(k);
    }

    for(int i=0;i<n;i++){
        k=i;
        for(j=i+1;j<n;j++){
            k=a[k]<=a[j]?k:j;   //保证这个是稳定排序！
        }
        if(k!=i){
            num++;
            int temp=a[k];
            a[k]=a[i];
            a[i]=temp;
        }
    }
    for(int i=0;i<n;i++){
        if(i) cout<<' ';
        cout<<a[i];
    }
    cout<<endl<<num<<endl;
    return 0;
}

