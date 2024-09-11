#ifndef DQUEUE
#define DQUEUE

typedef struct NodeDQ
{
    int e;
    struct NodeDQ *next;
} NodeDQ;

typedef struct DQueue
{
    NodeDQ *head;
    NodeDQ *tail;
    int count;
} DQueue;

void createDQ(DQueue *dque);
int isEmptyDQ(DQueue dque);
void enqueueDQ(DQueue *dque, int ele);
int dequeueDQ(DQueue *dque);
void deleteDQ(DQueue *dque);

#include "DQueue.c"
#endif
