#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    
    int n;
    cin >> n;
    int a[n];
    
    for(int i = 0; i < n; i ++) cin >> a[i];
    
    int ans = 0;
    for(int i = 0; i < n-1; i ++){
        int min_num =101;
        int sort_posi = i;
        for(int j = i; j < n; j ++){
            if(min_num > a[j]){
                min_num = a[j];
                sort_posi = j;
            }
        }
        if(a[i] > a[sort_posi]){
            swap(a[i], a[sort_posi]);
            ans ++;
        }
        
    }
    for(int i = 0; i < n; i ++){
        if(i != 0) cout << " ";
        cout << a[i];
    }cout << endl;
    
    cout << ans << endl;
    
}

