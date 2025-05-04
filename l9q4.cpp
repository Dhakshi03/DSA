#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <cctype>


class Tree
{
    struct node
    {
        char data;
        struct node* left;
        struct node* right;
    } *root;

public:
    Tree()
    {
        root = nullptr;
    }

    void inorder(node* root)
    {
        if (root != nullptr)
        {
            inorder(root->left);
            printf("%c ", root->data);
            inorder(root->right);
        }
    }

    void inorder()
    {
        inorder(root);
    }

    void preorder(node* root)
    {
        if (root != nullptr)
        {
            printf("%c ", root->data);
            preorder(root->left);
            preorder(root->right);
        }
    }

    void preorder()
    {
        preorder(root);
    }

    void postorder(node* root)
    {
        if (root != nullptr)
        {
            postorder(root->left);
            postorder(root->right);
            printf("%c ", root->data);
        }
    }

    void postorder()
    {
        postorder(root);
    }

    void createTree(char postfix[])
    {
        std::stack<node*> s;
        int len = strlen(postfix);

        for (int i = 0; i < len; i++)
        {
            if (isdigit(postfix[i]))
            {
                struct node* newnode = new struct node;
                newnode->data = postfix[i];
                newnode->left = nullptr;
                newnode->right = nullptr;
                s.push(newnode);
            }
            else
            {
                struct node* newnode = new struct node;
                newnode->data = postfix[i];
                newnode->right = s.top();
                s.pop();
                newnode->left = s.top();
                s.pop();
                s.push(newnode);
            }
        }
        root = s.top();
    }
};

int main()
{
    int exit = 0;
    Tree t;
    char postfix[100];

    while (exit != 1)
    {
        printf("1.Postfix Expression\n2.Create Expression Tree\n3.Inorder\n4.Preorder\n5.Postorder\n6.Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter postfix expression: ");
                scanf("%s", postfix);
                break;
            case 2:
                t.createTree(postfix);
                printf("Expression tree created\n");
                break;
            case 3:
                printf("Inorder Traversal: ");
                t.inorder();
                printf("\n");
                break;
            case 4:
                printf("Preorder Traversal: ");
                t.preorder();
                printf("\n");
                break;
            case 5:
                printf("Postorder Traversal: ");
                t.postorder();
                printf("\n");
                break;
            case 6:
                exit = 1;
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
