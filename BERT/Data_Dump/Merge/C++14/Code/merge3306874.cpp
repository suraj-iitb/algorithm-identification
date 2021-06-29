#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

class AbstractSort
{
    protected:
        int *array, length;
    
    public:
        AbstractSort() : array(nullptr), length(0)
        {

        }

        virtual void sort() = 0;

        void Setlength() {
            scanf("%d", &length);
        }

        void SetArray() {
            array = (int *)malloc(length * sizeof(int));
            for(int i=0; i<length; ++i) 
                scanf("%d", &array[i]);
        }

        void PrintArray() {
            for(int i=0; i<length; ++i) {
                if(i)
                    printf(" ");

                printf("%d", array[i]);
            }
            printf("\n");
        }

        void DeleteArray() {
            delete(array);
        }

        virtual ~AbstractSort() {

        }
};

class MergeSort : public AbstractSort
{
    private:
        int cnt;

    public:
        MergeSort() :cnt(0)
        {

        }

        void merge(int left, int mid, int right) {
            int i, j, n1, n2, *L, *R;
            n1 = mid - left;
            n2 = right - mid;

            L = (int *)malloc((n1 + 1) * sizeof(int));
            L[n1] = INT_MAX;
            for(int i=0; i<n1; ++i)
                L[i] = array[left+i];
            
            R = (int *)malloc((n2 + 1) * sizeof(int));
            R[n2] = INT_MAX;
            for(int i=0; i<n2; ++i)
                R[i] = array[mid+i];

            i = j = 0;
            for(int k=left; k<right; ++k) {
                ++cnt;
                if(L[i] <= R[j]) {
                    array[k] = L[i];
                    ++i;
                }

                else {
                    array[k] = R[j];
                    ++j;
                }
            }
        }

        void mergesort(int left, int right) {
            int mid;
            if(left+1 < right) {
                mid = (left + right) / 2;
                mergesort(left, mid);
                mergesort(mid, right);
                merge(left, mid, right);
            }
        }

        void sort() override {
            Setlength();
            SetArray();
            mergesort(0, length);
            PrintArray();
            printf("%d\n", cnt);
        }
};

int main() {
    AbstractSort *_Absort;
    _Absort = new MergeSort();
    _Absort->sort();
    delete(_Absort);
    return 0;
}
