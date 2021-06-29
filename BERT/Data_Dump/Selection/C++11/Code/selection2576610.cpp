#include<iostream>
#include<vector>

class SelectionSort{
protected:
    std::vector<int> dataSet;
    int changeCount;
public:
    SelectionSort(std::vector<int> vec);
    int getChangeCount();
    void showVector();
    void startSort();
};

SelectionSort::SelectionSort(std::vector<int> vec){
    this->dataSet = vec;
    this->changeCount = 0;
}

int SelectionSort::getChangeCount(){
    return this->changeCount;
}

void SelectionSort::showVector(){
    for(int i = 0;i < dataSet.size();i++){
        std::cout << (i ? " " : "") << dataSet[i];
    }
    std::cout << std::endl;
}

void SelectionSort::startSort(){
    for(int i = 0;i < dataSet.size();i++){
        int min_index = i;
        for(int j = i;j < dataSet.size();j++){
            if(dataSet[j] < dataSet[min_index]){
                min_index = j;
            }
        }
        if(i != min_index){
            int tmp = dataSet[i];
            dataSet[i] = dataSet[min_index];
            dataSet[min_index] = tmp;
            changeCount++;
        }
    }
}

int main(){
    
    int content;
    std::cin >> content;

    int input;
    int input_count = 0;
    std::vector<int> vec;

    while(std::cin >> input){
        vec.push_back(input);

        input_count++;
        if(input_count >= content){
            break;
        }
    }

    SelectionSort ss = SelectionSort(vec);
    ss.startSort();
    ss.showVector();
    std::cout << ss.getChangeCount() << std::endl;

    return 0;
}
