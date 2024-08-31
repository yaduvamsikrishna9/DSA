/*Construct a Binary Search Tree and perform the following operations on it
a. Insert and element to the BST
b. Delete the element from BST
c. Search for an element in BST*/


#include <stdio.h>
#include <stdlib.h>
struct node {
	int key;
	struct node *left, *right;
};
struct node* newNode(int item){
	struct node* temp
		= (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
void inorder(struct node* root){
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}
void Postorder(struct node* root){
	if (root == NULL)
		return;
	Postorder(root->left);
	Postorder(root->right);
	printf("%d ", root->key);
}
void Preorder(struct node* root){
	if (root == NULL)
		return;
	printf("%d ", root->key);
	Preorder(root->left);
	Preorder(root->right);
}
struct node* insert(struct node* node, int key){
	if (node == NULL)
		return newNode(key);
	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);
	return node;
}
struct node* minValueNode(struct node* node){
	struct node* current = node;
	while (current && current->left != NULL)
		current = current->left;
	return current;
}
struct node* search(struct node* root, int key){
	if (root == NULL || root->key == key)
	return root;
	if (root->key < key)
	return search(root->right, key);
	return search(root->left, key);
}
struct node* deleteNode(struct node* root, int key){
	if (root == NULL)
		return root;
	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);
	else {
		if (root->left == NULL) {
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			struct node* temp = root->left;
			free(root);
			return temp;
		}
		struct node* temp = minValueNode(root->right);
		root->key = temp->key;
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}
int main(){
	struct node* root = NULL;
	root = insert(root, 50);
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 70);
	root = insert(root, 60);
	root = insert(root, 80);
	printf("Inorder traversal of the given tree   : ");
	inorder(root);
	printf("\nPreorder traversal of the given tree  : ");
	Preorder(root);
	printf("\nPostorder traversal of the given tree : ");
	Postorder(root);
	printf("\nDelete 20\n");
	root = deleteNode(root, 20);
	printf("Inorder traversal of updated tree     :");
	inorder(root);
	printf("\nPreorder traversal of updated tree    : ");
	Preorder(root);
	printf("\nPostorder traversal of updated tree   : ");
	Postorder(root);
	printf("\nDelete 30\n");
	root = deleteNode(root, 30);
	printf("Inorder traversal of updated tree     : ");
	inorder(root);
	printf("\nPreorder traversal of updated tree    : ");
	Preorder(root);
	printf("\nPostorder traversal of updated tree   : ");
	Postorder(root);
	printf("\nDelete 50\n");
	root = deleteNode(root, 50);
	printf("Inorder traversal  of updated tree    : ");
	inorder(root);
	printf("\nPreorder traversal of updated tree    : ");
	Preorder(root);
	printf("\nPostorder traversal of updated tree   : ");
	Postorder(root);
	search(root, 60);
	return 0;
}
