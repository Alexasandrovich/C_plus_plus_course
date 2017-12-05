//
// Created by Александр on 30.11.2017.
//

#ifndef PRIORITYQUEUEL_PRIORITYQUEUEL_H
#define PRIORITYQUEUEL_PRIORITYQUEUEL_H

#include <iosfwd>
using namespace std;
class PriotityQueueL
{
public:
    PriotityQueueL()= default;
    PriotityQueueL(const PriotityQueueL& lhs);
    PriotityQueueL& operator=(const PriotityQueueL& lhs);
    void push(const int& rhs); // +
    void pop(); // +
    bool isEmpty(); // +
    void deleteAll();
    int& start(); // +
    const int& start() const; // +
    int& end(); // +
    const int& end() const; // +
    ~PriotityQueueL();
    std::ostream &writeTo(std::ostream &ostrm) const;

private:
    struct Node
    {
        Node(Node* pNext); // +
        Node(Node *pNext, const int& value); // +
        Node* pNext_{nullptr};
        int data_{ int(0)};
        ~Node() = default;
    };
    Node* pHead_{nullptr};
    Node* ptail_{nullptr};
    double e=10E-6;
};

std::ostream& operator<<(std::ostream& ostream, const PriotityQueueL& lhs);
#endif //PRIORITYQUEUEL_PRIORITYQUEUEL_H
