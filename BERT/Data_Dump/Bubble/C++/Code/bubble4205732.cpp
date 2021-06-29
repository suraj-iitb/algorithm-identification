#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;
int a[200];
int main(){
    int n, count=0;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    int flag = 1;
    while(flag){
        flag = 0;
        for(int i=n-1;i>0;i--){
            if(a[i]<a[i-1]){
                int tmp = a[i];
                a[i] = a[i-1];
                a[i-1] = tmp;
                flag = 1;
                count++;
            }
        
        }
    }
    for(int i=0;i<n;i++){
        if(i!=0) cout << " ";
        cout << a[i];
    }
    cout << "\n" << count << endl;
    return 0;
}
