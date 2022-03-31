#include <stdio.h>
#include <stdlib.h>

struct abc
{
     int data;
     struct abc *left, *right;
};

struct abc* insert(struct abc*, int);
struct abc* create(int);
struct abc* display(struct abc*);
void inorder(struct abc*);
void preorder(struct abc*);
void postorder(struct abc*);

struct abc* insert(struct abc* Root, int d)
{
      if(Root == NULL)
      {
         return create(d);
      }
      else if(Root->data>d)
      {
         Root->left=insert(Root->left, d);
      }
      else
      {
         Root->right=insert(Root-right, d);
      }
      return Root;
}

struct abc* create(int e)    
{
      struct abc* temp;
      temp=(struct abc*)malloc(sizeof(struct abc));
      temp->data=e;
      temp->left=NULL;
      temp->right=NULL;
      return temp; 
} 

void inorder(struct abc* Root)
{
      if(Root==NULL)
         return;
      inorder(Root->left);
      printf("%d ", Root->data);
      inorder(Root->right);
}

void preorder(struct abc* Root)
{
      if(Root==NULL)
         return;
      printf("%d ", Root->data);
      preorder(Root->left);
      preorder(Root->right);
}

void postorder(struct abc* Root)
{
      if(Root==NULL)
         return;
      postorder(Root->left);
      postorder(Root-right);
      printf("%d ", Root->data);
}

struct abc* create(struct abc* Root)
         
void main()
{
     struct abc *Root = NULL;
     int ch;
     printf("Welcome to binary search tree program!");
     printf("1. Create\t2.Search\t3.Insert\t4.Delete\t5.Display inorder\t6.Display preorder\t7.Display postorder\t8.Exit\n");
     printf("Enter your choice:\n");
     scanf("%d", &ch);
     do
     {
       switch(ch)
       {
          case 1:
                  int a;
                  printf("Enter a nuber to set as root of the tree:\n");
                  scanf("%d", &a);
                  create             
}     		  break;
          case 2:
                  int b;
                  printf("Enter a number to search in the binary tree:\n");  
