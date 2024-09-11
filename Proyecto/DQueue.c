#include <stdio.h>
#include <stdlib.h>
#include "DQueue.h"

void createDQ(DQueue *dque)
{
    dque->head = NULL;
    dque->tail = NULL;
    dque->count = 0;
}

int isEmptyDQ(DQueue dque)
{
    if (dque.head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueueDQ(DQueue *dque, int ele)
{
    NodeDQ *nuevo = (NodeDQ *)malloc(sizeof(NodeDQ));
    nuevo->e = ele;
    nuevo->next = NULL;

    if (isEmptyDQ(*dque))
    {
        dque->head = nuevo;
    }
    else
    {
        dque->tail->next = nuevo;
    }
    dque->tail = nuevo;
    dque->count++;
}

int dequeueDQ(DQueue *dque)
{
    int e, aux_e;
    if (isEmptyDQ(*dque))
    {
        printf("Error de underflow\n");
        return -1;
    }
    else
    {
        aux_e = dque->head->e;
        NodeDQ *aux = dque->head;
        dque->head = dque->head->next;
        free(aux);
        dque->count--;
        return aux_e;
    }
}

int getNodeCount(DQueue dque)
{
    return dque.count;
}

void deleteDQ(DQueue *dque)
{
    while (!isEmptyDQ(*dque))
    {
        dequeueDQ(dque);
    }
}
