#include <iostream>
#include <cstdlib>


#define PRINTARRAY std::cout << array[0]; for (int v = 1; v < len; v++){ std::cout << ' ' << array[v]; } std::cout << "\n"

int main () {
        int len, i, j, k, s, c;
        std::cin >> len;
        int * array = (int *) malloc(sizeof(int) * len);
        for (i = len; i > 0; i--){
                std::cin >> array[len-i];
        }


        for (i = 0; i < len - 1; i++){
                k = i;
                for (j = i + 1; j < len; j++){
                        if (array[j] < array[k]){
                                k = j;
                        }
                }
                if (k != i){
                        s = array[i];
                        array[i] = array[k];
                        array[k] = s;
                        c++;
                }
        }

        PRINTARRAY;
        std::cout << c << "\n";
        free(array);
}
