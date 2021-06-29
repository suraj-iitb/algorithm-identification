#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n; cin>>n;
    int i,j,l;
    vector<int> a;
    for(i=0; i<n;i++){
        cin >> l;
        a.push_back(l);
    }
    for(j=0; j<n;j++) cout << a[j] << (j==n-1?'\n':' ');
    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            if(a[j]>a[i]){
                l=a[i];
                a.erase(a.begin()+i);
                a.insert(a.begin()+j,l);
                break;
            }
        }
        for(j=0;j<n;j++)cout << a[j] <<(j==n-1?'\n':' ');
    }
    return 0;
}
