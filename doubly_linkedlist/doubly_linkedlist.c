#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "doubly_linkedlist.h"

int LENGTH = 0;

node_ptr create_node(int data) {
    node_ptr nn = (node_ptr)(malloc(sizeof(struct node)));
    nn->data = data;
    return nn;
}
void insert_at_start(node_ptr* head, int data){
    node_ptr nn = create_node(data);

    nn->prev = NULL;
    if(*head==NULL){
        printf("List is empty so inserting at the start\n");
        nn->next=NULL;
    }
    else{
        nn->next = *head;
    }
    *head=nn;
    LENGTH++;
    printf("Inserted\n");
}

void insert_at_end(node_ptr* head, int data){
    node_ptr nn = create_node(data);

    nn->next = NULL;
    if(*head==NULL){
        nn->prev=NULL;
    }
    else{
        node_ptr temp = *head;
        while(temp->next!=NULL){
            temp= temp->next;
        }
        nn->prev = temp;
        temp->next=nn;
    }
    LENGTH++;
    printf("Inserted\n");
}

void insert_at_pos(node_ptr* head, int data, int pos){
    insert_before(head, data, pos);
}

void insert_after(node_ptr *head, int data, int pos)
{
    node_ptr nn = create_node(data);
    if (*head == NULL)
    {
        printf("List is empty so inserting at the start\n");
        nn->prev=NULL;
        nn->next = NULL;
        *head = nn;
        LENGTH++;
    }
    else
    {
        if (pos == LENGTH)
        {
            insert_at_end(head, data);
        }
        else if (pos > LENGTH || pos < 0)
        {
            printf("\nEnter valid position. Size of the list is %d\n", LENGTH);
        }
        else
        {

            node_ptr temp = *head;
            for (int i = 0; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            nn->prev=temp->prev;
            nn->next = temp->next;
            temp->next->prev=nn;
            temp->next = nn;
            LENGTH++;
            printf("Inserted!\n");
        }
    }
}
void insert_before(node_ptr* head, int data, int pos){
    node_ptr nn = create_node(data);
    if (*head == NULL)
    {
        printf("List is empty so inserting at the start\n");
        nn->prev=NULL;
        nn->next=NULL;
        *head = nn;
        LENGTH++;
    }
    else
    {
        if (pos == 1)
        {
            insert_at_start(head, data);
        }
        else if (pos > LENGTH || pos < 0)
        {
            printf("\nEnter valid position. Size of the list is %d\n", LENGTH);
            return;
        }
        else
        {
            node_ptr temp = *head;
            node_ptr temp2;
            for (int i = 1; i < pos; i++)
            {
                temp2=temp;
                temp = temp->next;
            }

            nn->next = temp;
            nn->prev = temp2;
            temp->prev = nn;
            temp2->next = nn;
            printf("Inserted!\n");
            LENGTH++;
        }
    }

}

void delete_at_start(node_ptr* head){

    if (*head == NULL)
    {
        printf("\nList is Empty\n");
        return;
    }


    node_ptr temp = *head;
    *head=(*head)->next;
    (*head)->prev=NULL;
    free(temp);

    LENGTH--;
    printf("Deleted\n");

}

void delete_at_end(node_ptr* head){
    node_ptr temp = *head;
    node_ptr prev;
    if(*head==NULL){
        printf("\nList is Empty\n");
        return;
    }

    if (temp->next == NULL){
        *head = NULL;
        LENGTH--;
        printf("Deleted\n");
        return;
    }
    while (temp->next != NULL)
    {
        prev=temp;
        temp = temp->next;
    }

    prev->next = NULL;
    temp->prev = NULL;
    free(temp);
    LENGTH--;
    printf("Deleted\n");
}

void delete_at_pos(node_ptr *head, int pos)
{
    if (*head == NULL)
    {
        printf("\nList is Empty\n");
    }
    else
    {
        if (pos == LENGTH)
        {
            printf("There is no element after position %d\n", pos);
        }
        else if (pos > LENGTH || pos < 0)
        {
            printf("\nEnter valid position. Size of the list is %d\n", LENGTH);
        }
        else
        {

            node_ptr temp = *head;
            node_ptr prev;
            for (int i = 0; i < pos - 1; i++)
            {
                prev = temp;
                temp = temp->next;
            }

            prev->next = temp->next;
            temp->next->prev = prev;
            free(temp);
            LENGTH--;
            printf("Deleted!\n");
        }
    }
}
void delete_after(node_ptr* head, int pos){
    if (*head == NULL)
    {
        printf("\nList is Empty\n");
    }
    else
    {
        if (pos == LENGTH)
        {
            printf("There is no element after position %d\n", pos);
        }
        else if (pos > LENGTH || pos < 0)
        {
            printf("\nEnter valid position. Size of the list is %d\n", LENGTH);
        }
        else
        {

            node_ptr temp = *head;
            node_ptr prev;
            for (int i = 0; i < pos; i++)
            {
                prev=temp;
                temp = temp->next;
            }

            prev->next = temp->next;
            temp->next->prev = prev;
            free(temp);
            LENGTH--;
            printf("Deleted!\n");
        }
    }

}

void delete_before(node_ptr* head, int pos){
    if(*head == NULL){
        printf("\nList is empty\n");
        return;
    }
    else{
        if(pos == 1){
            printf("\nThere is no element before position 1. Please enter valid position\n");
        }
        else if(pos == 2){
            delete_at_start(head);
        }
        else if (pos > LENGTH || pos < 0)
        {
            printf("\nEnter valid position. Size of the list is %d\n", LENGTH);
        }
        else{
            node_ptr temp = *head;
            node_ptr prev;

            for(int i=0; i<pos-2; i++){
                prev=temp;
                temp=temp->next;
            }
            prev->next=temp->next;
            temp->next->prev=prev;
            free(temp);
            LENGTH--;
            printf("Deleted!\n");
        }
    }


}
void print_list(node_ptr* head)
{
    if (*head == NULL)
        printf("\nList is empty\n");

    else
    {
        node_ptr temp = *head;
        printf("\n");
        while (temp->next != NULL)
        {
            printf("| %d | <-> ", temp->data);
            temp = temp->next;
        }
        printf("| %d | ->  NULL\n", temp->data);
    }

}

void search(node_ptr * head, int data){
    node_ptr temp = *head;
    int i=1;
    bool found=false;
    while(temp!= NULL){
        if(data==temp->data){
            printf("Element found at position %d\n", i);
            found=true; 
            break;
        }

        temp=temp->next;
        i++;
    }
    if(found==false){
        printf("Element not found\n");
    }
} 
