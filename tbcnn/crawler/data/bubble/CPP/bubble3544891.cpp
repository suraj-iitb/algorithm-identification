#include <bits/stdc++.h>
using namespace std;
int counter;
void bubble_sort(vector<int> &a,int n){
    int flag=1;
    while(flag){
        flag=0;
        for(int j=n-1;j>0;j--){
            if(a.at(j)<a.at(j-1)){
                swap(a.at(j),a.at(j-1));
                flag=1;
                counter++;
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a.at(i);
    }
    bubble_sort(a,n);
    for(int i=0;i<n-1;i++){
        cout<<a.at(i)<<' ';
    }
    cout<<a.at(n-1)<<endl<<counter<<endl;
}
