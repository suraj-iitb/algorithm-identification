#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    for(int i=0;i<n;i++){
        if(i != n-1){cout<<vec[i]<<" ";}
      	else{cout<<vec[i];}
    }
    cout<<endl;
    int v;
    for(int i= 1;i<n;i++){
        v=vec[i];
        int j=i-1;
        while(j>=0&&vec[j]>v){
            vec[j+1]=vec[j];
            j--;
        }
        vec[j+1]=v;
    for(int i=0;i<n;i++){
        if(i != n-1){cout<<vec[i]<<" ";}
      	else{cout<<vec[i];}
        }
    cout<<endl;
    }
}
