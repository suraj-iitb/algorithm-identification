#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    int cnt=0;
    for(int i=0; i<n-1; i++){
        int min_num=i;
        for(int j=i+1; j<n; j++){
            if(a[min_num]>a[j]) min_num=j; 
        }
        if(min_num!=i) cnt++;
        swap(a[i],a[min_num]);
    }
    for(int i=0; i<n; i++){
        if(i!=n-1) cout << a[i] << " ";
        else cout << a[i] << endl;
    }
    cout << cnt << endl;
    return 0;
}
