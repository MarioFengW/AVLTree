## AVL Tree Structure

An AVL Tree is a type of **binary search tree** that maintains balance by performing rotations during node insertions and deletions. Since it's balanced, it ensures that insertion, search, and deletion operations are performed in **O(log n)** in the worst case.

## Functionalities

### 1. Insertion (`insert`)
Inserts a node in the AVL tree in the correct position. After each insertion, the tree checks for balance, applying rotations as needed to restore equilibrium.

### 2. Search (`search`)
Searches for a specific value in the AVL tree, returning `true` if the value exists and `false` otherwise.

### 3. Deletion (`remove`)
Deletes a node from the tree and performs rotations as necessary to maintain balance.

### 4. Tree Traversals
The AVL tree supports three types of traversal:
- **In-order**: Left → Root → Right
- **Pre-order**: Root → Left → Right
- **Post-order**: Left → Right → Root

### 5. Tree Balancing through Rotations
To maintain balance, the tree performs rotations:
- **Single left rotation**: used when unbalanced to the right.
- **Single right rotation**: used when unbalanced to the left.
- **Double left-right rotation**: a combination of a left rotation followed by a right rotation.
- **Double right-left rotation**: a combination of a right rotation followed by a left rotation.

## Time Complexity

Since the AVL tree is balanced, the main operations have the following time complexity:
- **Insertion**: O(log n)
- **Search**: O(log n)
- **Deletion**: O(log n)
- **Traversals**: O(n)
