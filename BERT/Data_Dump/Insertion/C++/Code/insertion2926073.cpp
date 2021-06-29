# include <iostream>
# include <stdint.h>
# include <stdio.h>
# include <math.h>
#include <cstdlib>
# include <algorithm>
# include <string>
using namespace std;

int main(){
    int n,v,j;
    int A[1000];
    cin >>n;
    for(int i=0;i<n;i++){
        cin >>A[i];
        if(i ==0) cout <<A[i];
        else cout <<" "<<A[i];

    }
    cout <<"\n";
    for(int i=1;i<n;i++){
        v= A[i];
        j =i-1;
        while(j>=0 && A[j] >v){
            A[j+1] =A[j];
            j--;
            A[j+1] = v;
        }
        for(int i=0;i<n;i++){
            if(i ==0) cout <<A[i];
            else cout <<" "<<A[i];

        }
        cout <<"\n";

    }

    
	return 0;
}

