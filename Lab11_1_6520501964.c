#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX_SIZE 100
//swap 
void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp; 
}
//set Heap
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
//build Heap
void buildHeap(int heap[],int size){
    for(int i = (size/2) - 1;i >= 0 ; i--){
        setMinHeap(heap,size,i);
    }
}
//print Heap in level order
void printHeapLevel(int heap[],int size){
    int level = 1;
    int currentLevel = 1 ;
    int i=0,j;
    while(i < size){
        for(j = 0; j<currentLevel && i < size ; j++){
            printf("%d ",heap[i]);
            i++;
        }
        printf("\n");
        currentLevel  *= 2;
        level++;
    }
}
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    int heap[MAX_SIZE];
    if(n > 0 && n <= 100){
        for(int i = 0 ; i < n ; i++){
            scanf("%d",&heap[i]);
        }
    }
    buildHeap(heap,n);
    printHeapLevel(heap,n);
    return 0;
}
