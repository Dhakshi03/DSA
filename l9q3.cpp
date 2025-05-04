#include <cstdio>
#include <cstdlib>
#include <iostream>

class tree
{
    struct node
    {
        int data;
        node* left;
        node* right;
    };

    struct node* root; //root should be a class member to be accessed

    public:
    //constructor
    tree()
    {
        root = NULL;
    }

    //Insert
    node* ins(node* root,int data)
    {
        
        if(root == NULL)
        {
            struct node* newnode = new struct node;
            newnode->data=data;
            newnode->left=NULL;
            newnode->right=NULL;
            return newnode;
        }
        else
        {
            if (data<=root->data)
            {
                root->left=ins(root->left,data);
                //We are assigning it to root->left as it initially stores NULL and now the newnode will be stored; 
                //to update the tree structure
            }
            else
            {
                root->right=ins(root->right,data);
            }
        }
        return root;
    }

    void insert(int data) //Calls insert function but doesn't require user to pass root in main()
    {
        root=ins(root, data);
    }

    //Inorder
    void inorder(node* root)
    {
        if(root!=NULL)
        {
            inorder(root->left);
            printf("%d ",root->data);
            inorder(root->right);
        }
    }

    void inorderdisplay() //this calls the recursive function but doesn't require user to pass root in main()
    {
        if (root!=NULL)
        {
            inorder(root);
        }
        else
        {
            printf("Empty Tree");
        }
    }

    //Preorder
    void preorder(node* root)
    {
        if(root==NULL)return; //To prevent function from crashing

        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }

    void preorderdisplay()
    {
        if(root!=NULL)
        {
            preorder(root);
        }
        else
        {
            printf("Empty Tree");
        }
    }

    //Postorder
    void postorder(node* root)
    {
        if(root==NULL)return; //To prevent function from crashing

        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }

    void postorderdisplay()
    {
        if(root!=NULL)
        {
            postorder(root);
        }
        else
        {
            printf("Empty Tree");
        }
    }

    //Search
    void search(node* root, int val)
    {
        if(root==NULL)
        {
            printf("\nNot Found!");
            return;
        } 

        if (root->data==val)
        {
            printf("\nFound!");
            return;
        }
        else
        {
            if (val<root->data)
            {
                search(root->left,val);
            }
            else
            {
                search(root->right, val);
            }
        }
        
        
    }

    void searchdisplay(int val)
    {
        if(root!=NULL)
        {
            search(root,val);
        }
        else
        {
            printf("\nEmpty Tree");
        }
    }

};

int main()
{
    tree t;

    int choice, data, val;

    while(1)
    {
        printf("\n1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Search\n6.Exit");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            //Insert
            printf("\nEnter data value: ");
            scanf("%d",&data);
            t.insert(data);
            break;

            case 2:
            //Preorder
            printf("\nPreorder traversal: \n");
            t.preorderdisplay();
            break;
            
            case 3:
            //Inorder
            printf("\nInorder traversal: \n");
            t.inorderdisplay();
            break;

            case 4:
            //Postorder
            printf("\nPostorder traversal: \n");
            t.postorderdisplay();
            break;
            
            case 5:
            //Search
            printf("\nEnter number you want to search: ");
            scanf("%d",&val);
            t.searchdisplay(val);
            break;

            case 6:
            //Exit
            exit(0);
        }
    }
    return 0;
}