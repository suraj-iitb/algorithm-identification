#include<bits/stdc++.h>                                                                                                                
using namespace std;
int n,a[150],sw;
int selectionsort(){
    int minj,t;
    for(int i=0 ; i < n - 1 ;++i){
        minj = i;
        for(int j=i ; j<n ; ++j ){
            if(a[j] < a[minj]) minj = j;
        }
        swap(a[i],a[minj]);
        if(i != minj) ++sw;
    }   
    return sw; 
}
int main(){
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> a[i];
    }   
    selectionsort();
    for(int i=0;i<n;++i){
        if(i == 0) cout << a[i];
        else cout << ' ' << a[i];
    }   
    cout << '\n' << sw << '\n';
    return 0;
}

