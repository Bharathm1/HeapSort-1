#include <iostream>
#include "Heap.h"

using namespace std;

int main() {

    Heap myHeap;

    int *tempArray;
    tempArray = myHeap.getHeap();

    for (int i = 0; i < 25; ++i) {
        printf("Value No.%d is %d\n" ,i, tempArray[i]);
    }
    return 0;
}