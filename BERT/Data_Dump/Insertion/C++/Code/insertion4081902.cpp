#include <bits/stdc++.h>

using namespace std;
void insertion_sort(vector<int>& objective_array,int len_array){
    for(int i = 1;i < len_array;i++){
        int v = objective_array[i];
        int j = i-1;
        while(j>=0 && objective_array[j] > v){
            objective_array[j+1] = objective_array[j];
            j--;
        }
        objective_array[j+1] = v;
        for (int k =0; k < len_array; k++){
            cout << objective_array[k];
            if(k<len_array-1) cout << " ";
        }
        cout << "\n";
    }
}

int main(){
    int len_array;
    cin >> len_array;
    vector<int> objective_array(len_array,0);
    for(int i = 0;i < len_array;i++){
        cin >> objective_array[i];
        cout << objective_array[i];
        if(i < len_array-1) cout << " ";
    }
    cout << "\n";
    insertion_sort(objective_array,len_array);

    return 0;   
}

