#include<iostream>
#include<vector>
using namespace std ;

int main(){
    int n ; cin >> n ;
    vector<int> a(n) ;
    for(int i=0;i<n;i++) cin >> a.at(i) ;
    cout << a.at(0) ;
    for(int i=1;i<n;i++) cout << " " << a.at(i) ;
    cout << endl ;
    for(int i=1;i<n;i++){
        int v = a.at(i) ;
        int j = i-1 ;
        while(j>=0&&a.at(j)>v){
            a.at(j+1) = a.at(j) ;
            j-- ;
        }
        a.at(j+1) = v ;
        cout << a.at(0) ;
        for(int i=1;i<n;i++) cout << " " << a.at(i) ;
        cout << endl ;
    }
}
