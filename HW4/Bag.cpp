#include "Bag.h"
#include <iostream>
#include <map>
#include <set>

using std::cout;
using std::endl;

template <class ItemType>
Bag<ItemType>::Bag() {
    head = new list;
    head->next = head;
    head->prev = head;
    now = NULL;
    bag_size = 0;
    cout << "Bag constructed" << endl;
}

template <class ItemType>
bool Bag<ItemType>::empty() const {
    return head->next == head;
}

template <class ItemType>
Bag<ItemType>::~Bag() {
    clear();
    delete (head);
    cout << "Bag destructed" << endl;
}

template <class ItemType>
Bag<ItemType>::Bag(const Bag &b) {
    cout << "Bag copy constructed" << endl;
    head = new list;
    bag_size = 0;
    now = NULL;
    head->next = head;
    head->prev = head;

    for (list *i = b.head->next; i != b.head; i = i->next) 
        insert(i->item);
}

template <class ItemType>
Bag<ItemType> &Bag<ItemType>::operator=(const Bag &b) {
    head = new list;
    bag_size = 0;
    now = NULL;
    head->next = head;
    head->prev = head;

    for (list *i = b.head->next; i != b.head; i = i->next) {
        insert(i->item);
    }
    return (*this);
}

template <class ItemType>
bool Bag<ItemType>::insert(const ItemType &item) {
    list *tmp = new list;
    list *end = head->prev;
    end->next = tmp;
    head->prev = tmp;
    tmp->item = item;
    tmp->next = head;
    tmp->prev = end;
    ++bag_size;
    return 1;
}

template <class ItemType>
bool Bag<ItemType>::ended() const {
    return now == NULL;
}

template <class ItemType>
void Bag<ItemType>::next() {
    if (ended()) {
        cout << "Please initializes" << endl;
        return;
    }
    now = now->next;
    if (now == head) now = NULL;
}

template <class ItemType>
void Bag<ItemType>::start() {
    if (head->next == head) {
        cout << "Please input item" << endl;
        return;
    }
    now = head->next;
}

template <class ItemType>
const ItemType &Bag<ItemType>::currentValue() const {
    return now->item;
}

template <class ItemType>
int Bag<ItemType>::currentCount() const {
    int i = 1;
    for (list *cur = head->next; cur != now; cur = cur->next, ++i);
    return i;
}

template <class ItemType>
int Bag<ItemType>::size() const {
    return bag_size;
}

template <class ItemType>
int Bag<ItemType>::uniqueSize() const {
    std::set<ItemType> s;

    for (list *cur = head->next; cur != head; cur = cur->next) {
        s.insert(cur->item);
    }
    return s.size();
}

template <class ItemType>
int Bag<ItemType>::erase(const ItemType &it) {
    int cnt = 0;

    for (list *cur = head->next; cur != head; cur = cur->next, ++cnt) {
        if (cur->item == it) {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            delete (cur);
            return cnt;
        }
    }
    return -1;
}

template <class ItemType>
int Bag<ItemType>::eraseAll(const ItemType &it) {
    int cnt = 0;

    for (list *cur = head->next; cur != head; cur = cur->next) {
        if (cur->item == it) {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            delete (cur);
            cnt++;
        }
    }
    return cnt;
}

template <class ItemType>
bool Bag<ItemType>::contains(const ItemType &it) const {
    for (list *cur = head->next; cur != head; cur = cur->next) {
        if (cur->item == it) return true;
    }
    return false;
}

template <class ItemType>
int Bag<ItemType>::count(const ItemType &it) const {
    int cnt = 0;

    for (list *cur = head->next; cur != head; cur = cur->next) {
        if (cur->item == it) ++cnt;
    }
    return cnt;
}

template <class ItemType>
void Bag<ItemType>::clear() {
    for (auto cur = head->next; cur != head; cur = cur->next) delete (cur);
    head->next = head;
    head->prev = head;
}

template <class ItemType>

void combine(Bag<ItemType> &bag1, Bag<ItemType> &bag2, Bag<ItemType> &result) {
    for (auto i = bag2.head->next; bag2.head != i; i = i->next)
        result.insert(i->item);
    for (auto i = bag1.head->next; bag1.head != i; i = i->next)
        result.insert(i->item);
}

template <class ItemType>

void subtract(Bag<ItemType> &bag1, Bag<ItemType> &bag2, Bag<ItemType> &result) {
    std::map<ItemType, int> dict;

    for (auto i = bag1.head->next; i != bag1.head; i = i->next) ++dict[i->item];
    for (auto i = bag2.head->next; i != bag2.head; i = i->next) --dict[i->item];
    for (auto i : dict) {
        for (int j = 0; j < i.second; ++j) result.insert(i.first);
    }
}