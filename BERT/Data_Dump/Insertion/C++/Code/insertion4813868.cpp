#include <iostream>
#include <cstdlib>


#define PRINTARRAY std::cout << array[0]; for (int v = 1; v < len; v++){ std::cout << ' ' << array[v]; } std::cout << "\n"

int main () {
        int len, i, j, k;
        std::cin >> len;
        int * array = (int *) malloc(sizeof(int) * len);
        for (i = len; i > 0; i--){
                std::cin >> array[len-i];
        }

        PRINTARRAY;

        for (i = 1; i < len; i++){
                k = array[i];
                j = i - 1;
                while (j > -1 && array[j] > k){
                        array[j + 1] = array[j];
                        j--;
                }
                array[j + 1] = k;
                PRINTARRAY;
        }

        free(array);
}
