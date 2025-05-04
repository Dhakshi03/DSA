// #include <iostream>
// using namespace std;
// #define MAX 50

// class graph
// {
//     private:
//     struct node
//     {
//         int*weight;
//         struct node* next;
//     };

//     public:
//     node* adjlist[MAX];

//     //insert
//     void insert(int vertex)
//     {
        
//     }
// };

#include <iostream>
using namespace std;

#define MAX 5

class Graph {
    struct Node {   
        int data;
        Node* next;
        Node(int d) : data(d), next(nullptr) {}
    };

    Node* arr[MAX];

public:
    Graph() {
        for (int i = 0; i < MAX; i++) {
            arr[i] = nullptr;
        }
    }

    void insertEdge(int source, int dest) {
        if (source >= MAX || dest >= MAX || source < 0 || dest < 0) {
            cout << "\nInvalid source or destination\n";
            return;
        }

        // Add edge from source to dest
        Node* newNode1 = new Node(dest);
        newNode1->next = arr[source];
        arr[source] = newNode1;

        // Add edge from dest to source (undirected graph)
        Node* newNode2 = new Node(source);
        newNode2->next = arr[dest];
        arr[dest] = newNode2;

        cout << "\nEdge added successfully!\n";
    }

    void deleteEdge(int source, int dest) {
        if (source >= MAX || dest >= MAX || source < 0 || dest < 0) {
            cout << "\nInvalid source or destination\n";
            return;
        }

        // Remove dest from source list
        Node* prev = nullptr;
        Node* curr = arr[source];
        while (curr != nullptr && curr->data != dest) {
            prev = curr;
            curr = curr->next;
        }
        if (curr != nullptr) {
            if (prev == nullptr) 
            {
                arr[source] = curr->next;
            }
            else 
            {
                prev->next = curr->next;
            }
            delete curr;
        }

        // Remove source from dest list
        prev = nullptr;
        curr = arr[dest];
        while (curr != nullptr && curr->data != source) {
            prev = curr;
            curr = curr->next;
        }
        if (curr != nullptr) {
            if (prev == nullptr) arr[dest] = curr->next;
            else prev->next = curr->next;
            delete curr;
        }

        cout << "\nEdge deleted successfully!\n";
    }

    void searchEdge(int source, int dest) {
        if (source >= MAX || dest >= MAX || source < 0 || dest < 0) {
            cout << "\nInvalid source or destination\n";
            return;
        }

        Node* temp = arr[source];
        while (temp != nullptr) {
            if (temp->data == dest) {
                cout << "\nEdge exists between " << source << " and " << dest << ".\n";
                return;
            }
            temp = temp->next;
        }

        cout << "\nNo edge found between " << source << " and " << dest << ".\n";
    }

    void display() {
        cout << "\nGraph (Adjacency List Representation):\n";
        for (int i = 0; i < MAX; i++) {
            cout << i << " -> ";
            Node* temp = arr[i];
            while (temp) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << "\n";
        }
    }
};

int main() {
    Graph g;
    int choice, source, dest;

    while (true) {
        cout << "\n1. Insert an edge\n2. Delete an edge\n3. Search an edge\n4. Display graph\n5. Exit";
        cout << "\nENTER YOUR CHOICE: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter source: ";
                cin >> source;
                cout << "Enter destination: ";
                cin >> dest;
                g.insertEdge(source, dest);
                break;

            case 2:
                cout << "Enter source: ";
                cin >> source;
                cout << "Enter destination: ";
                cin >> dest;
                g.deleteEdge(source, dest);
                break;

            case 3:
                cout << "Enter source: ";
                cin >> source;
                cout << "Enter destination: ";
                cin >> dest;
                g.searchEdge(source, dest);
                break;

            case 4:
                g.display();
                break;

            case 5:
                exit(0);

            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}
