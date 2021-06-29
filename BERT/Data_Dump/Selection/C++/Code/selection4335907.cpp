#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> vec(n);
    int count=0;
    for(int i=0;i<n;i++){
        cin>>vec.at(i);
    }
    for(int i=0;i<n-1;i++){
        int check=i;
        int minimum=vec.at(i);
        for(int j=i;j<n;j++){
            if(minimum>vec.at(j)){
                minimum=vec.at(j);
                check=j;
            }
        }
        swap(vec.at(check),vec.at(i));
        if(check!=i){
            count++;
        }
    }
    for(int i=0;i<n;i++){
        if (i) cout<<" ";
        cout<<vec.at(i);
    }
    cout<<endl;
    cout<<count<<endl;
}
