#include <iostream>
#include "Heap.h"

using namespace std;

int main() {

    Heap myHeap;

    int *tempArray;
    tempArray = myHeap.getHeap();


    for (int i = 0; i < 10; ++i) {
        printf("Value No.%d is %d\n" ,i, tempArray[i]);
    }

    printf("\n");

    int *tempSorted = myHeap.getSortedHeap();

    for (int i = 0; i < 10; ++i) {
        printf("Value No.%d is %d\n" ,i, tempSorted[i]);
    }


    return 0;
}