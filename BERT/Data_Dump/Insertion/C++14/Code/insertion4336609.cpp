#include <iostream>
using namespace std;
const int maxn = 110;
int arr[maxn];
int main(){
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n; i++) if (i == 0) printf("%d", arr[i]); else printf(" %d", arr[i]);
    puts("");
    for(int i = 1; i <= n-1; i++){
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j], j--;
        }
    arr[j+1] = key;
    for(int i = 0; i <= n-1; i++){
        if (i == 0) printf("%d", arr[i]); else printf(" %d", arr[i]);
    }
    puts("");
    }
}
