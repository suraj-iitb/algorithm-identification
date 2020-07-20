#include <bits/stdc++.h>

using namespace std;
int main(){
    int n, n_swaps=0, temp;
    cin >> n;
    vector<int> array(n);
    for(int i=0;i<n;i++) cin >> array[i];
    
    //Bubble sort
    for(int i=0;i<n;i++){
        for(int j=n-1; j>i;j--){
            if(array[j-1] > array[j]){
                temp = array[j-1];
                array[j-1] = array[j];
                array[j] = temp;
                n_swaps++;
            }
        }
    }
    
    for(int i=0;i<n;i++) cout << array[i] << " \n"[i==n-1];
    cout << n_swaps << endl;
    
    return 0;
}
