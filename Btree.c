#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct noob
{
    int key;
    struct noob *left;
    struct noob *right;
};

typedef struct noob noob;

struct noob * makeNoob(int key)
{
    noob * temp = (noob*)malloc(sizeof(noob));
    temp->left=NULL;
    temp->right=NULL;
    /////////////////
    temp->key = key;
    return temp;
}

void addNoob(noob ** tree, noob ** new)
{
    if (*tree == NULL) *tree = *new;
    else if ((*tree)->key > (*new)->key) addNoob(&(*tree)->left, new);
    else addNoob(&(*tree)->right, new);
}

struct noob * searchNoob(noob * tree, int key)
{
    if (tree==NULL) return NULL;
    else 
    {
        if (tree->key == key) return tree;
        else if (tree->key > key) return searchNoob(tree->left, key);
        else searchNoob(tree->right, key);
    }
}

struct noob * delNoob(noob ** tree, int key)
{
    if (*tree==NULL) return NULL;
    else if ((*tree)->key > key) return delNoob(&(*tree)->left, key);
    else if ((*tree)->key < key) return delNoob(&(*tree)->right, key);
    else // T->key == x
    {
        noob *P = *tree;
        noob *del = makeNoob((*tree)->key);
        if ((*tree)->left == NULL) (*tree) = (*tree)->right;    // Node chi co cay con (*tree)hai
        else if ((*tree)->right == NULL) (*tree) = (*tree)->left;   // Node chi co cay con trai
        else // Node co ca 2 con
        {
            noob *S = *tree, *Q = S->left;
            // S la cha cua Q, Q la Node phai nhat cua cay con trai cua P
            while (Q->right != NULL)
            {
                S = Q;
                Q = Q->right;
            }
            P->key = Q->key;
            if (S!=*tree) 
            {
                S->right = Q->left;
                S->right = NULL;
            } 
            else 
            {
                S->left = NULL;
            }
        }
        return del;
    }
    return NULL;
}

void showNoob(noob * tree)
{
    if (tree!=NULL)
    {
        showNoob(tree->left);
        printf("%d\t", tree->key);
        showNoob(tree->right);
    }
}

void showNoobFILE(FILE *f, noob * tree)
{
    if (tree!=NULL)
    {
        showNoobFILE(f, tree->left);
        fprintf(f,"%d", tree->key);
        showNoobFILE(f, tree->right);
    }
}

int main()
{
    //Khai bao cay
    noob * tree = NULL;
    
    //Tao nut
    noob * node1 = makeNoob(5);
    addNoob(&tree, &node1);

    noob * node2 = makeNoob(1);
    addNoob(&tree, &node2);

    noob * node3 = makeNoob(7);
    addNoob(&tree, &node3);

    noob * node4 = makeNoob(12);
    addNoob(&tree, &node4);

    noob * node5 = makeNoob(122);
    addNoob(&tree, &node5);

    noob * node6 = makeNoob(3);
    addNoob(&tree, &node6);

    noob * node7 = makeNoob(6);
    addNoob(&tree, &node7);

    noob * node8 = makeNoob(-1);
    addNoob(&tree, &node8);

    noob * node9 = makeNoob(8);
    addNoob(&tree, &node9);

    noob * node10 = makeNoob(9);
    addNoob(&tree, &node10);

    //in ra man hinh
    printf("_DS: \n");
    showNoob(tree);
    printf("\n");

    //tim kiem
    noob * resutl = searchNoob(tree, 5);
    printf("Tim so 7: %d\n", resutl->key);

    //xoa Noob
    noob * del = delNoob(&tree, 122);
    printf("_DS: xoa %d \n", del->key);
    showNoob(tree);
    printf("\n");    

    //in ra file
    FILE *f;
    f= fopen("Btree.txt", "w+");
    showNoobFILE(f, tree);
    fclose(f);
    
    return 1;
}