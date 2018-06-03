//#include <iostream>
#include "HuffmanTree.cpp"

using namespace std;

int main(){
    const string t = "abbccccddddd";
    HuffmanTree hTree = HuffmanTree(t);
    cout << hTree.encode("abcd") << endl;
    cout << hTree.decode("011010001") <<endl;
    return 0;
}