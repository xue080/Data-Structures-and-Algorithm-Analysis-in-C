//
// Created by seineo on 2020/1/15.
//

#include <algorithm>
#include <stdexcept>
#include "leftist_heap.h"

void PriorityQueue::Copy(Tree &dest, Tree to_copy) {
    if (to_copy != nullptr) {
        dest = new TreeNode(to_copy->elem, to_copy->npl);
        Copy(dest->left, to_copy->left);
        Copy(dest->right, to_copy->right);
    } else {
        dest = nullptr;   //without this line, when to_copy is nullptr, dest is undefined
    }
}

void PriorityQueue::MakeEmpty(Tree root) {
    if (root != nullptr) {
        MakeEmpty(root->left);
        MakeEmpty(root->right);
        delete root;
        root = nullptr;
    }
}

PriorityQueue::PriorityQueue(const PriorityQueue &pq) {
    Copy(priority_queue, pq.priority_queue);
}

PriorityQueue &PriorityQueue::operator=(PriorityQueue pq) {
    std::swap(priority_queue, pq.priority_queue);
    return *this;
}

PriorityQueue::~PriorityQueue() {
    MakeEmpty(priority_queue);
}

void PriorityQueue::Merge(PriorityQueue &pq) {
    priority_queue = Merge(priority_queue, pq.priority_queue);
    pq.priority_queue = nullptr;   //should not use the old leftist heaps
}

Tree PriorityQueue::Merge(Tree h1, Tree h2) {
    if (h1 == nullptr)
        return h2;
    if (h2 == nullptr)
        return h1;
    if (h1->elem < h2->elem) {
        return Merge1(h1, h2);
    } else {
        return Merge1(h2, h1);
    }
}

Tree PriorityQueue::Merge1(Tree h1, Tree h2) {
    if (h1->left == nullptr) {   //single node
        h1->left = h2;  //h1->right is already nullptr, then h1->npl is already 0
    } else {
        h1->right = Merge(h1->right, h2);
        if (h1->left->npl < h1->right->npl)
            std::swap(h1->left, h1->right);   //swap children
        h1->npl = h1->right->npl + 1;
    }
    return h1;
}

Elemtype PriorityQueue::FindMin() const {
    if (priority_queue == nullptr)
        throw std::logic_error("Priority queue is empty");
    return priority_queue->elem;
}

void PriorityQueue::Insert(Elemtype x) {  //heap with single node calls Merge()
    Tree temp = new TreeNode(x);
    priority_queue = Merge(temp, priority_queue);
}

Elemtype PriorityQueue::DeleteMin() {
    if (IsEmpty())
        throw std::logic_error("Priority queue is empty");
    Elemtype data = priority_queue->elem;
    Tree left_heap = priority_queue->left;
    Tree right_heap = priority_queue->right;
    delete priority_queue;
    priority_queue = Merge(left_heap, right_heap);
    return data;
}
