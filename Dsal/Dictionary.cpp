// A dictionary stores keywords and its meanings,, Now provides facility for adding new keywords,, deleting keywords, and updating values of any entry. Also provies facility to display whole data strored in ascending/ descending order also we have to find how many maximum comparisions may require for finding any keyword.

#include <iostream>
#include<bits/stdc++.h>
#include <string.h>

using namespace std;

class node
{
public:
    node *left;
    node *right;
    char word[50];
    char mean[50];
};

class BST
{
public:
    node *root;

    BST()
    {
        root = NULL;
    }

    void create();
    node *insert(node *, node *);
    void preorder(node *);
    void postorder(node *);
    void inorder(node *);

    node *largest(node *);
    node *smallest(node *);

    void search(node *, char[]);
    void update(node *, char[]);
};

void BST::create()
{
    int c;
    node *temp;

    do
    {
        temp = new node();
        cout << "Enter the word " << endl;
        cin >> temp->word;

        cout << "Enter the meaning" << endl;
        cin >> temp->mean;
        temp->left = NULL;
        temp->right = NULL;

        if (root == NULL)
        {
            root = temp;
        }
        else
        {
            root = insert(root, temp);
        }
        cout << "want to insert again(Any Number except -ve) Enter -1 to terminate" << endl;
        
        cin >> c;
    } while (c != -1);
}

node *BST::insert(node *root, node *temp)
{
    int len = min(strlen(temp->word), strlen(root->word));
    //  int l1=strlen(temp -> word);
    // int l2= strlen(root -> word);

    /* if(l1 > l2){
         len = l2;
     }
     else{
         len = l1;
     }*/
    for (int i = 0; i < len; i++)
    {
        if (root->word[i] > temp->word[i])
        {
            if (root->left == NULL)
            {
                root->left = temp;
                return root;
            }
            else
            {
                root->left = insert(root->left, temp);
                return root;
            }
        }

        else if (root->word[i] < temp->word[i])
        {
            if (root->right == NULL)
            {
                root->right = temp;
                return root;
            }
            else
            {
                root->right = insert(root->right, temp);
                return root;
            }
        }
    }
    return root;
}

void BST::inorder(node *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        cout <<" "<< temp->word << " " << temp->mean;
        inorder(temp->right);
    }
}

void BST::preorder(node *temp)
{
    if (temp != NULL)
    {
        cout <<" "<< temp->word << " " << temp->mean;
        preorder(temp->left);
        preorder(temp->right);
    }
}

void BST::postorder(node *temp)
{
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout <<" "<< temp->word << " " << temp->mean;
    }
}

node* BST::smallest(node *root)
{
    if (root->left == NULL)
    {
        cout << "\n\n Smallest Node:" << root->word;
        return root;
    }
    else
    {
        return smallest(root->left);
    }
}

node* BST::largest(node *root)
{
    if (root->right == NULL)
    {
        cout << "\n\n Largest Node:" << root->word;
        return root;
    }
    else
    {
        return largest(root->right);
    }
}

void BST ::search(node *temp, char s[])

{
    if (temp != NULL)
    {
        if (strcmp(temp->word, s) == 0)
        {
            cout << "Word found " << endl;
            cout << "Word: " << temp->word << endl;
            cout << "Meaning: " << temp->mean << endl;
        }
        else if (strcmp(temp->word, s) != 0)
        {

            if ((strcmp(temp->word, s)) > 0)
            {
                search(temp->left, s);
            }
            else if ((strcmp(temp->word, s)) < 0)
            {
                search(temp->right, s);
            }
        }
    }
    else
    {
        cout << "word not Found" << endl;
    }
}

void BST ::update(node *temp, char s[])
{
    if (temp != NULL)
    {
        if (strcmp(temp->word, s) == 0)
        {
            cout << "Word found " << endl;
            cout << "Enter the new meaning of Word: " << temp->word << endl;
            cin >> temp->mean;
        }
        else if (strcmp(temp->word, s) != 0)
        {

            if ((strcmp(temp->word, s)) > 0)
            {
                search(temp->left, s);
            }
            else if ((strcmp(temp->word, s)) < 0)
            {
                search(temp->right, s);
            }
        }
    }
    else
    {
        cout << "word not Found" << endl;
    }
}

int main()
{
    BST b;
    int op;
    char src[100];
    while (true)
    {
        cout << "\n ";
        cout << "\n 1. Insert Binary Search Tree ";
        cout << "\n 2. Display Inorder,preorder and postorder ";
        cout << "\n 3. Search The Word ";
        cout << "\n 4. Modify The Meaning Of Word ";
        cout << "\n 5. Largest and Smallest Node ";
        cout << "\n 6.Exit\n";
        cout << "\n Enter your choice:";
        cin >> op;
        switch (op)
        {
        case 1:
            b.create();
            break;

        case 2:
            cout << "\n Inorder : ";
            b.inorder(b.root);
            cout << "\n Preorder : ";
            b.preorder(b.root);
            cout << "\n Postorder : ";
            b.postorder(b.root);
            break;

        case 3:
            cout << "\n Enter The Word Want To Search : ";
            cin >> src;
            b.search(b.root, src);
            break;

        case 4:
            cout << "\n Enter The Word Want To Modify ";
            cin >> src;
            b.update(b.root, src);
            break;

        case 5:
            b.smallest(b.root);
            b.largest(b.root);
            break;

        case 6:
            exit(0);
            break;

        default:
            cout << "\n Invalid Option ";
            break;
        }
    }
}
