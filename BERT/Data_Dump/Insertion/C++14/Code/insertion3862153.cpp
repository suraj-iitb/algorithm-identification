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

void printList(const vector<int>& list) {
    for (int i = 0; i < list.size(); i++) {
        if (i == list.size() - 1){
            printf("%d\n", list[i]);
        }else{
           printf("%d ", list[i]);
        }
    }
}
int main() {
    // input
    int n = 0;
    scanf("%d", &n);
    vector<int> list = {};
    for (int i = 0; i < n; i++) {
        int v = 0;
        scanf("%d", &v);
        list.push_back(v);
    }

    // sort
    for (int i = 1; i < list.size(); i++) {
        int key = list[i];
        printList(list);
        int j = i - 1;
        for (;0 <= j && key < list[j]; j--) {
            list[j+1] = list[j];
        }
        list[j+1] = key;
    }
    printList(list);

    return 0;
}
