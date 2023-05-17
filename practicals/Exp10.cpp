/* ================================================== 
 Description     : Read the marks obtained by students of second year in an online examination of
particular subject. Find out maximum and minimum marks obtained in that subject. Use
heap data structure. Analyze the algorithm.
 Author          : Suyog Chavan
 Reach me here   : https://suyogchavan.me
 Date of creation: Wednesday, 17 May 2023 
 Copyright       : ©suyogschavan03@gmail.com
================================================== */

#include <iostream>
#include <vector>
#include <algorithm>

// Function to build the max heap
void buildMaxHeap(std::vector<int>& marks) {
    int n = marks.size();
    
    // Starting from the parent of the last leaf node and moving up to the root
    for (int i = (n / 2) - 1; i >= 0; i--) {
        int parent = i;
        
        // Perform heapify operation
        while (true) {
            int maxIndex = parent;
            int leftChild = 2 * parent + 1;
            int rightChild = 2 * parent + 2;
            
            // Compare the parent with its left child
            if (leftChild < n && marks[leftChild] > marks[maxIndex]) {
                maxIndex = leftChild;
            }
            
            // Compare the parent with its right child
            if (rightChild < n && marks[rightChild] > marks[maxIndex]) {
                maxIndex = rightChild;
            }
            
            // If the parent is already the maximum, break out of the loop
            if (maxIndex == parent) {
                break;
            }
            
            // Swap the parent with the maximum child
            std::swap(marks[parent], marks[maxIndex]);
            parent = maxIndex;
        }
    }
}

int main() {
    std::vector<int> marks;
    
    // Reading marks obtained by students
    int numStudents;
    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;
    
    std::cout << "Enter the marks obtained by the students: " << std::endl;
    for (int i = 0; i < numStudents; i++) {
        int mark;
        std::cin >> mark;
        marks.push_back(mark);
    }
    
    // Build the max heap
    buildMaxHeap(marks);
    
    // Find the maximum mark (root of the heap)
    int maxMark = marks[0];
    
    // Sort the heap in ascending order
    std::sort(marks.begin(), marks.end());
    
    // Find the minimum mark (last element of the sorted heap)
    int minMark =marks[0];
    
    // Display the maximum and minimum marks
    std::cout << "Maximum Mark: " << maxMark << std::endl;
    std::cout << "Minimum Mark: " << minMark << std::endl;
    
    return 0;
}
