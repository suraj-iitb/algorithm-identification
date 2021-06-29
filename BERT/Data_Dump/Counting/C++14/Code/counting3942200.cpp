#include <stdio.h>
#include <vector>
#include <list>
#include <array>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <stdexcept>


using std::string;
using std::vector;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// util
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::vector<std::string> split(const std::string& input, char delimiter)
{
    std::istringstream stream(input);

    std::string field;
    std::vector<std::string> result;
    while (std::getline(stream, field, delimiter)) {
        result.push_back(field);
    }
    return result;
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// user func
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void printList(const vector<int>& list) {
    // print
    for(int i = 0; i < list.size(); i++){
        printf("%d", list[i]);
        if(i != list.size() -1){
            printf(" ");
        }
    }
    printf("\n");
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// logic
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<int> countingSort(vector<int>& list){
    const int max = 2000000;
    // const int max = 10;
    vector<int> result(list.size());
    vector<int> countingList(max, {0});
    
    // count
    for(int i = 0; i < list.size(); i++){
        countingList[list[i]]++;
    }
    
    // set lower num count
    for(int i = 1; i < countingList.size(); i++){
        countingList[i] = countingList[i - 1] + countingList[i];
    }

    // sort
    for(int i = list.size() - 1; 0 <= i; i--){
        int index = countingList[list[i]] - 1;
        result[index] = list[i];
        countingList[list[i]]--;
    }
    return result;
}

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> list(n);
    for(int i = 0; i < n; i++){
        int v;
        scanf("%d", &v);
        list[i] = v;
    }
    auto result = countingSort(list);
    printList(result);
    
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// main
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
    solve();
    return 0;
}
