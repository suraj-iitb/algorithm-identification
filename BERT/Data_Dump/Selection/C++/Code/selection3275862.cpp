#include <iostream>
using namespace std;

int SL(int a[],int n){
    int ans = 0;
    for(int i = 0;i<n;i++){
        int minindex=i;
        for(int j=i;j<n;j++){
            if(a[j] < a[minindex]){
                minindex = j;
            }
        }
    if(i != minindex){
    int k = a[i];
    a[i] = a[minindex];
    a[minindex] = k;
    ans++;
    }
    }
    return ans;
}

int main(){
    int n;
    int a[100];
    cin >> n;
    for(int i=0;i<n;i++){
        int v ;
        cin >> v;
        a[i] = v;
    }
    int ans =SL(a,n);

    for(int i=0;i<n;i++){
        if(i != n-1){
            cout << a[i] << ' ';
        } else{
            cout << a[i] << endl;
        }
    }
    cout << ans << endl;
}
