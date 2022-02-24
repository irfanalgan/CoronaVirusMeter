//IRFAN KAAN ALGAN 2328599//
#include <stdio.h>											
#include <stdlib.h>			
#include <string.h>
#define TRUE 1
#define FALSE 0



typedef struct Node *AVLTree;

struct dataNode{
	int TotalCase;
	char countryName[50];
	int TotalTest;
	int TotalDeaths;
	int TotalRecovered;
	int ActiveCases;
	struct dataNode *next;
};

struct Node{
	int TotalCase;	
	char countryName[50];
	int TotalTest;
	int TotalDeaths;
	int TotalRecovered;
	int ActiveCases;
	AVLTree left;
	AVLTree right;
	int height;
	int count;
	struct dataNode *dataNext;
};


AVLTree SingleRotateWithLeft(AVLTree);
AVLTree SingleRotateWithRight(AVLTree);
AVLTree DoubleRotateWithLeft(AVLTree);
AVLTree DoubleRotateWithRight(AVLTree);
int AVLTreeHeight(AVLTree);
int Max(int,int);


AVLTree SingleRotateWithLeft(AVLTree k2)
{
	AVLTree k1;
    k1=k2->left;
    k2->left=k1->right;
    k1->right=k2;
    
    k2->height=Max(AVLTreeHeight(k2->left),AVLTreeHeight(k2->right));
    k1->height=Max(AVLTreeHeight(k1->left),AVLTreeHeight(k1->right));
    
    return k1;
	
}

AVLTree SingleRotateWithRight(AVLTree k1)
{
	AVLTree k2;
    
    k2=k1->right;
    k1->right = k2->left;
    k2->left=k1;
    
    k2->height=Max(AVLTreeHeight(k2->left),AVLTreeHeight(k2->right));
    k1->height=Max(AVLTreeHeight(k1->left),AVLTreeHeight(k1->right));
    
    return k2;
}

AVLTree DoubleRotateWithLeft(AVLTree k3)
{
	k3->left = SingleRotateWithRight(k3->left);
    return SingleRotateWithLeft(k3);
}

AVLTree DoubleRotateWithRight(AVLTree k3)
{
	k3->right = SingleRotateWithLeft(k3->right);
    return SingleRotateWithRight(k3);
	
}

int AVLTreeHeight(AVLTree t)
{
	if (t == NULL)
		return -1;
	else
		return t->height;
}
	
int Max(int x, int y)
{
	if (x >= y)
		return x;
	else
		return y;
}
