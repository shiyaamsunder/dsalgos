#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <binary.h>

node_ptr create_node(int data){
    node_ptr nn  = malloc(sizeof(node));
    nn->data=data;
    nn->left=NULL;
    nn->right=NULL;
    return nn;
}

node_ptr create()  
{  
    node_ptr temp;
    int data, choice;  
    temp = (node_ptr)malloc(sizeof(node_ptr));  
    printf("\nPress 0 to exit");  
    printf("\nPress 1 for new node");  
    printf("\nEnter your choice : ");  
    scanf("%d", &choice);   
    if(choice==0)  
    {  
        return 0;  
    }  
    else  
    {  
        printf("\nEnter the data:");  
        scanf("%d", &data);  
        temp->data = data;  
        printf("\nEnter the left child of %d", data);  
        temp->left = create();  
        printf("\nEnter the right child of %d", data);  
        temp->right = create();  
        return temp;   
    }  
}


void inorder(node_ptr tree){
    if(tree == NULL) return;
    inorder(tree->left);
    printf("%d\n", tree->data);
    inorder(tree->right);
}

void postorder(node_ptr tree){
    if(tree) {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d\n", tree->data);
    }
}

void preorder(node_ptr tree){
    if(tree) {
        printf("%d\n", tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}
