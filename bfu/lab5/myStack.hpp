#pragma once

#include <mutex>
#include <memory>
#include <stack>
#include <type_traits>

using std::mutex;
using std::lock_guard;
using std::shared_ptr;
using std::get_deleter;
using std::move;
using std::string;
using std::make_shared;
using std::stack;
using std::dynamic_pointer_cast;

template <class type1>
class Stack {
public:
    Stack();
    ~Stack();

    void push(type1 T);
    void pop();
    type1 top() const;
    int size()const;

private:
    mutable mutex m;
    stack <shared_ptr<type1> > st;
};

/* methods and c-d'rs */

template <class type1>
Stack<type1>::Stack() {
    //
}

template <class type1>
Stack<type1>::~Stack() {
    while(size()) {
        pop();
    }
}

template <class type1>
void Stack<type1>::push(type1 T) {
    lock_guard <mutex> lock(m);
    shared_ptr<type1> el = make_shared<type1>(T);
    st.push(el);
}

template <class type1>
void Stack<type1>::pop() {
    lock_guard <mutex> lock(m);
    if (st.empty()) {
        return;
    }
    get_deleter<type1>(st.top());
    st.pop();
}

template <class type1>
type1 Stack<type1>::top() const {
    lock_guard <mutex> lock(m);
    if (st.empty()) {
        return type1();
    }
    return *st.top();
}

template <class type1>
int Stack<type1>::size() const {
    lock_guard <mutex> lock(m);
    return st.size();
}
