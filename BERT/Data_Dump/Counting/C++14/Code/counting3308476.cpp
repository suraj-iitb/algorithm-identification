#include <stdio.h>
#include <stdlib.h>

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
            array = (int *)malloc((length + 1) * sizeof(int));
            for(int i=1; i<=length; ++i) 
                scanf("%d", &array[i]);
        }

        void PrintArray() {
            for(int i=1; i<=length; ++i) {
                if(i-1)
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

class CountingSort : public AbstractSort
{
    private:
        int max;
        int *Coe_array;
        int *Outarray;

    public:
        CountingSort() : max(0), Coe_array(nullptr), Outarray(0)
        {

        }

        void sort() override {
            Setlength();
            SetArray();
            SetCoeArray();
            SetOutarray();
            countingsort();
            for(int i=1; i<=length; ++i) {
                if(i-1) 
                    printf(" ");
                
                printf("%d", Outarray[i]);
            }
            printf("\n");
        }

        void reqmax() {
            for(int i=1; i<=length; ++i) 
                if(max < array[i]) max = array[i];
        }

        void SetCoeArray() {
            reqmax();
            Coe_array = (int *)malloc((max + 1) * sizeof(int));
            for(int i=0; i<=max; ++i) 
                Coe_array[i] = 0;
        }

        void SetOutarray() {
            Outarray = (int *)malloc((length + 1) * sizeof(int));
            for(int i=1; i<=length; ++i)
                Outarray[i] = 0;
        }

        void countingsort() {
            for(int j=1; j<=length; j++)
                Coe_array[array[j]]++;

            
            /*
            for(int i=0; i<=max; ++i) {
                if(i) printf(" ");
                printf("%d", Coe_array[i]);
            }
            printf("\n");
            */
            
            for(int i=1; i<=max; ++i)
                Coe_array[i] = Coe_array[i] + Coe_array[i-1];
            
            /*
            for(int i=0; i<=max; ++i) {
                if(i) printf(" ");
                printf("%d", Coe_array[i]);
            }
            printf("\n");
            */
            
            for(int j=length; j>=1; --j){
                Outarray[Coe_array[array[j]]] = array[j];
                Coe_array[array[j]]--;
            }
        }
};

int main() {
    AbstractSort *_Absort;
    _Absort = new CountingSort();
    _Absort->sort();

    delete(_Absort);
    return 0;
}
