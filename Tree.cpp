#include <stdio.h>
#include <stdlib.h>
// Structure for a node in the binary tree
struct Node 
{
	int data;
	struct Node* left;
	struct Node* right;
};
// Function to create a new node
struct Node* createNode(int data) 
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 	newNode->data = data;
 	newNode->left = newNode->right = NULL;
 	return newNode;
}
// Function to insert a node in the binary tree
struct Node* insert(struct Node* root, int data) 
{
 	if (root == NULL) {
 	root = createNode(data);
 	return root;
 }

 if (data < root->data)
 	root->left = insert(root->left, data);
 else
 	root->right = insert(root->right, data);

 return root;
}
// Function to find the minimum value node
struct Node* findMin(struct Node* node) 
{
	struct Node* current = node;
	while (current && current->left != NULL)
		current = current->left;
	return current;
}
// Function to delete a node from the binary tree
struct Node* deleteNode(struct Node* root, int data) 
{
	if (root == NULL) return root;
	if (data < root->data)
		root->left = deleteNode(root->left, data);
	else if (data > root->data)
		root->right = deleteNode(root->right, data);
	else 
	{
		if (root->left == NULL) 
		{
			struct Node* temp = root->right;
			free(root);
		return temp;
	 	}
 		else if (root->right == NULL) 
		{
 			struct Node* temp = root->left;
 			free(root);
 			return temp;
 		}

 	struct Node* temp = findMin(root->right);
 	root->data = temp->data;
 	root->right = deleteNode(root->right, temp->data);
 }
 return root;
}
// Inorder traversal (Left, Root, Right)
void inorder(struct Node* root) 
{
 	if (root != NULL) 
	{
 		inorder(root->left);
 		printf("%d ", root->data);
 		inorder(root->right);
	}
}
// Preorder traversal (Root, Left, Right)
void preorder(struct Node* root) 
{
 	if (root != NULL) 
	{
 		printf("%d ", root->data);
 		preorder(root->left);
 		preorder(root->right);
 	}
}
// Postorder traversal (Left, Right, Root)
void postorder(struct Node* root) 
{
	 if (root != NULL) 
	{
 		postorder(root->left);
 		postorder(root->right);
 		printf("%d ", root->data);
 	}
}
int main() 
{
	struct Node* root = NULL;

 // Inserting nodes
 	root = insert(root, 50);
 	root = insert(root, 30);
 	root = insert(root, 20);
 	root = insert(root, 40);
 	root = insert(root, 70);
 	root = insert(root, 60);
 	root = insert(root, 80);
 	printf("Inorder traversal: ");
 	inorder(root);
 	printf("\n");
 	printf("Preorder traversal: ");
 	preorder(root);
 	printf("\n");
 	printf("Postorder traversal: ");
 	postorder(root);
 	printf("\n");
 // Deleting a node
 	printf("Deleting 20\n");
 	root = deleteNode(root, 20);
 	printf("Inorder traversal after deletion: ");
 	inorder(root);
 	printf("\n");
 	return 0;
}
