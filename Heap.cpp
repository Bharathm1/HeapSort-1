#include <stddef.h>
#include <time.h>
#include <stdlib.h>
#include "Heap.h"


Heap::Heap() {
    //set current pos equal to zero
    mCurrentPos = 0;

    //fillWithNums();

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
    heapSort();
    return mHeap;
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
bool Heap::bubbleDown(int node, int stoppingPoint) {

    //if we are at an array element already swapped then stop
    if(node >= stoppingPoint){
        return false;
    }

    //if this is attempted on a index at the bottom or lower of the array
    //return false and stop at the bottom
    if(node >= HEAP_SIZE-1){
        return false;
    }

    int leftChild, rightChild;

    //assuming counting from node 0
    leftChild = ((node+1) * 2) - 1;

    rightChild = (node+1) * 2;

    //if we are at an array element already swapped then stop
    if(leftChild >= stoppingPoint || rightChild >= stoppingPoint){
        return false;
    }


    //first check if right child is a thing
    if(rightChild <= stoppingPoint){

        //second check that parent isn't the larger
        if(mHeap[node] > mHeap[leftChild] &&
                mHeap[node] > mHeap[rightChild]){
            return false;
        }

        //if right child is greater
        if(mHeap[rightChild] > mHeap[leftChild]){
            swapNodes(node, rightChild);
            bubbleDown(rightChild, stoppingPoint);

        }

        //if the left child is larger
        if(mHeap[leftChild] > mHeap[rightChild]){
            swapNodes(node, leftChild);
            bubbleDown(leftChild, stoppingPoint);
        }


    }

    //only need to check with left child
    if(leftChild < HEAP_SIZE){

        //if left child is greater than node
        if(mHeap[leftChild] > mHeap[node]){
            swapNodes(node, leftChild);
            //no need to try any more here
            return false;
        }

    }
    return false;
}




//going to attempt this for first time
void Heap::heapSort() {


    for (int i = 0; i < HEAP_SIZE; ++i) {

        swapNodes(0, ((HEAP_SIZE-i) -1));

        bubbleDown(0, (HEAP_SIZE-i) -1);

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

void Heap::fillWithNums() {

    for (int i = 0; i < HEAP_SIZE; ++i) {

        insert(i);

    }

}
