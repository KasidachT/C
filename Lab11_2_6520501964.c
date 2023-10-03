#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX_HEAP 100
//swap
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Heap
void setMinHeap(int heap[],int size,int idx){
    int smallest = idx;
    int left = (2*idx) + 1;
    int right = (2*idx) + 2;
    if(left < size && heap[left] < heap[smallest])
        smallest = left;
    if(right < size && heap[right] < heap[smallest])
        smallest = right;
    if(smallest != idx){
        swap(&heap[idx],&heap[smallest]);
        setMinHeap(heap,size,smallest);
    }
}
//build heap
void buildMinHeap(int heap[],int size){
    int i;
    int last = (size-2)/2;
    for(i=(size-2)/2;i>=0;i--){
        setMinHeap(heap,size,i);
    }
}
//check minHeap
int checkMinHeap(int heap[],int size){
    int lastLevel = (size-2)/ 2;
    int i;
    for(i=0;i <= lastLevel;i++){
        int leftChild = 2*i + 1;
        int rightChild = 2*i + 2;
        if(leftChild < size && heap[i] > heap[leftChild])
            return 0;
        if(rightChild < size && heap[i] > heap[rightChild])
            return 0;
    }

    return 1;
}
//print in level
void printLevel(int heap[],int size){
    int level = 1;
    int currentLevel = 1;
    int i = 0 ;
    while(i < size){
        for(int j = 0 ; j < currentLevel && i < size;j++){
            printf("%d ",heap[i]);
            i++;
        }
        printf("\n");
        currentLevel *= 2;
        level++;
    }
}
int main(int argc, char const *argv[])
{
    int n,i;
    scanf("%d",&n);
    int heap[MAX_HEAP];
    for(i=0;i<n;i++){
        scanf("%d",&heap[i]);
    }
    
    if(checkMinHeap(heap,n)){
        printf("a Min-Heap");
    } else {
        printf("Not a Min-Heap\n");
        buildMinHeap(heap,n);
        printLevel(heap,n);
    }
    return 0;
}
