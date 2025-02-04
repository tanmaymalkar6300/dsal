// Begining with an empty binary search tree, construct a BST by inserting the values in the values in the order given after constructing.
//  1) Insert new code
//  2) Find number of nodes in longest path
//  3) Min data found in the tree.....
//  4) search the value....

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class node
{
public:
    int key;
    node *left;
    node* right;
};

class tree{
public:
node* root;

node* createtree(int v){
    root  =  new node();
    root ->key = v;
    root -> left = NULL;
    root -> right = NULL;
    return root;
}

void insertnode(int v,node* root){
    node* r = new node();
    r -> key = v;
    if(root->key > v){
        if(root -> left == NULL){
            root -> left = r;
        }
        else{
            insertnode(v , root -> left);
        }
    }

    else if(root->key < v){
        if(root -> right == NULL){
            root -> right = r;
        }
        else{
            insertnode(v , root -> right);
        }
    }
    else{
        cout<<"No duplicates are allowed"<<endl;
    }
}

int height(node* root){
    if(root==NULL){
       return 0;
    }
    int l = height(root -> left);
    int r = height(root -> right);
    return max(l,r)+1;
}


void display(node* root){
if(root!=NULL){
    display(root ->left);
    cout<<root -> key<<" ";
    display(root -> right);
}

}


void displaymin(node* root){

    while(root-> left!=NULL){
        root = root -> left;
    }
    cout<<"Minimum data value present in tree  "<<root ->key<<endl;

}
    
    void displaymax(node* root){

    while(root-> right!=NULL){
        root = root -> right;
    }
    cout<<"Maximum data value present in tree  "<<root ->key<<endl;

}

node* swapnode(node* root){

    node* temp;
    if(root == NULL){
        return NULL;
    }

    temp = root -> left;
    root -> left = root -> right;
    root -> right = temp;

    swapnode(root -> left);
    swapnode(root -> right);
 return 0;
}


};


int main()
{
    int choice, flag=0;
    int key;
    tree t1;
    node* root;

    do{
        cout<<"\n\noperations"<<endl;  
        cout<<"1.enter the number"<<endl;
        cout<<"2.display tree"<<endl;
        cout<<"3.display min"<<endl;
        cout<<"4.swapnode"<<endl;
        cout<<"5.height "<<endl;
        cout<<"6.exit"<<endl;
        cout<<"\nEnter choice : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
        cout<<endl;
            cout<<"enter the number"<<endl;
            cin>>key;
            if(flag==0){
                root = t1.createtree(key);
                flag=1;
            }
            else{
                t1.insertnode(key, root);
            }
            break;

            case 2:
                cout<<endl;
              t1.display(root);
              cout<<endl;
              break;
            
            case 3:
            t1.displaymin(root);
            break;

            case 4:
            t1.swapnode(root);
            cout<<"after traversal"<<endl<<endl;
            t1.display(root);
            cout<<endl;
            break;
          
            case 5:
          //  root = new node();
            cout<<"height is: "<<t1.height(root)<<endl;
            break;

            default:
              break;
              
        }
    }while(choice!=6);
}