#include<iostream>

void printData(int data[], int lineCnt ) {
	for( int i = 0; i < lineCnt; i++ ) {
		if ( i > 0 ) {
			std::cout << " ";
		}
		std::cout << data[i];
	}
	std::cout << std::endl;
}

int main(void) {
    int lineCnt;
    std::cin >> lineCnt;

    int data[lineCnt];
    for( int i = 0; i < lineCnt; i++ ) {
        std::cin >> data[i];
    }

    for( int i = 0; i < lineCnt; i++ ) {
        int val = data[i];
        int j = i -1;
        while ( j >= 0 && val < data[j] ) {
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = val;
        printData(data,lineCnt);
    }

    return 0;
}

