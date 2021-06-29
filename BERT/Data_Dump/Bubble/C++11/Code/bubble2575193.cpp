#include<iostream>
#include<vector>

class BubbleSort{
private:
    std::vector<int> dataSet;
    int changeCount;
public:
    BubbleSort(std::vector<int> vec);
    void dataSort();
    void showVector();
    int getChangeCount();
};

BubbleSort::BubbleSort(std::vector<int> vec){
    this->dataSet = vec;
    this->changeCount = 0;
}

void BubbleSort::dataSort(){
    bool swapped = true;
    while(swapped){
        swapped = false;
        for(int i = 1;i < dataSet.size();i++){
            if(dataSet[i - 1] > dataSet[i]){
                int tmp = dataSet[i];
                dataSet[i] = dataSet[i - 1];
                dataSet[i - 1] = tmp;
                swapped = true;
                changeCount++;
            }
        }
    }
}

void BubbleSort::showVector(){
    for(int i = 0;i < dataSet.size();i++){
        std::cout << (i ? " " : "") << dataSet[i];
    }
    std::cout << std::endl;
}

int BubbleSort::getChangeCount(){
    return this->changeCount;
}



int main(){
    
    int content;

    std::cin >> content;

    std::vector<int> vec;

    for(int i = 0;i < content;i++){
        int num;
        std::cin >> num;
        vec.push_back(num);
    }

    BubbleSort bs = BubbleSort(vec);
    bs.dataSort();
    bs.showVector();
    std::cout << bs.getChangeCount() << std::endl;

    return 0;
    
}
