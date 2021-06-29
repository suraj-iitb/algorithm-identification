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
    // input
    int n;
    scanf("%d", &n);
    vector<int> list(n);
    for (int i = 0; i < n; i++){
        int v;
        scanf("%d", &v);
        list[i] = v;
    }

    // sort
    int swaped = 0;
    for(int i = 0; i < list.size(); i++){
        int minIndex = i;
        for(int j = i + 1; j < list.size(); j++){
            if(list[j] < list[minIndex]){
               minIndex = j;
            }
        }
        if(i != minIndex) {
            std::swap(list[i], list[minIndex]);
            swaped++;
        }
    }
    // print
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
