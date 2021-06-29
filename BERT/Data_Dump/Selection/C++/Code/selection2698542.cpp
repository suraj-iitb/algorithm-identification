#include<iostream>

void printData(int data[], int dataNum ) {
    for( int i = 0; i < dataNum; i++ ){
        if( i != 0 ) {
            std::cout << " ";
        }
        std::cout << data[i];
    }
}

int main() {
    int lineCnt;
    std::cin >> lineCnt;

    int data[lineCnt];
    for( int i = 0; i < lineCnt; i++ ){
        std::cin >> data[i];
    }

    int exchangeCnt = 0;
    for( int i = 0; i < lineCnt - 1; i++ ) {
        int curMinIndex = i;
        for( int k = i + 1; k < lineCnt; k++ ) {
            if( data[k] < data[curMinIndex] ) {
                curMinIndex = k;
            }
        }
        if( curMinIndex != i ) {
            int buf = data[i];
            data[i] = data[curMinIndex];
            data[curMinIndex] = buf;
            exchangeCnt++;
        }
    }

    printData(data,lineCnt);
    std::cout << std::endl;
    std::cout << exchangeCnt;
    std::cout << std::endl;
}
