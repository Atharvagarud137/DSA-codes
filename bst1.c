#include <stdio.h>
#include <stdlib.h>

struct abc
{
     int data;
     struct abc *left, *right;
};

struct abc* insert(struct abc*, int);
struct abc* create(int);
struct abc* search(struct abc*, int);
struct abc* delete_node(struct abc*, int); 
struct abc* find_minimum(struct abc*);
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

struct abc* delete_node(struct abc *Root, int x)
{
    if(Root==NULL)
        return NULL;
    if (x>Root->data)
        Root->right = delete_node(Root->right, x);
    else if(x<Root->data)
        Root->left = delete_node(Root->left, x);
    else
    {
        if(Root->left==NULL && Root->right==NULL)
        {
            free(Root);
            return NULL;
        }

        else if(Root->left==NULL || Root->right==NULL)
        {
            struct abc* temp;
            temp=(struct abc*)malloc(sizeof(struct abc));
            if(Root->left==NULL)
                temp = Root->right;
            else
                temp = Root->left;
            free(Root);
            return temp;
        }

        else
        {
            struct abc *temp = find_minimum(Root->right);
            Root->data = temp->data;
            Root->right = delete_node(Root->right, temp->data);
        }
    }
    return Root;
}
struct abc* find_minimum(struct abc *Root)
{
    if(Root == NULL)
        return NULL;
    else if(Root->left != NULL) // node with minimum value will have no left child
        return find_minimum(Root->left); // left most element will be minimum
    return Root;
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

struct abc* search(struct abc* Root, int y)
{
  struct abc* p;
  p=(struct abc*)malloc(sizeof(struct abc));
  p->data=y;
  p->left=NULL;
  p->right=NULL;
  return p;
}

         
void main()
{
     struct abc *Root = NULL;
     int a,b,c,d,ch;
     printf("Welcome to binary search tree program!\n");
     do
     {
         printf("1. Create\t2.Search\t3.Insert\t4.Delete\t5.Display inorder\t6.Display preorder\t7.Display postorder\t8.Exit\n");
         printf("Enter your choice:\n");
         scanf("%d", &ch);
         switch(ch)
         {
          case 1:
                  printf("Enter a number to set as root of the tree:\n");
                  scanf("%d", &a);
                  Root = create(a);  
                  break;
          case 2:
                  printf("Enter a number to search in the binary tree:\n");
                  scanf("%d", &b);
                  Root = search(Root, b);
                  break;
          case 3: 
                  printf("Enter a number to insert in the binary tree:\n");
                  scanf("%d", &c);
                  Root = insert(Root, c);
                  break;
          case 4:
                  printf("Enter the number to be deleted from the tree:\n");
                  scanf("%d", &d);
                  Root = delete_node(Root, d);
                  break;
          case 5:
                  printf("Inorder traversing:\n");
                  inorder(Root);
                  break;
          case 6:
                  printf("Preorder traversing:\n");
                  preorder(Root);
                  break;
          case 7:
                  printf("Postorder traversing:\n");
                  postorder(Root);
                  break;
          case 8:
                  printf("You have chosen to exit the program. Thank you.\n");
                  break;
          default:
                  printf("Enter a valid choice.\n");
                  break;
        }
     }while(ch<8);
           
}   
