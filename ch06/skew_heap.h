//
// Created by seineo on 2020/1/16.
//

#ifndef DS_SKEW_HEAP_H
#define DS_SKEW_HEAP_H

#define Elemtype int

using Tree = struct TreeNode *;

struct TreeNode {
    TreeNode(Elemtype e) : elem(e), left(nullptr), right(nullptr) {}

    Elemtype elem;
    Tree left;
    Tree right;
};

class PriorityQueue {
public:
    PriorityQueue() : priority_queue(nullptr) {}

    PriorityQueue(const PriorityQueue &pq);

    PriorityQueue &operator=(PriorityQueue pq);

    ~PriorityQueue();

    bool IsEmpty() const { return priority_queue == nullptr; }

    void Insert(Elemtype x);

    Elemtype DeleteMin();

    Elemtype FindMin() const;

    void Merge(PriorityQueue &pq);

private:
    Tree priority_queue;

    void Copy(Tree &dest, Tree to_copy);

    void MakeEmpty(Tree root);

    Tree Merge(Tree h1, Tree h2);

    Tree Merge1(Tree h1, Tree h2);
};

#endif //DS_SKEW_HEAP_H

