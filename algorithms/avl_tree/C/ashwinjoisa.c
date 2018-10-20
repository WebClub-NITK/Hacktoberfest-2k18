//AVL Tree - Insertion, Deletion, Search

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max(a, b) (a>b ? a:b)

typedef struct tree_node
{
	int data;
	struct tree_node *left, *right;
	int height;
}node;

node *get_new_node(int num)
{
	node *cur = (node *)malloc(sizeof(node));
	cur->data = num;
	cur->left = cur->right = NULL;
	cur->height = 1;
	return cur;
}

int height(node *cur)
{
	if(cur==NULL)
		return 0;
	return cur->height;
}

node *rotate_right(node *cur)
{
	node *x, *y;
	x = cur->left;
	y = x->right;

	//Rotate
	x->right = cur;
	cur->left = y;

	//Update height
	cur->height = max(height(cur->left), height(cur->right)) +1;
	x->height = max(height(x->left), height(x->right)) +1;

	return x;
}

node *rotate_left(node *cur)
{
	node *x, *y;
	x = cur->right;
	y = x->left;

	//Rotate
	x->left = cur;
	cur->right = y;

	//Update height
	cur->height = max(height(cur->left), height(cur->right)) +1;
	x->height = max(height(x->left), height(x->right)) +1;

	return x;
}

int balance_factor(node *cur)
{
	if(cur==NULL)
		return 0;
	return height(cur->left) - height(cur->right);
}

node *min_node(node *cur)
{
	//Non-empty tree
	node *temp;
	while(temp->left != NULL)
		temp = temp->left;
	return temp;
}

node *insert(node *cur, int num)
{
	int bal;

	if(cur == NULL)
		return get_new_node(num);

	if(num < cur->data)
		cur->left = insert(cur->left, num);
	else if(num > cur->data)
		cur->right = insert(cur->right, num);
	else //Invalid
		return cur;

	//After Insertion
	cur->height = max(height(cur->left), height(cur->right)) +1;
	bal = balance_factor(cur);

	//Rotations
	if(bal > 1 && num < cur->left->data)
	{
		//Left-Left
		return rotate_right(cur);
	}
	else if(bal < -1 && num > cur->right->data)
	{
		//Right-Right
		return rotate_right(cur);
	}
	else if(bal > 1 && num > cur->left->data)
	{
		//Left-Right
		cur->left = rotate_left(cur->left);
		return rotate_right(cur);
	}
	else if(bal < -1 && num < cur->right->data)
	{
		//Right-Left
		cur->right = rotate_right(cur->right);
		return rotate_left(cur);
	}
	else //Still Balanced
		return cur;
}

node *delete(node *cur, int num)
{
	int bal;

	if(cur==NULL)
		return cur;

	if(num < cur->data)
		cur->left = delete(cur->left, num);
	else if(num > cur->data)
		cur->right = delete(cur->right, num);
	else
	{
		//Node to delete
		node *temp;
		if(cur->left == NULL || cur->right == NULL)
		{
			//One or no children.
			if(cur->left == NULL)
				temp = cur->right;
			else
				temp = cur->left;

			if(temp == NULL)
			{
				//No Child
				temp = cur;
				cur = NULL;
			}
			else
			{
				//One Child
				//Copy contents of temp to cur
				cur->data = temp->data;
				cur->left = temp->left;
				cur->right = temp->right;
				cur->height = temp->height;
			}
			free(temp);
		}
		else
		{
			//Two Children
			temp = min_node(cur->right);
			cur->data = temp->data; //Height will be updated...
			cur->right = delete(cur->right, temp->data);
		}
	}

	//After Deletion
	if(cur == NULL)
		return cur;

	cur->height = max(height(cur->left), height(cur->right)) +1;
	bal = balance_factor(cur);

	//Rotations
	if(bal > 1 && balance_factor(cur->left) >= 0)
	{
		//Left-Left
		return rotate_right(cur);
	}
	else if(bal > 1)
	{
		//Left-Right
		cur->left = rotate_left(cur->left);
		return rotate_right(cur);
	}
	else if(bal < -1 && balance_factor(cur->right) <= 0)
	{
		//Right-Right
		return rotate_left(cur);
	}
	else if(bal < -1)
	{
		//Right-Left
		cur->right = rotate_right(cur->right);
		return rotate_left(cur);
	}
	else //Still Balanced
		return cur;
}

int search(node *cur, int num)
{
	if(cur == NULL)
		return 0;
	if(cur->data == num)
		return 1;
	if(num < cur->data)
		return search(cur->left, num);
	if(num > cur->data)
		return search(cur->right, num);
}

void print_tree(node *cur)
{
	int flag=0;

	if(cur==NULL)
	{
		printf("#");
		return;
	}

	printf("%d", cur->data);

	if(cur->left)
	{
		printf("(");
		print_tree(cur->left);
		flag=1;
	}
	if(cur->right)
	{
		if(!flag)
			printf("(#,");
		else
			printf(",");

		print_tree(cur->right);
		flag=2;
	}

	if(flag==1)
		printf(",#");

	if(flag)
		printf(")");
}

void main()
{
	int ch;
	node *root = NULL;

	do
	{
		printf("\nCurrent tree : ");
		print_tree(root);
		printf("\n");

		printf("\n1. Insert node\n2. Delete node\n3. Search node\nx. Exit");
		printf("\nEnter your choice : ");
		scanf("%d", &ch);

		if(ch==1)
		{
			printf("\nEnter data : ");
			scanf("%d", &ch);

			root = insert(root, ch);

			ch=1;
		}
		else if(ch==2)
		{
			printf("\nEnter data to delete : ");
			scanf("%d", &ch);

			root = delete(root, ch);

			ch=2;
		}
		else if(ch==3)
		{
			printf("Enter data to search : ");
			scanf("%d", &ch);

			if(search(root, ch))
				printf("Element present\n");
			else
				printf("Element not present\n");

			ch=3;
		}
	}while(ch>=1 && ch<=3);
}
 
/* 
	Test case 
	1 9 1 5 1 10 1 0 1 6 1 11 1 -1 1 1 1 2 2 10 

	//Constructing tree given in the above figure 
	root = insert(root, 9);
	root = insert(root, 5);
	root = insert(root, 10);
	root = insert(root, 0);
	root = insert(root, 6);
	root = insert(root, 11);
	root = insert(root, -1);
	root = insert(root, 1);
	root = insert(root, 2);

	The constructed AVL Tree would be
	      9
	     /  \
	    1    10
	   /  \    \
	  0    5    11
	 /    /  \
	-1   2    6


	root = deleteNode(root, 10);
	The AVL Tree after deletion of 10
	     1
	    /  \
	   0    9
	  /    /  \
	-1   5     11
	    /  \
	   2    6
*/