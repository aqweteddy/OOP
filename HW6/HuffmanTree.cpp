#include "HuffmanTree.h"

struct compareNode : public std::binary_function<Node*, Node*, bool>
{
    bool operator()(const Node* lhs, const Node* rhs) const {
        return lhs->freq > rhs->freq;
    }
};

Node::~Node()
{
    return;
}

IntervalNode::IntervalNode(int f)
{
    freq = f;
}

IntervalNode::~IntervalNode()
{
    delete(lChild);
    delete(rChild);
}

int IntervalNode::getNodeType()
{
    return 1;
}

Node* IntervalNode::getLChild()
{
    return lChild;
}

Node* IntervalNode::getRChild()
{
    return rChild;
}

char IntervalNode::getValue()
{
    cout << "Interval Node don't have value" << endl;
    return 0;
}

TerminalNode::TerminalNode(char c, int f)
{
    freq = f;
    value = c;
}

TerminalNode::~TerminalNode()
{
    return;
}

int TerminalNode ::getNodeType()
{
    return 0;
}

char TerminalNode::getValue()
{
    return value;
}

Node* TerminalNode ::getLChild()
{
    cout << "Terminate Node don't have child" << endl;
    return NULL;
}

Node* TerminalNode ::getRChild()
{
    cout << "Terminate Node don't have child" << endl;
    return NULL;
}

HuffmanTree::HuffmanTree(const string& s)
{
    std::map<char, int> dic;
    std::priority_queue<Node*, std::vector<Node*>, compareNode> pq;
    
    for (char i : s) ++dic[i];
    
    for (auto& i : dic) {
        TerminalNode *tmp = new TerminalNode(i.first, i.second);
        pq.push(tmp);
    }

    IntervalNode* tmp;

    while (pq.size() != 1) {
        Node *a = pq.top();
        pq.pop();
        Node *b = pq.top();
        pq.pop();
        tmp = new IntervalNode(a->freq + b->freq);
        tmp->rChild = a;
        tmp->lChild = b;
        pq.push(tmp);
    }
    root = tmp;
    make_code(root, "");
}

HuffmanTree::~HuffmanTree()
{
        delete(root);
}


void HuffmanTree::make_code(Node *par, string now)
{    
    if(par->getNodeType() == 0){
        code_c_s[par->getValue()] = now;
        code_s_c[now] = par->getValue();
    } else {
        make_code(par->getLChild(), now + "0");
        make_code(par->getRChild(), now + "1");
    }
}

string HuffmanTree::encode(const string& s)
{
    string ans;

    for(const char &c : s){
        if(code_c_s.find(c) != code_c_s.end()){
            ans += code_c_s[c];
        } else {
            cout << s << " can't be encode." << endl;
            return "";
        }
    }
    return ans;
}

string HuffmanTree::decode(const string& s)
{
    string ans, tmp;

    for(const char &c : s){
        tmp += c;
        if(code_s_c.find(tmp) != code_s_c.end()){
            ans += code_s_c[tmp];
            tmp.clear();
        }
    }
    if(tmp.empty()) return ans;
    cout << s << " can't be decode." << endl;
    return "";
}
