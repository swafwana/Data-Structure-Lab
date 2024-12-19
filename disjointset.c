#include <stdio.h>

#define MAX 100 // Maximum number of elements in the disjoint set

// Array to store the parent of each element
int parent[MAX];

// Array to store the rank (depth) of each tree
int rank[MAX];

// Array to store the elements (optional, but for user input)
int elements[MAX];

// MakeSet operation: Initialize the parent of each element to itself
// and the rank of each element to 0
void MakeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;  // Each element is its own parent initially
        rank[i] = 0;     // Initial rank is 0
    }
}

// FindSet operation with path compression
int FindSet(int x) {
    if (parent[x] != x) {
        parent[x] = FindSet(parent[x]); // Path compression
    }
    return parent[x];
}

// Union operation with union by rank
void Union(int x, int y) {
    int rootX = FindSet(x);
    int rootY = FindSet(y);

    if (rootX != rootY) {
        // Union by rank: attach the tree with lesser rank under the tree with higher rank
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++; // Increase the rank if both trees have the same rank
        }
    }
}

// Function to display the parent and rank arrays for debugging
void displaySets(int n) {
    printf("Element  Parent  Rank\n");
    for (int i = 0; i < n; i++) {
        printf("%d        %d       %d\n", elements[i], parent[i], rank[i]);
    }
}

int main() {
    int n, choice, x, y;

    while (1) {
        printf("\nDisjoint Set Operations Menu:\n");
        printf("1. MakeSet\n");
        printf("2. FindSet\n");
        printf("3. Union\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of elements for MakeSet: ");
                scanf("%d", &n);

                printf("Enter the elements:\n");
                for (int i = 0; i < n; i++) {
                    printf("Element %d: ", i + 1);
                    scanf("%d", &elements[i]);
                }

                MakeSet(n);
                printf("MakeSet operation completed.\n");
                break;
            
            case 2:
                printf("Enter the element to find its set (enter index): ");
                scanf("%d", &x);
                if (x >= 0 && x < n) {
                    printf("FindSet of %d: %d\n", elements[x], FindSet(x));
                } else {
                    printf("Invalid index.\n");
                }
                break;
            
            case 3:
                printf("Enter two elements to perform Union (enter indices): ");
                scanf("%d %d", &x, &y);
                if (x >= 0 && x < n && y >= 0 && y < n) {
                    Union(x, y);
                    printf("Union of %d and %d completed.\n", elements[x], elements[y]);
                } else {
                    printf("Invalid indices.\n");
                }
                break;
            
            case 4:
                printf("Current Disjoint Set:\n");
                displaySets(n);
                break;
            
            case 5:
                printf("Exiting the program.\n");
                return 0;
            
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

