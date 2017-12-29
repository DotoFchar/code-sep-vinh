#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct noob
{
    int key;
    struct noob *next;
};

typedef struct noob noob;

void makeQueue(noob ** top, noob ** rear)
{
    *top = NULL;
    *rear = NULL;
}

struct noob * makeNoob(int key)
{
    noob * temp = (noob*)malloc(sizeof(noob));
    temp->next=NULL;
    /////////////////
    temp->key = key;
    return temp;
}

void enQueue(noob ** queue, noob ** rear, noob ** new)
{
    if (*queue == NULL)
    {
        *queue= *new;
        *rear = *new;
    }
    else
    {
        (*rear)->next = *new;
        *rear = *new;
    }
}

struct noob * deQueue(noob ** queue, noob ** rear)
{
    if (*queue == NULL) return NULL;
    else
    {
        noob * del = *queue;
        *queue = (*queue)->next;
        return del;
    }
}

void showQueue(noob * queue)
{
    if (queue != NULL) 
    {
        printf("%d\t", queue->key);
        showQueue(queue->next);
    }
}

void showQueueFILE(FILE *f, noob * queue)
{
    if (queue != NULL) 
    {
        fprintf(f,"%d\t", queue->key);
        showQueueFILE(f, queue->next);
    }
}

int main()
{
    //Khai bao QUEUE
    noob * QueueTOP, *rear;
    makeQueue(&QueueTOP, &rear);
    
    //Tao Nut
    noob * node1 = makeNoob(4);
    enQueue(&QueueTOP, &rear, &node1);

    noob * node2 = makeNoob(6);
    enQueue(&QueueTOP, &rear, &node2);

    noob * node3 = makeNoob(9);
    enQueue(&QueueTOP, &rear, &node3);

    noob * node4 = makeNoob(0);
    enQueue(&QueueTOP, &rear, &node4);

    //in ra manhinh
    showQueue(QueueTOP);
    printf("\n");

    //xoa nut
    noob * del = deQueue(&QueueTOP, &rear);
    printf("xoa nut: %d\n", del->key);

    //in ra manhinh
    showQueue(QueueTOP);
    printf("\n");

    //in ra FILE
    FILE *f;
    f = fopen("Queue.txt", "w+");
    showQueueFILE(f,QueueTOP);  
    fclose(f);

    return 0;
}