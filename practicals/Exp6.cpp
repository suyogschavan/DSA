#include <iostream>
#include <vector>
#include <queue>

// Node structure for the tree
struct Node {
    int data;
    std::vector<Node*> children;

    Node(int data) : data(data) {}
};

// Function to perform DFS traversal on the tree
void DFS(Node* node, std::vector<bool>& visited) {
    visited[node->data] = true;
    std::cout << node->data << " ";

    for (Node* child : node->children) {
        if (!visited[child->data]) {
            DFS(child, visited);
        }
    }
}

// Function to perform BFS traversal on the tree
void BFS(Node* root) {
    std::vector<bool> visited(100, false); // Assuming maximum 100 nodes in the tree
    std::queue<Node*> queue;

    visited[root->data] = true;
    queue.push(root);

    std::cout << "BFS Traversal: ";

    while (!queue.empty()) {
        Node* currentNode = queue.front();
        queue.pop();
        std::cout << currentNode->data << " ";

        for (Node* child : currentNode->children) {
            if (!visited[child->data]) {
                visited[child->data] = true;
                queue.push(child);
            }
        }
    }

    std::cout << std::endl;
}

int main() {
    // Create the tree with landmarks as nodes
    Node* root = new Node(0);
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);

    // Build the tree structure by connecting the nodes
    root->children.push_back(node1);
    root->children.push_back(node2);
    node1->children.push_back(node3);
    node1->children.push_back(node4);
    node2->children.push_back(node4);
    node3->children.push_back(node4);
    node3->children.push_back(node5);

    // Perform DFS traversal
    std::vector<bool> visited(100, false); // Assuming maximum 100 nodes in the tree
    std::cout << "DFS Traversal: ";
    DFS(root, visited);
    std::cout << std::endl;

    // Perform BFS traversal
    BFS(root);

    return 0;
}
