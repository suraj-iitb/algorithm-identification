#include<iostream>
#include<vector>

using namespace std;

int selection_sort(vector<int> &a,int n){
    int m=0;
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[min]>a[j]){
                min=j;
            }
        }
        if(min!=i){
            swap(a[min],a[i]);
            m++;
        }
    }
    return m;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int m=selection_sort(a,n);
    for(int i=0;i<n;i++){
        if(i>0)cout<<' ';
        cout<<a[i];
    }
    cout<<endl;
    cout<<m<<endl;
    
}
