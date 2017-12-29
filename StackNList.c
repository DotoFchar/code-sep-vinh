#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct noob
{
    int key;
    struct noob *next;
};

typedef struct noob noob;

struct noob * makeNoob(int key)
{
    noob * temp = (noob*)malloc(sizeof(noob));
    temp->next=NULL;
    /////////////////
    temp->key = key;
    return temp;
}

void addTop(noob ** list, noob ** new) // hay la PUSH() trong STACK
{
    (*new)->next = *list;
    *list = *new;
}

void addTail(noob **list, noob ** new)
{
    if (*list == NULL)
    {
        (*new)->next = *list;
        *list = *new;
    }
    else if ((*list)->next == NULL)
    {
        (*list)->next = *new;
    } 
    else 
    {
        addTail(&(*list)->next, new);
    }
}

void addOder(noob ** list, noob ** new)
{    
    if ((*list) == NULL)
    {
        (*new)->next = *list;
        *list = *new;
    }
    else if ((*list)->next == NULL)
    {
        if ((*list)->key > (*new)->key) 
        {
            (*new)->next = *list;
            *list = *new;
        }
        else 
        {
            (*list)->next = *new;
        }
    }
    else
    {
        noob * ship = *list;
        while (ship != NULL)
        {
            if (ship->key < (*new)->key) 
            {
                if (ship->next == NULL)
                {
                    ship->next = (*new);
                    break;
                }
                else if (((ship->next)->key) <= (*new)->key)
                {
                    ship = ship->next;
                }
                else 
                {
                    (*new)->next = ship->next;
                    ship->next = (*new);
                    break;
                }
            } 
            else 
            {
                (*new)->next = *list;
                *list = *new;
                break;
            }           
        }
    }   
}

struct noob * delTop(noob ** list) //Hay la POP() trong Stack
{
    noob * del = *list;
    (*list) = (*list)->next;
    return del;
}

void showList(noob * list)
{
    if (list != NULL)
    {
        printf("%d\t", list->key);
        showList(list->next);
    }
}

void showListFILE(FILE *f, noob * list)
{
    if (list != NULL)
    {
        fprintf(f,"%d\t", list->key);
        showListFILE(f,list->next);
    }
}

int main()
{
    //Khai bao LIST
    noob * list=NULL;
    
    //Tao Nut & Them Vao Dau
    noob * node1 = makeNoob(4);
    addTop(&list, &node1);

    noob * node2 = makeNoob(6);
    addTop(&list, &node2);

    noob * node3 = makeNoob(9);
    addTop(&list, &node3);

    noob * node4 = makeNoob(0);
    addTop(&list, &node4);

    //in ra man hinh
    showList(list);
    printf("\n");

    //Them vao Duoi
    noob * node5 = makeNoob(5);
    addTail(&list, &node5);

    //in ra man hinh
    showList(list);
    printf("\n");

    //Khai bao LIST
    noob * list2 = NULL;

    //them nut theo thu tu
    noob * node6 = makeNoob(4);
    addOder(&list2, &node6);

    noob * node7 = makeNoob(6);
    addOder(&list2, &node7);

    noob * node8 = makeNoob(9);
    addOder(&list2, &node8);

    noob * node9 = makeNoob(0);
    addOder(&list2, &node9);

    //in ra man hinh
    showList(list2);
    printf("\n");

    //in ra FILE
    FILE *f;
    f = fopen("StackNList.txt", "w+");
    showListFILE(f,list);  
    fclose(f);

    return 1;
}