//
// Created by Александр on 30.11.2017.
//
#include "priorityQueueL.h"
#include <iostream>
#include <stdexcept>

using namespace std;
PriotityQueueL::Node::Node(Node *pNext, const int& value): pNext_(pNext), data_(value) // +
{}

PriotityQueueL::Node::Node(Node *pNext): pNext_(pNext) // +
{}

bool PriotityQueueL::isEmpty() { // +
    return (pHead_== nullptr);
}

PriotityQueueL::PriotityQueueL(const PriotityQueueL &lhs) { // +
    PriotityQueueL priotityQueueL;
    Node* func(priotityQueueL.pHead_);
    while (func!=nullptr)
    {
         priotityQueueL.push(func->data_);
         func=func->pNext_;
    }
}

void PriotityQueueL::push(const int &rhs) { // +
    Node* func;
    if (isEmpty()) {
        pHead_ = new Node(nullptr, rhs);
        ptail_= pHead_;
    }
    else
    {
        if (rhs - (*pHead_).data_ > e)
        {
            pHead_=new Node(pHead_, rhs);
        }
        else {
            func = pHead_;
            while (func->pNext_ != nullptr && rhs - func->pNext_->data_ <= e)
            {
                func=func->pNext_;
            }
            Node *func1 = func->pNext_;
            func->pNext_ = new Node(func1, rhs);

        }
    }

}

void PriotityQueueL::pop() {

    if(! isEmpty()){
        Node* pdeleted(pHead_);
        pHead_ = pdeleted->pNext_;
        delete pdeleted;
    }
}
void PriotityQueueL::deleteAll() {
    while (!isEmpty()) {
        pop();
    }
}

int&  PriotityQueueL:: start() {
    return pHead_->data_;
}

const int& PriotityQueueL::start() const {
    return pHead_->data_;
}

int& PriotityQueueL:: end() {
    return ptail_->data_;
}
const int& PriotityQueueL:: end() const {
    return ptail_->data_;
}
ostream& operator<<(std::ostream& ostrm, const PriotityQueueL& rhs)
{
    return rhs.writeTo(ostrm);
}

ostream& PriotityQueueL::writeTo(ostream &ostrm) const {
    PriotityQueueL PriotityQueueL(*this);
    while (!PriotityQueueL.isEmpty())
    {
        ostrm <<PriotityQueueL.start() << endl;
        PriotityQueueL.pop();
    }
    return ostrm;
}
PriotityQueueL::~PriotityQueueL()
{

}
