#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node {
    Node* left;
    Node* right;
    int data;
    int h;
};

Node* root = NULL;

Node* create_node(int data){
    Node* nn =  (Node*)malloc(sizeof(Node));
    nn->data = data;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}


 int height(Node* root){
     int lh, rh;
 
     lh = root && root->left ? root->left->h : 0;
     rh = root && root->right ? root->right->h : 0;
 
     return lh > rh ? lh + 1 : rh + 1;
 }
 
 
 int balance_factor(Node* root){
     int lh, rh;
 
     lh = root && root->left ? root->left->h : 0;
     rh = root && root->right ? root->right->h : 0;
 
     return lh - rh;
     
 }
 
 
 Node* ll_rotation(Node* p){
     Node* pl = p->left;
     Node* plr = pl->right;
 
     p->left = plr;
     pl->right = p;
 
     p->h = height(p);
     pl->h =height(pl);
 
     if(root==p){
         root = pl;
     }
 
     return pl;
 }


 Node* lr_rotation(Node* p){
     Node* pl = p->left;
     Node* plr = pl->right;

     pl->right = plr->left;
     p->left = plr->right;

     plr->left = pl;
     plr->right = p;

     pl->h = height(pl);
     p->h = height(p);
     plr->h = height(p);

     if(root == p){
         root = plr;
     }
     return plr;
 }
 Node* rr_rotation(Node* p){
     printf("rr\n");
     Node* pr = p->right;
     Node* prl = pr->left;

     pr->left = p;
     p->right = prl;

     p->h = height(p);
     pr->h = height(pr);

     if(root == p){
         root = pr;
     }

     return pr;
 }

 Node* rl_rotation(Node* p){
     Node* pr = p->right;
     Node* prl = pr->left;

     p->right = prl->left;
     pr->left = prl->right;

     prl->left = p;
     prl->right = pr;

     pr->h = height(pr);
     p->h = height(p);
     prl->h = height(p);

     if(root == p){
         root = prl;
     }
     return prl;
 }



Node* insert(Node* root, int data){
    Node* nn = NULL;
    if(root == NULL){
        nn = create_node(data);
        nn->h = 1;
        return nn;
    }

    
    if(data < root->data){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }

    root->h = height(root);

    if(balance_factor(root) == 2 && balance_factor(root->left) == 1){
        return ll_rotation(root);
    }
    else if(balance_factor(root) == 2 && balance_factor(root->left) == -1){
            return lr_rotation(root);
    }

    else if(balance_factor(root) == -2 && balance_factor(root->right) == -1){
            return rr_rotation(root);
    }
    else if(balance_factor(root) == -2 && balance_factor(root->right) == 1){
            return rl_rotation(root);
    }
    return root;
}


Node* in_pre(Node* p){
    while(p && p->right != NULL){
        p=p->right;
    }
    return p;
}

Node* in_suc(Node* p){
    while(p && p->left != NULL){
        p=p->left;
    }
    return p;
}

Node* delete(Node* p, int key){
    if(p==NULL){
        return NULL;
    }

    if(p->left == NULL && p->right == NULL){
        if(p==root){
            root = NULL;
        }
        free(p);
        return NULL;
    }

    if(key < p->data){
        p->left = delete(p->left, key);
    }
    else if(key > p->data){
        p->right = delete(p->right, key);
    }
    else{
        Node* q;
        if(height(p->left) > height(p->right)){
            q = in_pre(p->left);
            p->data = q->data;
            p->left = delete(p->left, key);
        }
        else{
            q = in_suc(p->right);
            p->data = q->data;
            p->right = delete(p->right, key);
        }
    }

    p->h = height(p);

    if(balance_factor(p) == 2 && balance_factor(p->left) == 1){
        return ll_rotation(p);
    }
    else if(balance_factor(p) == 2 && balance_factor(p->left) == -1){
            return lr_rotation(p);
    }

    else if(balance_factor(p) == -2 && balance_factor(p->right) == -1){
            return rr_rotation(p);
    }
    else if(balance_factor(p) == -2 && balance_factor(p->right) == 1){
            return rl_rotation(p);
    }

    else if(balance_factor(p) == 2 && balance_factor(p->left) == 0){
            return ll_rotation(p);
    }
    else if(balance_factor(p) == -2 && balance_factor(p->right) == 0){
            return rl_rotation(p);
    }

    return p;
}
void print2dutil(Node* root, int space){
    if(root==NULL){
        return;
    }
    space+=3;
    print2dutil(root->right, space);
    printf("\n");
    for(int i=3; i<space; i++)
        printf(" ");
    printf("%d\n", root->data);
    
    print2dutil(root->left, space);

}
void print2d(Node* root){
    print2dutil(root, 0);
}


int main(){
    
    root = insert(root, 50);
    insert(root, 40);
    insert(root, 25);
    insert(root, 75);
    insert(root, 45);
    delete(root, 25);

    print2d(root);
}
