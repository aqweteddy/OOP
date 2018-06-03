// Main Program Example for HW6

// You can use this file as your main program, or add more functions if you want.
// Please ***MAKE SURE*** that your class works fine in this main program.
// TA will test your class by this program with additional test data.
#include "HuffmanTree.h"
#include <iostream>
//#include "HuffmanTree.cpp"
/*
int main()
{
    // Build a Huffman Tree according to the string
    HuffmanTree t("Abcdaaaabbbbaaaacceee!@&$()#@%*");

    // encode a string
    cout << t.encode("Abcdaaaabbbbaaaacc") << endl;

    // The Hoffman Tree t will be unable to encode this
    // Therefore, please print out error message and return an empty string("") when encounter this.
    cout << t.encode("Abcdaaaeeeabbbbaaaac@@@%%cRRRRR") << endl;

    // decode a string
    cout << t.decode("101011110000111100101111111010111") << endl;

    // The Hoffman Tree t will be unable to decode this
    // Therefore, please print out error message and return an empty string("") when encounter this.
    cout << t.decode("1010111100001111001011111110101111") << endl;
    return 0;
}
*/
int main(){
	HuffmanTree a("eebbeecdebeeebecceeeddebbbeceedebeeddeeeecceeeedeeedeeebeedeceedebeeedeceeedebee");
	string t = a.encode("ebdeebdeebdeeebddbed");	
	cout<<	a.encode("ebdeebdeebdeeebddbed") << endl;
	cout << a.decode(t) << endl;
	cout << "ebdeebdeebdeeebddbed" << '\n';
}
