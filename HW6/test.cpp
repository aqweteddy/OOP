//#include <iostream>
#include "HuffmanTree.h"

using namespace std;

int main(){
    const string t = "abbccddddd";
    HuffmanTree hTree = HuffmanTree(t);
    hTree.print();
    return 0;
}
