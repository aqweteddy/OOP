#include	"locator.h"

void WordLocator :: renew(){
	data.clear();
}


bool WordLocator :: check_word(char i){
	if(i != '\'' && !isdigit(i) && !isalpha(i)) return 1;
	return 0;
}

void WordLocator :: load(string file){
	std::fstream	fin;
	string			tmp;

	data.clear();

	fin.open(file, std::ios::in);

	if(access(file.c_str(), F_OK) == -1)
		cout << "ERROR: Error reading from file" <<endl;
	//		cout << "ERROR: File not found" <<endl;
	else if(access(file.c_str(), R_OK) ==-1 || !fin)
		cout << "ERROR: Error reading from file" <<endl;

	else {
		int 	cnt = 0;
		while(fin >> tmp){
			for(char &i : tmp)
				if(check_word(i)) i = ' ';

			string 		t;
			std::stringstream ss(tmp);
			while(ss>>t) {
				cnt++;
				data[t].push_back(cnt);
			}
			ss.str("");
			ss.clear();
		}
		fin.close();
	}
}

void WordLocator :: locate(string pattern, int cnt){
	if(data[pattern].size() > cnt-1)
		cout << data[pattern][cnt-1] << endl;
	else cout <<  "No matching entry" << endl;
}
