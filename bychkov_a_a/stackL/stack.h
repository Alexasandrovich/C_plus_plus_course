#ifndef STACK_2017
#define STACK_2017

#include <iosfwd>
using namespace std;
class StackL
{
public: // +
	StackL()= default;
    StackL(const StackL& stack);
    StackL& operator = (const StackL& rhs);
	void push(const int& rhs);
	void pop();
	int& top();
    const int& top() const;
	bool isEmpty() const;
    ostream& writeTo(ostream& ostrm) const;
    ~StackL();
private:
	struct Node // В классе нужно хранить указатель на начало стека и на вершину
	{
		Node(Node* pNext, const int& value);
        ~Node() = default;
		Node* pNext_{ nullptr };
		int data_{ int(0) };
	};
	Node* pHead_{ nullptr };
};
ostream& operator<<(ostream& ostrm, const StackL& rhs);
#endif STACK_2017
