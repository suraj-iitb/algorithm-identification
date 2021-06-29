#include <iostream>

using namespace std;
int main() {
    int i, j, data_length;

    // data_length = 100;
    // int data[] = {0, 933, 743, 262, 529, 700, 508, 752, 256, 256, 119, 711, 351, 843, 705, 108, 393, 330, 366, 169, 932, 917, 847, 972, 868, 980, 223, 549, 592, 164, 169, 551, 427, 190, 624, 635, 920, 944, 310, 862, 484, 363, 301, 710, 236, 876, 431, 929, 397, 675, 491, 190, 344, 134, 425, 629, 30, 727, 126, 743, 334, 104, 760, 749, 620, 256, 932, 572, 613, 490, 509, 119, 405, 695, 49, 327, 719, 497, 824, 596, 649, 356, 184, 93, 245, 7, 306, 509, 754, 352, 665, 783, 738, 801, 690, 330, 337, 195, 656, 963 };

    cin >> data_length;
    int data[data_length];
    for (i = 0; i < data_length; i++) {
        cin >> data[i];
    }

    for (i = 0; i < data_length - 1; i++) { cout << data[i] << " "; }
    cout << data[i] << endl;

    for (i = 1; i < data_length; i++) {
        int base = data[i];
        j = i - 1;
        while (base < data[j] && 0 <= j) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = base;

        for (j = 0; j < data_length - 1; j++) { cout << data[j] << " "; }
        cout << data[j] << endl;
    }

    return 0;
}
