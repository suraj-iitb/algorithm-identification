#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec.at(i);
    }
    int count=0;
    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>i;j--){
            if(vec.at(j-1)>vec.at(j)){
                swap(vec.at(j-1),vec.at(j));
                count++;
                continue;
            }else{
                continue;

            }
        }
    }
    for(int i=0;i<n;i++){
        if(i)cout<<" ";
        cout<<vec.at(i);
    }
    cout<<endl;
    cout<<count<<endl;

}
