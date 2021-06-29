#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,min,s,c=0;
    vector<int> v;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s;
        v.push_back(s);
    }
    for(int i=0;i<n;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(v[j]<v[min]){
                min=j;
            }
        }
        swap(v[i],v[min]);
        if(i!=min)c++;
    }
    for(int i=0;i<n;i++){
        cout << v[i] << ((i==n-1)?"":" ") ;
    }
    cout<<endl<<c<<endl;
}
