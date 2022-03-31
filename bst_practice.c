#include <stdio.h>
#include <stdlib.h>

struct abc
{
     int data;
     struct abc *left, *right;
};

struct abc* insert(struct abc*, int);
struct abc* create(int);
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
         Root->right=insert(Root->right, d);
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
      postorder(Root->right);
      printf("%d ", Root->data);
}

int search(struct abc* Root, int f)
{
      if(Root==NULL)
      {
          return 0;
      }   
      else if(Root->data==f)
          return 1;
      else if(Root->data>f)
          search=search(Root->left, f);    
      else
          printf("Element not found.\n");
      
         
}
void main()
{
      struct abc* Root=NULL;
      int search;
      Root=insert(Root, 15);
      Root=insert(Root, 10);
      Root=insert(Root, 20);
      Root=insert(Root, 5);
      Root=insert(Root, 8);
      Root=insert(Root, 35);
      Root=insert(Root, 7);
      Root=insert(Root, 42);
      Root=insert(Root, 41);
      printf("Inorder Traversing:\n");
      inorder(Root);
      printf("\n");
      printf("Preorder Traversing:\n");
      preorder(Root);
      printf("\n");
      printf("Postorder Traversing:\n");
      postorder(Root);
      printf("\n");
      search(Root, 10);
      if(search==0)
            printf("The tree is empty.\n"); 
      if(search==1)
            printf("Element found.\n");  
      search(Root, 20);
      if(search==0)
            printf("The tree is empty.\n"); 
      if(search==1)
            printf("Element found.\n");             
}
