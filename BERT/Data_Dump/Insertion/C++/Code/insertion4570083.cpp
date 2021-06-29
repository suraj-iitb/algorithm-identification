#include <bits/stdc++.h>

using namespace std;

int main(){
    
    vector<int> array;
    int n,c;
    cin >>n;
    for(int i=0;i<n;i++){
        cin >> c;
        array.push_back(c);
    }
    
    // Insertion sort
    for(int i=1;i<array.size(); i++){
        //print
        for(int i=0; i<array.size(); i++){
            cout << array[i] << " \n"[i==array.size()-1];
        }
        int key = array[i];
        int j = i-1;
        while(j >=0 && array[j]>key){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
        
        

    }//print
        for(int i=0; i<array.size(); i++){
            cout << array[i] << " \n"[i==array.size()-1];
        }
    
    return 0;
}
