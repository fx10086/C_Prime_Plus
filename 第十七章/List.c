#include <stdlib.h>
#include <stdio.h>
#include "List.h"

static void CopyToNode(Item item, Node * pnode);

void InitializeList(List *plist)
{
    plist->head = NULL;
    plist->tail = NULL;
}

bool ListIsEmpty(const List *plist) 
{
    return plist->head == NULL;
}

bool ListIsFull(const List *plist)
{
    Node * pt;
    bool full;
    pt = (Node *)malloc(sizeof(Node));
    if (pt == NULL)
        full = true;
    else 
        full = false;
    free(pt);
    return full;
}

unsigned int ListItemCount(const List * plist) 
{
    unsigned int count = 0;
    Node * pnode = plist->head;
    while (pnode != NULL)
    {
        count++;
        pnode = pnode->next;
    }
    return count;
}

bool AddItem(const Item item, List *plist)
{
    Node * pnew;
    pnew = (Node *)malloc(sizeof(Node));
    if (pnew == NULL)
        return false;
    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (plist->head == NULL)
        plist->head = pnew;
    else
        plist->tail->next = pnew;
    plist->tail = pnew;
    return true;
}

void Traverse(const List *plist, void (*pfun)(Item item)) 
{
    Node * pnode = plist->head;
    while (pnode != NULL)
    {
        (*pfun)(pnode->item);
        pnode = pnode->next;
    }
}

void EmptyTheList(List *plist) 
{
    Node * psave;
    while (plist->head != NULL)
    {
        psave = plist->head->next;
        free(plist->head);
        plist->head = psave;
    }
}

static void CopyToNode(Item item, Node * pnode)
{
    pnode->item = item;
}