#include <bits/stdc++.h>

using namespace std;

void countSort(const vector<int> &init_array,vector<int> &sorted_array,const int max_val){
    vector<int> count_array(max_val+1,0);
    for(int i = 0;i < init_array.size();i++) count_array[init_array[i]]++;
    for(int i = 1;i < max_val+1;i++) count_array[i] = count_array[i] + count_array[i-1];
    for(int j = init_array.size()-1;j >= 0;j--){
        sorted_array[count_array[init_array[j]]-1] = init_array[j];
        count_array[init_array[j]]--;
    }
}

int main(){
    int len_array;
    int temp,max_val = 0;
    scanf("%d",&len_array);
    
    vector<int> int_array(len_array,0);
    vector<int> sorted_array(len_array,0);

    for(int i = 0;i < len_array;i++){
        scanf("%d",&temp);
        int_array[i] = temp;
        max_val = max(temp,max_val);
    } 
    
    countSort(int_array,sorted_array,max_val);
    
    for(int i = 0;i < len_array;i++){
        printf("%d",sorted_array[i]);
        if(i < len_array-1) printf(" ");
        else printf("\n");
    }
    return 0;   
}

