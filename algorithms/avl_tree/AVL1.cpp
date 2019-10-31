#include<iostream>

using namespace std;


    struct node
    {
        int data;
        node* left;
        node* right;
        int height;
    };

    node* root;

    void makeEmpty(node* t)
    {
        if(t == NULL)
            return;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    int height(node* t)
    {
        return (t == NULL ? -1 : t->height);
    }

    int getBalance(node* t)
    {
        if(t == NULL)
            return 0;
        else
            return height(t->left) - height(t->right);
    }

    node* singleRightRotate(node* &t)
    {
        node* u = t->left;
        t->left = u->right;
        u->right = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(u->left), t->height)+1;
        return u;
    }

    node* singleLeftRotate(node* &t)
    {
        node* u = t->right;
        t->right = u->left;
        u->left = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(t->right), t->height)+1 ;
        return u;
    }

    node* doubleLeftRotate(node* &t)
    {
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }

    node* doubleRightRotate(node* &t)
    {
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }

    node* insert(int x, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->height = 0;
            t->left = t->right = NULL;
        }
        else if(x < t->data)
        {
            t->left = insert(x, t->left);
            if(height(t->left) - height(t->right) == 2)
            {
                if(x < t->left->data)
                    t = singleRightRotate(t);
                else
                    t = doubleRightRotate(t);
            }
        }
        else if(x > t->data)
        {
            t->right = insert(x, t->right);
            if(height(t->right) - height(t->left) == 2)
            {
                if(x > t->right->data)
                    t = singleLeftRotate(t);
                else
                    t = doubleLeftRotate(t);
            }
        }

        t->height = max(height(t->left), height(t->right))+1;
        return t;
    }
 
    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node* findMax(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    node* remove(int x, node* t)
    {
        node* temp;

        // Element not found
        if(t == NULL)
            return NULL;

        // Searching for element
        else if(x < t->data)
            t->left = remove(x, t->left);
        else if(x > t->data)
            t->right = remove(x, t->right);

        // Element found
        // With 2 children
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        // With one child
        else if(t->left || t->right)
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }
       // else //for leaf node
        
        if(t == NULL)
           return t;

        t->height = max(height(t->left), height(t->right))+1;

        // If node is unbalanced
        // If left node is deleted, right case
        if(height(t->left) - height(t->right) == 2)
        {
            // right right case
            if(height(t->left->left) - height(t->left->right) == 1)
                return singleLeftRotate(t);
            // right left case
            else
                return doubleLeftRotate(t);
        }
        // If right node is deleted, left case
        else if(height(t->right) - height(t->left) == 2)
        {
            // left left case
            if(height(t->right->right) - height(t->right->left) == 1)
                return singleRightRotate(t);
            // left right case
            else
                return doubleRightRotate(t);
        }
        return t;
    }

    void inorder(node* t)
    {
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

    void preorder(node* t)
    {
        if(t==NULL)
            return;
        cout<<t->data<<" ";
        preorder(t->left);
        preorder(t->right);
    }

    node * Find(node *t, int data)
{
    if(t==NULL)
    {
        /* Element is not found */
        return NULL;
    }
    if(data > t->data)
    {
        /* Search in the right sub tree. */
        return Find(t->right,data);
    }
    else if(data < t->data)
    {
        /* Search in the left sub tree. */
        return Find(t->left,data);
    }
    else
    {
        /* Element Found */
        return t;
    }
}
   node* successor(node *root){
    if(root==NULL)
        return NULL;

    node* temp = root->right;
    if(temp== NULL)
    {
        return root->left;
    }

    /* this block not required
    if(temp->left == NULL)
    {
            return temp; //********here we should return temp and not NULL
    }
    */
    while(temp->left!= NULL)
    {
            temp=temp->left;
    }
    return temp;
    
}
node* predecessor(node *root)
{
    if(root== NULL)
    {
        return NULL;
    }
    node* temp = root->left;
    if(temp== NULL)
    {
        return root->right;
    }
    /*
    if(temp->right == NULL)
    {
            return NULL;
    }
    */
    while(temp->right!= NULL)
    {
            temp=temp->right;
    }
    return temp;    
}



    /*void insert(int x)
    {
        root = insert(x, root);
    }

    void remove(int x)
    {
        root = remove(x, root);
    }

    void display()
    {
        cout<<" The inorder traversal is :\n";
        inorder(root);
        cout<<"\nThe preorder traversal is:\n ";
        preorder(root);
        cout << endl;
    }*/


int main()
{
    node *root = NULL,*temp;
    int c,ch;
    while(1)
    {
        cout<<"\n1.Insert\n2.Delete\n3.Inorder\n4.Preorder\n5.Exit\n6.FindMin\n7.FindMax\n8.Search\n9.Predecessor & Successor\n";
        cout<<"Enter your choice:";
        cin>>c;
        switch(c)
        {
        case 1:
            cout<<"\nEnter element to be insert:";
            cin>>ch;
            root=insert(ch,root);
            cout<<"\nElements in AVL are:";
            inorder(root);
            break;
        case 2:
            cout<<"\nEnter element to be deleted:";
            cin>>ch;
            root=remove(ch,root);
            cout<<"\nAfter deletion elements in AVL are:";
            inorder(root);
            break;
        case 3:
            cout<<"\nInorder Traversal is:";
            inorder(root);
            break;
        case 4:cout<<"\nPreorder Traversal is:";
            preorder(root);
            break;
        case 5:
            cout<<"You are exiting the program...";
            exit(0);
            break;
        case 6:
            temp = findMin(root);
            cout<<"\nMinimum element is :"<<temp->data;
            break;
        case 7:
            temp = findMax(root);
            cout<<"\nMaximum element is :"<<temp->data;
            break;
        case 8:
            cout<<"\nEnter element to be searched:";
            cin>>ch;
            temp = Find(root,ch);
            if(temp==NULL)
            {
                cout<<"Element is not found";
            }
            else
            {
                cout<<"Element "<<temp->data<<" is Found\n";
            }
            break;

        case 9: 
                temp = successor(root);
                //************if condition added**********
                if(temp!=NULL)
                    cout<<"The successor of the root is:"<< temp->data<<endl;
                temp = predecessor(root);
                //************if condition added**********
                if(temp!=NULL)
                    cout<<"The predecessor of the root is:"<< temp->data;
                break;
        default:
            cout<<"\nEnter correct choice:";
            break;
    
}    
}
}