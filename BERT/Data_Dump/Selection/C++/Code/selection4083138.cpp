#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int selectionSort(vector<int>& vector_array,int n){
    int counter = 0;
    rep(i,n-1){
        int minj = i;
        for(int j = i;j < n;j++){
            if(vector_array[j] < vector_array[minj]) minj = j;
        }
        if(minj > i) {
            swap(vector_array[i],vector_array[minj]);
            counter++;
        }
    }
    return counter;
}

int main(){
    int n;
    cin >> n;
    vector<int> num_array(n,0);
    rep(i,n){
        cin >> num_array[i];
    }
    int counter = selectionSort(num_array,n);
    rep(i,n){
        cout << num_array[i];
        if(i < n-1) cout << " ";
    }
    cout << "\n" << counter << "\n";

    return 0;   
}
