#include<iostream>
#include<vector>
using namespace std ;

int main(){
    int n ; cin >> n ;
    vector<int> a(n) ;
    for(int i=0;i<n;i++) cin >> a.at(i) ;
    int cnt = 0 ;
    for(int i=0;i<n-1;i++){
        int mn = i ;
        for(int j=i+1;j<n;j++){
            if(a.at(mn)>a.at(j)) mn = j ;
        }
        if(i!=mn){
            cnt++ ;
            int sub = a.at(i) ;
            a.at(i) = a.at(mn) ;
            a.at(mn) = sub ;
        }
    }
    for(int i=0;i<n;i++){
        cout << a.at(i) ;
        if(i==n-1) cout << endl ;
        else cout << " " ;
    }
    cout << cnt << endl ;
}
