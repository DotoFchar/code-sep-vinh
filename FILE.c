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

int rFile(char *file, noob ** tree)
{
    FILE *f;
    f = fopen(file, "r");
    if (f==NULL) {perror("LOI"); return 1;}
    while (1)
    {
        //////// doc mot dong trong file
        char line[100];
        if (fscanf(f, "%[^\n]%*c", line) == EOF) break;
        
        ///////////////////////////// doc cau truc cua 1 dong
        int key;
        sscanf(line, "%d", &key);
        
        /////////////////////// dua vao cay
        noob *new = makeNoob(key);
        addNoob(tree, &new); // 
    }
    return 1;
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

int main()
{
    noob * tree = NULL;
    rFile("FILE.txt", &tree);

    printf("_DS: \n");
    showNoob(tree);
    printf("\n");
    return 0;
}