#include <stdio.h>
#include <vector>
#include <array>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <unordered_map>


using std::string;
using std::vector;


void solve() {
    int n;
    scanf("%d", &n);
    vector<int> list(n);
    for (int i = 0; i < n; i++){
        int v;
        scanf("%d", &v);
        list[i] = v;
    }
    int swaped = 0;
    for(int i = 0; i < list.size(); i++){
        for(int j = list.size() - 1; i < j; j--){
            if(list[j] < list[j-1]){
                std::swap(list[j], list[j-1]);
                swaped++;
            }
        }
    }
    for(int i = 0; i < list.size(); i++){
        printf("%d", list[i]);
        if(i != list.size() -1){
            printf(" ");
        }
    }
    printf("\n%d\n", swaped);
    
}

int main() {
    
    solve();
    
    return 0;
}
