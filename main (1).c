#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#define MAX_HEAP 200
//swap
struct node{
    char label;
    int freq;
    struct node* LC;
    struct node* RC;
};
int Rear = -1;
int index = -1;
int size = 0;
struct node *Q[MAX_HEAP];
struct node *Root = NULL;

// Heap
void setMinHeap(struct node* heap[],int size,int idx){
    int smallest = idx;
    int left = (2*idx) + 1;
    int right = (2*idx) + 2;
    if(left < size && heap[left]->freq < heap[smallest]->freq)
        smallest = left;
    if(right < size && heap[right]->freq < heap[smallest]->freq)
        smallest = right;
    if(smallest != idx){
        //swap(heap[idx],heap[smallest]);
        struct node *temp;
        temp = heap[idx];
        heap[idx] = heap[smallest];
        heap[smallest] = temp; 
        setMinHeap(heap,size,smallest);
    }
}
//build heap
void buildMinHeap(struct node* heap[],int size){
    int i;
    int last = (size-2)/2;
    for(i=(size-2)/2;i>=0;i--){
        setMinHeap(heap,size,i);
    }
}

struct node* DeQ(){
	if(size != 0){
		struct node* data ;
		data = Q[index];
		index = (index + 1)%MAX_HEAP;
		size--;
	}
}


void enQ(struct node* data){
	if(index == -1 && Rear == -1){
		index = Rear = 0;
	}else{
		Rear = (Rear+1)%MAX_HEAP;
	}
	Q[Rear] = data;
	size++;
}


int main()
{
    int i ,j;
    char sen[MAX_HEAP];
    struct node *new;
    bool first = false;
    gets(sen);
    for(i=0;i<strlen(sen);i++){
        if(first == false){
            new = (struct node*)malloc(sizeof(struct node));
            new->label = sen[i];
            new->freq = 1;
            new->LC = NULL;
            new->RC = NULL;
            enQ(new);
            first = true;
        }else{
            for(j = 0;j < size;j++){
                if(Q[j]->label == sen[i]){
                    Q[j]->freq += 1;
                    break;
                }else if(j == size-1 && Q[j] != sen[i]){
                    new = (struct node*)malloc(sizeof(struct node));
                    new->label = sen[i];
                    new->freq = 1;
                    new->LC = NULL;
                    new->RC = NULL;
                    enQ(new);
                    break;
                }
            }
        }
    }
    buildMinHeap(Q,size);
    for(i = 0;i < size;i++){
        printf("%c=%d ",Q[i]->label,Q[i]->freq);
    }
    while(size > 1){
    	struct node *T1 , *T2;
    	T1 = DeQ();
    	T2 = DeQ();
    	new = (struct node*)malloc(sizeof(struct node));
        new->label = '-';
        new->freq = T1->freq + T2->freq;
        new->LC = T1;
        new->RC = T2;
        enQ(new);
	}
	for(i = 0;i < size;i++){
        printf("%c=%d ",Q[i]->label,Q[i]->freq);
    }
    
    return 0;
}

