#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define forn(i , n) for(int i=0;i<n;i++)



void print(vector<int> v){
    int n = v.size();
    
    forn(i , n){
        cout << v[i] << (i != n - 1 ? ' ' : '\n' );
    }
}


void insertionsort(vector<int> v , int size){
    for(int i = 1; i < size; i++){
        int key = v[i];
        int j = i - 1;
        
        while(j >= 0 && v[j] > key){
            swap(v[j + 1] , v[j]);
            j--;
        }
        
        print(v);
    } 
}


int main(){
    int n;
    cin >> n;
    
    vector<int> v(n , 0);
    forn(i , n){
        cin >> v[i];
    }
    
    int size = v.size();
    
    
    print(v);
    insertionsort(v , size);
    return 0;
}
