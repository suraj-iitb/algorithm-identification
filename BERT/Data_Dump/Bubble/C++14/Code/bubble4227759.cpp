#include<iostream>
#include<vector>
using namespace std ;

int main(){
    int n ; cin >> n ;
    int cnt = 0 ;
    vector<int> a(n) ;
    for(int i=0;i<n;i++) cin >> a.at(i) ;
    bool flag = true ;
    while(flag){
        flag = false ;
        for(int i=n-1;i>0;i--){
            if(a.at(i)<a.at(i-1)){
                cnt++ ;
                int sub = a.at(i) ;
                a.at(i) = a.at(i-1) ;
                a.at(i-1) = sub ;
                flag = true ;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << a.at(i) ;
        if(i==n-1) cout << endl ;
        else cout << " " ;
    }
    cout << cnt << endl ;
}
