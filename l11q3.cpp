// Separate Chaining without 'new'
#include<iostream>
#include<cstdio>
#define tsize 10
#define max_nodes 100

struct Node {
    int key;
    int next; // Index to next node in the pool
};

class hash {
private:
    int head[tsize];       
    Node pool[max_nodes];  
    int free_index;        
public:
    hash() {
        for (int i = 0; i < tsize; i++) {
            head[i] = -1;
        }
        for (int i = 0; i < max_nodes; i++) {
            pool[i].key = -1;
            pool[i].next = -1;
        }
        free_index = 0;
    }

    int hashf(int key) {
        return key % tsize;
    }

    void insert(int key) {
        int index = hashf(key);
        pool[free_index].key = key;
        pool[free_index].next = head[index];
        head[index] = free_index;
        free_index++;

        printf("Inserted!\n");
    }

    int del_h(int key) {
        int index = hashf(key);
        int curr = head[index];
        int prev = -1;

        while (curr != -1) {
            if (pool[curr].key == key) {
                if (prev == -1) {
                    head[index] = pool[curr].next;
                } else {
                    pool[prev].next = pool[curr].next;
                }
                printf("Deleted!\n");
                return 1;
            }
            prev = curr;
            curr = pool[curr].next;
        }
        printf("Not found!\n");
        return 0;
    }

    int search(int key) {
        int index = hashf(key);
        int curr = head[index];

        while (curr != -1) {
            if (pool[curr].key == key) {
                printf("Found!\n");
                return 1;
            }
            curr = pool[curr].next;
        }

        printf("Not found!\n");
        return 0;
    }

    void display() {
        bool empty = true;
        for (int i = 0; i < tsize; i++) {
            if (head[i] != -1) {
                empty = false;
                break;
            }
        }

        if (empty) {
            printf("Hash table is empty!\n");
            return;
        }

        for (int i = 0; i < tsize; i++) {
            printf("[%d]: ", i);
            int curr = head[i];
            if (curr == -1) {
                printf("Empty");
            } else {
                while (curr != -1) {
                    printf("%d -> ", pool[curr].key);
                    curr = pool[curr].next;
                }
                printf("NULL");
            }
            printf("\n");
        }
    }
};


int main(){
    hash ht;
    int choice,key;
    while(1){
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Search\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the key to be inserted: ");
                scanf("%d",&key);
                ht.insert(key);
                break;
            case 2:
                printf("Enter the key to be  deleted: ");
                scanf("%d",&key);
                ht.del_h(key);
                break;
            case 3:
                ht.display();
                break;
            case 4:
                printf("Enter the key to be searched: ");
                scanf("%d",&key);
                ht.search(key);
                break;
            case 5:
                printf("Exited!\n");
                return 0;
                break;
                
            default:
                printf("Enter valid choice!\n");
                break;
        }
    }
}