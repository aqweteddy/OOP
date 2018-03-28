#include	<string>
#include	<iostream>
#include	<fstream>
#include	<algorithm>
#include	<vector>
#include	<map>
#include	<cctype>
#include	<sstream>
#include	<unistd.h>


using std :: string;
using std :: endl;
using std :: cout;

class WordLocator{
public:
	WordLocator(){
		return;
	}

	WordLocator(string file){
		load(file);
	}

	void	load(string);
	void	locate(string, int);
	void	renew();
	
private:
	std::map<string, std::vector<int> >		data;
	bool	check_word(char);
};
