#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int bubbleSort(vector<int>& vector_array,int n){
    int counter = 0;
    bool flag = true;
    while(flag){
        flag = false;
        for(int j=n-1; j>0; j--){
            if (vector_array[j] < vector_array[j-1]){
                swap(vector_array[j],vector_array[j-1]);
                flag = true;
                counter ++ ;
            }
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
    int counter = bubbleSort(num_array,n);
    rep(i,n){
        cout << num_array[i];
        if(i < n-1) cout << " ";
    }
    cout << "\n" << counter << "\n";

    return 0;   
}
