#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct dlist {
struct dlist*left,*right;
boolean lthread,rthread;
int info;
}node;
struct node *insert(struct node *root,int key) {
struct node *ptr=root;
struct node *par=NULL;
while(ptr!=NULL) {
if(key==(ptr->info)) {
printf("Duplicate key!");
return root;
}
par=ptr;
if(key<ptr->info) {
if(ptr->lthread==false)
ptr=ptr->left;
else
break;
}
else
{
if(ptr->rthread==false)
ptr=ptr->right;
else
break;
}
}
struct node* temp=new struct node;
temp->info=key;
temp->lthread=true;
temp->rthread=true;
if(par==NULL) {
root=temp;
temp->left=NULL;
temp->right=NULL;
}
else if(key<(par->info)) {
temp->left=par->left;
temp->right=par;
par->lthread=false;
par->left=temp;
}
else {
temp->left=par;
temp->right=par->right;
par->rthread=false;
par->right=temp;
}
return root;
}
struct node *inordersuccessor(struct node *ptr) {
if(ptr->rthread==true)
return ptr->right;
ptr=ptr->right;
while(ptr->lthread==false)
ptr=ptr->left;
return ptr;
}
void inorder(struct node  *root) {
if(root==NULL)
printf("Tree is empty");
struct node *ptr=root;
while(ptr->lthread==false)
ptr=ptr->left;
while(ptr!=NULL) {
printf("ptr"=inordersuccessor(ptr));
}
}
int main() {
struct node *root=NULL;
root=insert(root,5);
root=insert(root,3);
root=insert(root,7);
root=insert(root,4);
root=insert(root,6);
inorder(root);
return 0;
}