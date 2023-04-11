#include "List.h"


template <typename T>
List<T>::List(size_t n) : sz(n) {
    auto tmp = front;
    for (auto i = 0u; i < sz - 1; ++i) {
        auto node = new Node<T>;
        tmp->next = node;
        tmp = node;
    }
    tmp->next = last;
}

template <typename T>
List<T>::List(size_t n, T x) : List(n) {
    auto iter = front->next;
    while (iter != nullptr) {
        iter->val = x;
        iter = iter->next;
    }
}

template <typename T>
List<T>::List(const std::initializer_list<T>& l) : List(l.size()) {
    auto iter = front->next;
    for (auto elm : l) {
        iter->val = elm;
        iter = iter->next;
    }
}

template <typename T>
auto List<T>::get_node(unsigned n) const {
    auto iter = front->next;
    for (auto i = 0u; i < n; ++i) {
        iter = iter->next;
    }
    return iter;
}

template <typename T>
auto List<T>::operator[](unsigned n) const{
    auto iter = this->get_node(n);
    return iter->val;
}

template <typename T>
List<T>::List(const List<T>& l) : List(l.sz) {
    auto iter = this->front->next;
    auto tmp = l.front->next;
    while (tmp != nullptr) {
        iter->val = tmp->val;
        iter = iter->next;
        tmp = tmp->next;
    }
}

template <typename T>
void List<T>::swap(List<T>& a, List<T>& b) {
    std::swap(a.sz, b.sz);
    std::swap(a.front, b.front);
    std::swap(a.last, b.last);
}

template <typename T>
List<T>& List<T>::operator=(List<T> l) {
    swap(*this, l);
    return *this;
}

template <typename T>
void List<T>::insert(List<T> l, const unsigned n) { 
    auto tmp = get_node(n - 1);
    for (int i = 0; i < l.sz; ++i) {
        auto node = new Node<T>;
        node->val = l[i];
        node->next = tmp->next;
        tmp->next = node;
        tmp = node;
    }
    sz += l.sz;
}

template <typename T>
void List<T>::insert(const T& x, const unsigned n) {
    List<T> tmp(1, x);
    insert(tmp, n);
}

template <typename T>
T List<T>::pop_first() {
    assert(sz != 0);
    auto new_begin = front->next->next;
    auto res = front->next->val;
    if (sz == 1) last = front;
    delete front->next;
    front->next = new_begin;
    --sz;
    return res;
}

template <typename T>
T List<T>::pop_last() {
    auto res = last->val;
    auto newlast = this->get_node(sz - 2);
    newlast->next = nullptr;
    delete last;
    last = newlast;
    --sz;
    return res;
}

template <typename T>
void List<T>::erase(unsigned n) {
    auto node = this->get_node(n - 1);
    auto tmp = node;
    node = node->next;
    tmp->next = nullptr;
    last = tmp;
    while (node != nullptr) {
        tmp = node;
        node = node->next;
        delete tmp;
        --sz;
    }
}

template <typename T>
List<T>::~List() {
    while (front->next != nullptr) {
        pop_first();
    }
    delete front;
}

template <typename T>
void List<T>::reverse_rec(unsigned n, Node<T>* cur) {
    //я изначально писал для begin - начала списка, мне лень это переписывать, поэтому static 
    static auto& begin = front->next;
    if (n == sz) return;
    if (n == 0) {
        cur = begin->next;
        begin->next = nullptr;
        last = begin;
        ++n;
    }
    auto tmp = cur->next;
    cur->next = begin;
    begin = cur;
    reverse_rec(n + 1, tmp);
}

template <typename T>
void List<T>::reverse_itr() { 
    static auto& begin = front->next;
    Node<T>* prev = nullptr;
    auto cur = begin;
    auto nxt = begin->next;
    while (nxt != nullptr) {
        cur->next = prev;
        prev = cur;
        cur = nxt;
        nxt = nxt->next;
    }
    cur->next = prev;
    last = begin;
    begin = cur;
}

template <typename T>
unsigned List<T>::size() const {
    return this->sz;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const List<T>& list){
    out << "( ";
    auto iter = list.front->next;
    while (iter != nullptr) {
        out << iter->val << ' ';
        iter = iter->next;
    }
    out << ")\n";
    return out;
}
