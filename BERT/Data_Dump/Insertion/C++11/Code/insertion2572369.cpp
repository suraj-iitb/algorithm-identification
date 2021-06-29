#include<iostream>
#include<vector>

class InsertionSort{
private:
    std::vector<int> dataSet;
public:
    InsertionSort(std::vector<int> dataSet);
    void showArray();
    void dataSort();
};

InsertionSort::InsertionSort(std::vector<int> dataSet){
    this->dataSet = dataSet;
}

void InsertionSort::showArray(){
    for(int i = 0;i < dataSet.size();i++){
        std::cout << (i ? " " : "") << dataSet[i];
    }
    std::cout << std::endl;
}

void InsertionSort::dataSort(){
    for(int i = 1;i < dataSet.size();i++){
        int v = dataSet[i];
        int j = i - 1;
        while(j >= 0 && dataSet[j] > v){
            dataSet[j + 1] = dataSet[j];
            j--;
        }
        dataSet[j + 1] = v;
        showArray();
    }
}

int main(){
    
    std::vector<int> vec;

    int maxCount = 0;
    std::cin >> maxCount;
    
    int i = 0;

    int input;
    while(std::cin >> input){
        vec.push_back(input);
        
        i++;
        if(i >= maxCount){
            break;
        }
    }

    InsertionSort is = InsertionSort(vec);
    is.showArray();
    is.dataSort();

    return 0;
}
