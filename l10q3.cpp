#include <cstdio>
#include <cstdlib>

#define MAX 100

class PriorityQueue {
    int heap[MAX];
    int size;

    void heapifyUp(int index) {
        while (index > 0 && heap[index] > heap[(index - 1) / 2]) {
            int temp = heap[index];
            heap[index] = heap[(index - 1) / 2];
            heap[(index - 1) / 2] = temp;
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            int temp = heap[index];
            heap[index] = heap[largest];
            heap[largest] = temp;
            heapifyDown(largest);
        }
    }

public:
    PriorityQueue() {
        size = 0;
    }

    void insert(int value) {
        if (size == MAX) {
            printf("Heap is full!\n");
            return;
        }
        heap[size] = value;
        heapifyUp(size);
        size++;
    }

    void deleteMax() {
        if (size == 0) {
            printf("Heap is empty!\n");
            return;
        }
        printf("Deleted: %d\n", heap[0]);
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
    }

    void display() {
        if (size == 0) {
            printf("Heap is empty!\n");
            return;
        }
        printf("Heap elements: ");
        for (int i = 0; i < size; i++)
            printf("%d ", heap[i]);
        printf("\n");
    }

    void search(int key) {
        for (int i = 0; i < size; i++) {
            if (heap[i] == key) {
                printf("Element %d found at index %d\n", key, i);
                return;
            }
        }
        printf("Element %d not found\n", key);
    }

    void heapSort() {
        int temp[MAX], tempSize = size;
        for (int i = 0; i < size; i++) temp[i] = heap[i];

        for (int i = size - 1; i >= 0; i--) {
            int t = heap[0];
            heap[0] = heap[i];
            heap[i] = t;
            size--;
            heapifyDown(0);
        }

        printf("Sorted elements (descending): ");
        for (int i = 0; i < tempSize; i++) {
            printf("%d ", heap[i]);
        }
        printf("\n");

        for (int i = 0; i < tempSize; i++) heap[i] = temp[i];
        size = tempSize;
    }
};

int main() {
    PriorityQueue pq;
    int choice, value;

    while (true) {
        printf("\nPriority Queue using Max Heap\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Search\n5. Sort\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                pq.insert(value);
                break;
            case 2:
                pq.deleteMax();
                break;
            case 3:
                pq.display();
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                pq.search(value);
                break;
            case 5:
                pq.heapSort();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
