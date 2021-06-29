#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int c[n];
    int i, j, min_j, tmp, cnt_swap=0;
    
    for(i=0; i<n; i++) cin >> c[i];
    
    for(i=0; i<n; i++){
        if (n==1) break; 
        min_j = i;
        for(j=i+1; j<n; j++){
            if (c[min_j] > c[j]) min_j = j;
        }
        if (i != min_j){
            tmp = c[i];
            c[i] = c[min_j];
            c[min_j] = tmp; 
            cnt_swap++;
        }
    }
    
    for(i=0; i<n; i++) cout << c[i] << " \n"[i==n-1];
    cout << cnt_swap << endl;
    
}
