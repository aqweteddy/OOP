#include <map>
#include <queue>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Node {
protected:
    friend class HuffmanTree;
    friend class compareNode;
    int freq;

public:
    virtual int getNodeType() = 0; // 0: terminal node 1: internal node
    virtual char getValue() = 0;
    virtual Node* getLChild() = 0;
    virtual Node* getRChild() = 0;
    virtual ~Node();
};

class IntervalNode : public Node {
    friend class HuffmanTree;

private:
    Node* lChild; // left child
    Node* rChild; // right child
    ~IntervalNode();

public:
    IntervalNode(int);
    int getNodeType(); // 0: terminal node 1: internal node
    Node* getLChild();
    Node* getRChild();
    char getValue(); // internal node 沒有 value，因此請印出提示訊息，並且 return 0。
    IntervalNode* getPointer();
};

class TerminalNode : public Node {
private:
    char value; // 儲存這個 node 代表的字元

public:
    TerminalNode(char, int);

    int getNodeType(); // 0: terminal node 1: internal node
    Node* getLChild(); // terminal node 沒有 LChild，因此請印出提示訊息，並且 return NULL。
    Node* getRChild(); // terminal node 沒有 RChild。
    char getValue();
    TerminalNode* getPointer();
    ~TerminalNode();
};

class HuffmanTree {
private:
    Node* root;
    std::map<char, string> code_c_s;
    std::map<string, char> code_s_c;
    void make_code(Node*, string);
    void clean(Node*);
public:
    HuffmanTree(const string& s);
    string encode(const string&);
    string decode(const string&);
	void print();
    ~HuffmanTree();
};
