#include<stdio.h>
#include "vector.h"

int main() {
    Vector v;
    
    // Initialize the vector
    initVector(&v);
    
    // Add some elements to the vector
    addElement(&v, 10);
    addElement(&v, 20);
    addElement(&v, 30);
    addElement(&v, 40);
    
    // Print the vector elements
    printf("Vector elements: ");
    printVector(&v);
    
    // Free the vector memory when done
    freeVector(&v);
    
    return 0;
}
