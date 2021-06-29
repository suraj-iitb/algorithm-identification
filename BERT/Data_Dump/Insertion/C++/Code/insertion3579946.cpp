#include <iostream>
#include <vector>

using namespace std;

int insSort(int *arr,int N){
    for(int i=1;i<N;i++){
        int v = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>v){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = v;
        for(int k=0;k<N;k++){
            cout << arr[k];
            if(k!=N-1) cout << " ";
        }
        cout << endl;       
    }
    return 0;
}

int main(){
    int N,l;
    cin >> N;
    int arr[N];

    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
  	for(int i=0;i<N;i++){
      cout << arr[i];
      if(i!=N-1) cout << " ";
    }
    cout << endl;
    
    insSort(arr,N);
    return 0;
}


