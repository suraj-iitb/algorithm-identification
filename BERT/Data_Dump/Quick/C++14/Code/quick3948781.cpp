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
typedef struct _card {
    char sute;
    int num;
} Card;
void printList(const vector<Card>& list) {
    // print
    for(int i = 0; i < list.size(); i++){
        printf("%c %d\n", list[i].sute, list[i].num);
    }
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// logic
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool IsStable(const vector<Card>& list,const vector<Card>& original){
    vector<Card> margeList = original;
    std::stable_sort(margeList.begin(), margeList.end(), [](const Card& lhs, const Card& rhs){
        return lhs.num < rhs.num;
    });

    for(int i = 0; i < list.size(); i++){
        if(list[i].sute != margeList[i].sute)
        {
            return false;
        }
    }
    return true;
}




int partition(vector<Card>& list, int begin, int end){
    int x = list[end].num;
    int i = begin - 1;
    for(int j = begin; j <= end - 1; j++){
        if(list[j].num <= x){
            i++;
            std::swap(list[i], list[j]);
        }
    }
    std::swap(list[i + 1], list[end]);
    return i + 1;
}

void quickSort(vector<Card>& list, int begin, int end){
    if (begin < end) {
        int pivot = partition(list, begin, end);
        quickSort(list, begin, pivot - 1);
        quickSort(list, pivot + 1, end);
    }
}

void solve() {
    int n;
    scanf("%d", &n);
    vector<Card> list(n);
    for(int i = 0; i < n; i++){
        char sute;
        int num;
        scanf(" %c%d", &sute, &num);

        list[i] = {sute, num};
    }
    vector<Card> originalList = list;
    quickSort(list, 0, list.size() - 1);    
    if (IsStable(list, originalList)) {
        printf("Stable\n");
    } else {
        printf("Not stable\n");
    }
    printList(list);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// main
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
    solve();
    return 0;
}
