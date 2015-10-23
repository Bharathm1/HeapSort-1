#include <stddef.h>
#include <time.h>
#include <stdlib.h>
#include "Heap.h"


Heap::Heap() {
    //set current pos equal to zero
    mCurrentPos = 0;
    fillWithRand();
}

void Heap::insert(int newNum) {

    //insert a number into the current position
    mHeap[mCurrentPos] = newNum;

    //bubble up the new entry
    bubbleUp(mCurrentPos);

    //update currentpos
    mCurrentPos++;

}

void Heap::fillWithRand() {
    srand(time(NULL));

    for (int i = 0; i < HEAP_SIZE ; ++i) {
        insert(rand() % 100 + 1);
    }

}

int *Heap::getHeap() {
    return mHeap;
}

int *Heap::getSortedHeap() {
    return nullptr;
}

//return true if node is larger than parent
bool Heap::compareToParent(int node) {
    return mHeap[node] > mHeap[getParent(node)] ? true : false;
}

int Heap::getParent(int node) {
    return (node-1) /2;
}

int Heap::getLevel(int node) {
    return 0;
}

void Heap::swapWithParent(int node) {

    int tempChild, tempParent;

    tempChild = mHeap[node];
    tempParent = mHeap[getParent(node)];

    //swap the nodes
    mHeap[getParent(node)] = tempChild;
    mHeap[node] = tempParent;

}

bool Heap::bubbleUp(int node) {

    //if at the root of the tree
    //break from this function
    if(getParent(node) < 0){
        return false;
    }

    //if child is larger than parent then swap
    if(compareToParent(node)){

        swapWithParent(node);
        //recursivly bubble until all is
        //well in the universe
        bubbleUp(getParent(node));

    }

    //bubble up has completed
    return false;
}

bool Heap::bubbleDown(int node) {
    return false;
}