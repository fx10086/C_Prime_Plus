#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

typedef struct pair
{
    Trnode *fa;
    Trnode *cur;
}Pair;

static Trnode * MakeNode(const Item * pi);
static bool ToLeft (const Item * i1, const Item * i2);
static bool ToRight(const Item * i1, const Item * i2);
static void AddNode(Trnode * new_node, Trnode * root);
static void InOrder(const Trnode * root, void(*pfun)(Item item));
static Pair SeekItem(const Item * pi, const Tree * ptree);
static void DeleteNode(Trnode **ptr);
static void DeleteAllNodes(Trnode * root);

void InitializeTree(Tree *ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
}

bool TreeIsEmpty(const Tree *ptree)
{
    return ptree->size == 0;
}

bool TreeIsFull(const Tree *ptree)
{
    return ptree->size == MAXITEMS;
}

int TreeItemCount(const Tree *ptree)
{
    return ptree->size;
}

bool AddItem(const Item * pi, Tree *ptree) 
{
    if (TreeIsFull(ptree))
    {
        fprintf(stderr,"Tree is full\n");
        return false;
    }
    if (InTree(pi, ptree))
    {
        fprintf(stderr,"Attempted to add duplicate item\n");
        return false;
    }
    Trnode * new_node = MakeNode(pi);
    if (new_node == NULL)
    {
        fprintf(stderr,"Couldn't create node\n");
        return false;
    }
    ptree->size++;
    if (ptree->root == NULL)
        ptree->root = new_node;
    else
        AddNode(new_node, ptree->root);
    return true;
}

bool InTree(const Item * pi, const Tree *ptree) 
{
    return SeekItem(pi, ptree).cur != NULL;
}

bool DeleteItem(const Item * pi, Tree *ptree) 
{
    Pair look = SeekItem(pi, ptree);
    if (look.cur == NULL)
        return false;
    if (look.fa == NULL)
        DeleteNode(&ptree->root);
    else if (look.fa->left == look.cur)
        DeleteNode(&look.fa->left);
    else
        DeleteNode(&look.fa->right);
    ptree->size--;
    return true;
}

void Traverse(const Tree *ptree, void (*pfun)(Item item)) 
{
    if (ptree != NULL)
        InOrder(ptree->root, pfun);
}

void DeleteAll(Tree * ptree) 
{
    DeleteAllNodes(ptree->root);
    ptree->root = NULL;
    ptree->size = 0;
}

static Trnode * MakeNode(const Item * pi)
{
    Trnode * new_node = (Trnode *)malloc(sizeof(Trnode));
    if (new_node != NULL)
    {
        new_node->item = *pi;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

static bool ToLeft (const Item * i1, const Item * i2)
{
    int cmp = strcmp(i1->petname, i2->petname);
    if (cmp < 0)
        return true;
    else if (cmp == 0 && strcmp(i1->petkind, i2->petkind) < 0)
        return true;
    else
        return false;
}

static bool ToRight(const Item * i1, const Item * i2)
{
    int cmp = strcmp(i1->petname, i2->petname);
    if (cmp > 0)
        return true;
    else if (cmp == 0 && strcmp(i1->petkind, i2->petkind) > 0)
        return true;
    else
        return false;
}

static void AddNode(Trnode * new_node, Trnode * root)
{
    if (ToLeft(&new_node->item, &root->item))
    {
        if (root->left == NULL)
            root->left = new_node;
        else
            AddNode(new_node, root->left);
    }
    else if (ToRight(&new_node->item, &root->item))
    {
        if (root->right == NULL)
            root->right = new_node;
        else
            AddNode(new_node, root->right);
    }
    else
    {
        fprintf(stderr,"Location error in AddNode()\n");
        exit(1);
    }
}

static void InOrder(const Trnode * root, void(*pfun)(Item item)) 
{
    if (root != NULL)
    {
        InOrder(root->left, pfun);
        (*pfun)(root->item);
        InOrder(root->right, pfun);
    }
}

static Pair SeekItem(const Item * pi, const Tree * ptree) 
{
    Pair look;
    look.fa = NULL;
    look.cur = ptree->root;
    while (look.cur != NULL)
    {
        if (ToLeft(pi, &look.cur->item))
        {
            look.fa = look.cur;
            look.cur = look.cur->left;
        }
        else if (ToRight(pi, &look.cur->item))
        {
            look.fa = look.cur;
            look.cur = look.cur->right;
        }
        else
            break;
    }
    return look;
}

static void DeleteNode(Trnode **ptr) 
{
    Trnode * temp;
    if ((*ptr)->left == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    }
    else if ((*ptr)->right == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
    else
    {
        for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right);
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
}

static void DeleteAllNodes(Trnode * root) 
{
    Trnode * temp;
    if (root != NULL) 
    {
        temp = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(temp);
    }
}