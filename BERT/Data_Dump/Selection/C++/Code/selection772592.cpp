#include <iostream>
using namespace std;
#define MAX 101

int cnt;

void selection_sort(int n,int array[MAX]){
    for(int i = 0 ; i < n ; i++){
        int mini = i, flg = 0;
        for(int j = i ; j < n ; j++){
            if(array[j] < array[mini]){
                mini = j;
                flg = 1;
            }
        }
        if(!flg) continue;
        swap(array[i],array[mini]);
        cnt++;
    }
}

int main(){
    int n,array[MAX];
    
    cin >> n;
    for(int i = 0 ; i < n ; i++) cin >> array[i];
    
    cnt = 0;
    selection_sort(n,array);
    
    for(int i = 0 ; i < n ; i++){
        if(!i) cout << array[i];
        else cout << ' ' << array[i];
    }
    cout << endl;
    cout << cnt << endl;
    
    return 0;
}
