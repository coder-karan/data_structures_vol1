#include<stdio.h>
#define MAX 5
int dequeue(int[],int*,int*);
void enqueue(int[],int*,int*,int);
void push(int[],int*,int*,int);
void pop(int[],int*,int*);
int isEmpty(int ,int);
int isFull(int,int);

int main(){
    int queue1[MAX];
    int start=-1;
    int end=-1;
    push(queue1,&start,&end,1);
    push(queue1,&start,&end,2);
    push(queue1,&start,&end,3);
    push(queue1,&start,&end,4);
    push(queue1,&start,&end,5);
     push(queue1,&start,&end,6);


    pop(queue1,&start,&end);
    pop(queue1,&start,&end);
    pop(queue1,&start,&end);
    pop(queue1,&start,&end);
    pop(queue1,&start,&end);
    pop(queue1,&start,&end);


}
int isEmpty(int start,int end){
    if(start==-1 && end==-1){
        return 1;
    }
    return 0;
}
int isFull(int start,int end){
    if(end==MAX-1){
        return 1;
    }
    return 0;
}
void push(int queue1[],int* start,int* end,int val){
    if(isFull(*start,*end)){
        printf("The stack is full\n");
        return;
    }
    enqueue(queue1,start,end,val);
}
void pop(int queue1[],int* start,int* end){
    if(isEmpty(*start,*end)){
        printf("The stack is Empty\n");
        return;   
    }
    int count=0;
    int temp;
    for(int i=(*start);i<((*start)+(*end))/2;i++){
        temp=queue1[i];
        queue1[i]=queue1[(*end)-count];
        queue1[(*end)-count]=temp;
        count++;
    }
    int element=dequeue(queue1,start,end);
    printf("The popped Element is :%d\n",element);
    count=0;
    if(!isEmpty(*start,*end)){
        for(int i=*start;i<((*start)+(*end))/2;i++){
        temp=queue1[i];
        queue1[i]=queue1[(*end)-count];
        queue1[(*end)-count]=temp;
        count++;
    }
    }
   
    

    

}
void enqueue(int queue1[],int *start,int *end,int val){
    (*end)++;
    queue1[*end]=val;
    if(*start==-1){
        *start=*end;
    }
}
int dequeue(int queue1[],int* start,int* end){
    int element=queue1[*start];
    (*start)++;
    if((*start)>(*end)){
        *start=*end=-1;
    }
    return element;
}