#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    vector<int> a;
    cin >> n;
    for(int temp;cin >> temp;) a.push_back(temp);
    for(int i=0; i<a.size(); i++){
        cout << a[i] << ((i==n-1)?'\n':' ');
    }
    for(int i=1; i<n; i++){
        int v = a[i];
        int j = i - 1;
        while(j>=0 && a[j]>v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        for(int t=0; t<a.size();t++){
            cout << a[t] << ((t==n-1)?'\n':' ');
        }
    }
    return 0;
}
