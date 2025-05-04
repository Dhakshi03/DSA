#include <iostream>

using namespace std;

class tree {
    struct node {
        int data;
        struct node *left, *right;
    } *root;

public:
    tree() { root = NULL; }

    // Function to create a new node
    node* create(int num) {
        node* newnode = new node; // Use 'new' instead of malloc
        newnode->data = num;
        newnode->left = newnode->right = NULL;
        return newnode;
    }

    // Recursive insert function
    node* insertrec(node* root, int num) {
        if (root == NULL) {
            return create(num);  // Fix: Assign the created node
        }

        int choice;
        printf("1. Left or 2. Right (1/2): ");
        scanf("%d", &choice);

        if (choice == 1) {
            root->left = insertrec(root->left, num);
        } else if (choice == 2) {
            root->right = insertrec(root->right, num);
        } else {
            printf("Invalid choice! Try again.\n");
        }
        return root;
    }

    // Insert function
    void insert(int num) {
        root = insertrec(root, num);
    }
    
    //Preorder traversal
    void preorderec(struct node *root){
        if(root!=NULL){
            printf("%d ",root->data);
            preorderec(root->left);
            preorderec(root->right);
        }
    }
    void preorder(){
        if(root==NULL){
            printf("Tree is empty!\n");
        }
        else{
            printf("Preorder traversal: ");
            preorderec(root);
            printf("\n");
        }
    }

    // Inorder traversal 
    void inorderec(struct node *root) {
        if (root != NULL) {
            inorderec(root->left);  
            printf("%d ", root->data);
            inorderec(root->right);
        }
    }

    void inorder() {
        if (root == NULL) {
            printf("Tree is empty.\n");
        } else {
            printf("Inorder Traversal: ");
            inorderec(root);
            printf("\n");
        }
    }
    
    //Postorder traversal
    void postorderec(struct node *root){
        if(root!=NULL){
            postorderec(root->left);
            postorderec(root->right);
            printf("%d ",root->data);
        }
    }
    void postorder(){
        if(root==NULL){
            printf("Tree is empty!\n");
        }
        else{
            printf("Postorder traversal: ");
            postorderec(root);
            printf("\n");
        }
    }
    
    //search
    bool searchRec(node* root, int key) {
    
    if (root == NULL) {
        return false;
    }
    if (root->data == key) {
        return true;
    }

    
    bool foundInLeft = searchRec(root->left, key);
    bool foundInRight = searchRec(root->right, key);

    return foundInLeft || foundInRight; 
}

// Wrapper function to search a value in the tree
bool search(int key) {
    return searchRec(root, key);
}

    
};

int main() {
    tree t1;
    int choice, num,key;

    while (1) {
        printf("\n1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number to be inserted: ");
                scanf("%d", &num);
                t1.insert(num);  
                printf("Inserted successfully!\n");
                break;
            case 2:
                t1.preorder();
                break;
            case 3:
                t1.inorder();
                break;
            case 4:
                t1.postorder();
                break;
            case 5:
                printf("Enter the element to search: ");
                scanf("%d",&key);
                if(t1.search(key)){
                    printf("Found!\n");
                }
                break;
            case 6:
                printf("Exited!\n");
                return 0;
            default:
                printf("Enter a valid choice!\n");
                break;
        }
    }

    return 0;
}



