#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=0, *newnode, *temp, *prev_loc, *next_loc;
int ch, check, x;
void insert(){
    newnode = (struct node *) malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    printf("Enter previous and next node's location: ");
    scanf("%d %d", &prev_loc, &next_loc);
    printf("Is previous node is head (1,0): ");
    scanf("%d", &check);
    if(check==1)
        head=newnode;
    else
        prev_loc->next=newnode;
    newnode->next=next_loc;
}
void delete(){
    printf("Enter previous and next node's location: ");
    scanf("%d %d", &prev_loc, &next_loc);
    printf("Is previous node is head (1,0): ");
    scanf("%d", &check);
    if(check==1)
        head=next_loc;
    else
        prev_loc->next=next_loc;
}
void search(){
    printf("Enter an element to be search: ");
    scanf("%d", &x);
    temp=head;
    while (temp!=0)
    {
        
        if(x==temp->data)
        break;
        temp=temp->next;
    }
    if(temp!=0)
        printf("Element found");
    else 
    printf("Element not found");
}
void display(){
    temp=head;
    printf("Singly Linked List Elements: ");
    printf("|%d(%d)|--->", head, &head);
    while(temp!=0){
        printf("|%d(%d)", temp->data, temp);
        temp=temp->next;
        printf("|%d|--->", temp);
    }
}
void main(){
    printf("\n1.Insert  2.Delete  3.Search  4.Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    newnode = (struct node *) malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    if(head==0)
        head=temp=newnode;
    else
    {
        temp->next = newnode;
        temp=newnode;
    }
    display();
    //temp=head;
    //printf("Singly Linked List Elements: ");
    //printf("|%d(%d)|--->", head, &head);
    //while(temp!=0){
        //printf("|%d(%d)", temp->data, temp);
        //temp=temp->next;
       // printf("|%d|--->", temp);
    //}
    while(0<ch<6)   
    {  
        printf("\n\nEnter your choice: ");         
        scanf("%d",&ch);
        switch(ch)  
        {  
            case 1:  
            insert();
            display();      
            break;  
            case 2:  
            delete();
            display();          
            break;  
            case 3:  
            search();       
            break;     
            case 4:  
            exit(0);  
            break;  
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
    getch();
}