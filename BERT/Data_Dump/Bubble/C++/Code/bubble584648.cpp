#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int cnt = 0;

    for(int i=0;i<n;i++){
        for(int j=n-1;j>=i+1;j--){
            if(a[j]<a[j-1]){
                swap(a[j],a[j-1]);
                cnt++;
            }
        }
    }
    cout << a[0];
    for(int i=1;i<n;++i){
        cout <<" "<<a[i];
    }
    cout << endl;
    cout << cnt <<endl;
    return 0;
}
