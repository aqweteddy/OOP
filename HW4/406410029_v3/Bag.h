#include <iostream>
#include <map>
#include <set>

using std::cout;
using std::endl;

template <class ItemType>
class Bag {
    template <class T>
    friend void combine(Bag<T>&, Bag<T>&, Bag<T>&);
    template <class T>
    friend void subtract(Bag<T>&, Bag<T>&, Bag<T>&);

   private:
    struct list {
        list* next;
        list* prev;
        ItemType item;
    };

    list* head;
    list* now;
    int bag_size;

   public:
    Bag() {
        head = new list;
        head->next = head;
        head->prev = head;
        now = NULL;
        bag_size = 0;
        cout << "Bag constructed" << endl;
    }

    ~Bag() {
        clear();
        delete (head);
        cout << "Bag destructed" << endl;
    }

    Bag(const Bag& b) {
        cout << "Bag copy constructor" << endl;
        head = new list;
        bag_size = 0;
        now = NULL;
        head->next = head;
        head->prev = head;

        for (list* i = b.head->next; i != b.head; i = i->next) insert(i->item);
    }

    Bag& operator=(const Bag& b) {
        if(&b == this) return (*this);
        clear();
        
        head = new list;
        bag_size = 0;
        now = NULL;
        head->next = head;
        head->prev = head;

        for (list* i = b.head->next; i != b.head; i = i->next) {
            insert(i->item);
        }
        return (*this);
    }

    bool empty() const { return head->next == head; }

    int size() const { return bag_size; }

    int uniqueSize() const {
        std::set<ItemType> s;

        for (list* cur = head->next; cur != head; cur = cur->next) {
            s.insert(cur->item);
        }

        return s.size();
    }

    bool insert(const ItemType& item) {
        list* tmp = new list;
        list* end = head->prev;
        end->next = tmp;
        head->prev = tmp;
        tmp->item = item;
        tmp->next = head;
        tmp->prev = end;
        ++bag_size;
        return 1;
    }

    int erase(const ItemType& it) {
        int cnt = 1;

        for (list* cur = head->next; cur != head; cur = cur->next, ++cnt) {
            if (cur->item == it) {
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                --bag_size;
                delete (cur);
                return cnt;
            }
        }
        return -1;
    }

    int eraseAll(const ItemType& it) {
        int cnt = 0;
        list* cur = head->next;

        while (cur != head) {
            if (cur->item == it) {
                ++cnt;
                list* old = cur;
                cur = cur->next;
                old->prev->next = old->next;
                old->next->prev = old->prev;
                delete (old);
                --bag_size;
            } else
                cur = cur->next;
        }
        return cnt;
    }

    bool contains(const ItemType& it) const {
        for (list* cur = head->next; cur != head; cur = cur->next) {
            if (cur->item == it) return true;
        }
        return false;
    }

    int count(const ItemType& it) const {
        int cnt = 0;

        for (list* cur = head->next; cur != head; cur = cur->next) {
            if (cur->item == it) ++cnt;
        }
        return cnt;
    }

    void start() {
        if (head->next == head) {
            cout << "Please input item" << endl;
            return;
        }
        now = head->next;
    }

    void next() {
        if (ended()) {
            cout << "Please initializes" << endl;
            return;
        }
        now = now->next;
        if (now == head) now = NULL;
    }

    bool ended() const { return now == NULL; }

    const ItemType& currentValue() const {
        if (now == NULL) {
            cout << "Please start finger" << endl;
            return head->item;
        }
        return now->item;
    }

    int currentCount() const {
        int i = 1;
        for (list* cur = head->next; cur != now; cur = cur->next, ++i)
            ;
        return i;
    }

    void clear() {
        for (auto cur = head->next; cur != head; cur = cur->next) delete (cur);
        head->next = head;
        head->prev = head;
        bag_size = 0;
    }
};

template <class ItemType>
void combine(Bag<ItemType>& bag1, Bag<ItemType>& bag2, Bag<ItemType>& result) {
    Bag<ItemType> res;
    for (auto i = bag2.head->next; bag2.head != i; i = i->next)
        res.insert(i->item);
    for (auto i = bag1.head->next; bag1.head != i; i = i->next)
        res.insert(i->item);
    result = res;
}

template <class ItemType>
void subtract(Bag<ItemType>& bag1, Bag<ItemType>& bag2, Bag<ItemType>& result) {
    std::map<ItemType, int> dict;

    for (auto i = bag1.head->next; i != bag1.head; i = i->next) ++dict[i->item];
    for (auto i = bag2.head->next; i != bag2.head; i = i->next) --dict[i->item];
    for (auto i : dict) {
        for (int j = 0; j < i.second; ++j) result.insert(i.first);
    }
}