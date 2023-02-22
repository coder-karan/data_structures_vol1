#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
void enqueue(node**,int);
void dequeue(node**);
void display(node*);
void peek(node*);
int main(){
    node* head=NULL;
    int ch=1,val;
    while(ch==1){
        printf("Enter the operation to be performed in queue :\n");
        printf("1 for enqueue\n2 for dequeue\n3 for peek\n4 for display:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter element to be pushed :");
            scanf("%d",&val);
            enqueue(&head,val);
            break;
        
        case 2:
            dequeue(&head);
            break;
        case 3:
            peek(head);
            break;
        case 4:
            display(head);
            break;
        default:
            printf("Invalid choice :\n");
            break;
        }
        printf("Want to continue (1/0):");
        scanf("%d",&ch);
    }
}
void enqueue(node** head,int val){
    node* p=(node*)malloc(sizeof(node));
    p->data=val;
    if(*head==NULL){
        *head=p;
        (*head)->next=NULL;
        return;
    }
    node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=p;
    p->next=NULL;

}
void dequeue(node** head){
    if(*head==NULL){
        printf("The queue is empty\n");
        return;
    }
    int element;
    element=(*head)->data;
    *head=(*head)->next;
    printf("Dequeued element is :%d\n",element);
}
void display(node* head){
    if(head==NULL){
        printf("The queue is empty \n");
        return;
    }
    node* temp=head;
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void peek(node* head){
    if(head==NULL){
        printf("The queue is empty\n");
        return;
    }
    printf("The peak element is : %d\n",head->data);


}