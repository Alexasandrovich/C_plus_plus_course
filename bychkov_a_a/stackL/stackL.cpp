//
// Created by Александр on 21.11.2017.
//
#include <stdexcept>
#include <iostream>
#include "stack.h"

using namespace std;

StackL::Node::Node(Node* pNext, const int& value) : pNext_(pNext), data_(value) { // +
}

bool StackL::isEmpty() const // +
{
    return  (pHead_ == nullptr);;
}

StackL::StackL(const StackL &stack) { // +
    StackL stackL;
    Node* func(stack.pHead_); //  если доступ осуществляется через указатель на объект
    while (nullptr != func) // , то используется операция стрелка
    {
        stackL.push(func->data_);
        func = func->pNext_;
    }
    while (!stackL.isEmpty())
    {
        push(stackL.top());
        stackL.top();
    }
}

StackL& StackL::operator=(const StackL &rhs) { // +
    StackL stackL;
    Node* func(rhs.pHead_);
    while (nullptr != func)
    {
        stackL.push(func->data_);
        func = func->pNext_;
    }
    while (!stackL.isEmpty())
    {
        push(stackL.top());
        stackL.top();
    }
    return *this;
}

void StackL::pop() // +
{
    if(! isEmpty()){
        Node* pdeleted(pHead_);
        pHead_ = pdeleted->pNext_;
        delete pdeleted;
    }
}

int& StackL::top() { // +
     if (isEmpty())
     {
         throw invalid_argument("Your stack is empty. Fix it.");
     }
    return pHead_->data_;
}

const int& StackL::top() const { // +
    if (isEmpty())
    {
        throw invalid_argument("Your stack is empty. Fix it.");
    }
    return pHead_->data_;
}
void StackL::push(const int& V) //+
{
    pHead_ = new Node(pHead_, V);
}
StackL::~StackL() // +
{
    while (pHead_ != nullptr) // почему нельзя использовать null
    {
        pop();
    }
}
ostream& operator<<(std::ostream& ostrm, const StackL& rhs)
{
    return rhs.writeTo(ostrm);
}
ostream& StackL::writeTo(ostream &ostrm) const {
    StackL Stack(*this);
    while (!Stack.isEmpty())
    {
        ostrm << Stack.top() << endl;
        Stack.pop();
    }
    return ostrm;
}
