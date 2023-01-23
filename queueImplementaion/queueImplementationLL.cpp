#include <iostream>

struct Node {
    int data;
    Node* next;
};

class Queue {
  public:
    Queue() : head_(NULL), tail_(NULL) {}
    ~Queue() {
        while (head_ != NULL) {
            Node* temp = head_;
            head_ = head_->next;
            delete temp;
        }
    }
    void enqueue(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        if (tail_ != NULL) {
            tail_->next = newNode;
        }
        tail_ = newNode;
        if (head_ == NULL) {
            head_ = tail_;
        }
    }
    int dequeue() {
        if (head_ == NULL) {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
        int data = head_->data;
        Node* temp = head_;
        head_ = head_->next;
        delete temp;
        if (head_ == NULL) {
            tail_ = NULL;
        }
        return data;
    }
    void print() {
        Node* temp = head_;
        while (temp != NULL) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
  private:
    Node* head_;
    Node* tail_;
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.print();
    std::cout << "Dequeued: " << q.dequeue() << std::endl;
    q.print();
    return 0;
}
