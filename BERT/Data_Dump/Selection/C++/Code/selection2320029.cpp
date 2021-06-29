#include <iostream>
using namespace std;

#define MAX 100
int main(void){
    int N;
    int arr[MAX];
    int i,j;
    int mini;
    int tmp;
    int count = 0;
    
    cin >> N;
    for(i = 0; i < N; i++) cin >> arr[i];
    
    for(i = 0; i < N; i++){
        mini = i;
        for(j = i; j < N; j++){
            if(arr[j] < arr[mini]) mini = j;
        }
        
        if(i != mini){
            tmp = arr[i];
            arr[i] = arr[mini];
            arr[mini] = tmp;
            count++;
        }
    }
    
    cout << arr[0];
    for(i = 1; i < N; i++) cout << " " << arr[i];
    cout << endl << count << endl;
    
    return 0;
}
