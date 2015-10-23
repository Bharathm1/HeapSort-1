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

    swapNodes(node, getParent(node));

    /*
    int tempChild, tempParent;

    tempChild = mHeap[node];
    tempParent = mHeap[getParent(node)];

    //swap the nodes
    mHeap[getParent(node)] = tempChild;
    mHeap[node] = tempParent;
    */
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


//this is going to be similar to the bubble up function but reverse obviously
//doesnt work
bool Heap::bubbleDown(int node) {

    //if this is attempted on a index at the bottom or lower of the array
    //return false and stop at the bottom
    if(node >= HEAP_SIZE-1){


    }

    int leftChild, rightChild;

    //assuming counting from node 0
    leftChild = ((node+1) * 2) - 1;

    rightChild = (node+1) * 2;

    //we will need to swap with the larger of the two children
    //checking if left child is greater in value
    //or if the right child is non-existant
    if(rightChild != HEAP_SIZE &&
            mHeap[leftChild] > mHeap[rightChild]){

        swapNodes(leftChild, node);
        bubbleDown(leftChild);

    }
    if(rightChild < HEAP_SIZE-1 &&
            mHeap[leftChild] < mHeap[rightChild] ){

        swapNodes(rightChild, node);
        bubbleDown(rightChild);
    }


    return false;
}




//going to attempt this for first time
void Heap::heapSort() {

    for (int i = 0; i < HEAP_SIZE; ++i) {

        bubbleDown(0);

    }

}

/*
 * Similar to swapParent function
 * but is different in that it will take two node
 * positions and swap them
 */
void Heap::swapNodes(int node1, int node2) {


    int temp1, temp2;

    temp1 = mHeap[node1];
    temp2 = mHeap[node2];

    //swap the nodes
    mHeap[node2] = temp1;
    mHeap[node1] = temp2;


}
