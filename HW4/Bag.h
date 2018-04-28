template <class ItemType>
class Bag{
  private:
    struct list{
        list* next;
        list* prev;
        ItemType item;
    };
    list* head;
    list* now;
    int bag_size;
    template <class T>
    friend void combine(Bag<T> &, Bag<T> &, Bag<T> &);
    template <class T>
    friend void subtract(Bag<T> &, Bag<T> &, Bag<T> &);

  public:
    Bag();
    ~Bag();
    Bag(const Bag &);
    Bag &operator=(const Bag &);

    bool empty() const;
    int size() const;
    int uniqueSize() const;
    bool insert(const ItemType &);
    int erase(const ItemType &);
    int eraseAll(const ItemType &);
    bool contains(const ItemType &) const;
    int count(const ItemType &) const;

    void start();
    void next();
    bool ended() const;
    const ItemType &currentValue() const;
    int currentCount() const;

    void clear();
};

