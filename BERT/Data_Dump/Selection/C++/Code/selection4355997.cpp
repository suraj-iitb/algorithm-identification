#include<bits/stdc++.h>
using namespace std;


int main(){
   
    int n;
    cin >> n;
    int A[n];
    for(int i=0;i<n;i++){
        cin >> A[i]; 
    }
    int s,count = 0;
 
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int k=i+1;k < n;k++){
            if(A[min] > A[k])
            min = k;
        }
        if(min != i){
            count++;
            swap(A[i],A[min]);
        }

    }

    for(int i=0;i<n;i++){
        if(i) cout << " ";
            cout << A[i];
    }
        cout << endl << count << endl;
}
