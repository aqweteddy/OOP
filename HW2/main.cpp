#include	"locator.cpp"

std :: vector<string> sep(string str){
	std :: vector<string>	com;
	std :: stringstream 	ss(str);
	string 					tmp;
	
	while(ss>>tmp) com.push_back(tmp);
	return com;
}

bool is_int(string in){
	for(auto i : in)
		if(!isdigit(i) && i-'0' > 0) 
			return 0;
	if(std::stoi(in) <= 0) return 0;
	return 1;
}

int main(){
	WordLocator		loc;
	string			inp, tmp;

	while(cout << ">" && getline(std :: cin, inp)){
		std :: vector<string> com = sep(inp);

		if(com.size() == 0) continue;
		if(com[0] == "load" && com.size() == 2) loc.load(com[1]);
		else if(com[0] == "locate" && com.size() == 3 && is_int(com[2]))
			loc.locate(com[1], std :: stoi(com[2]));
		else if(com[0] == "new" && com.size() == 1) loc.renew();
		else if(com[0] == "end" && com.size() == 1) break;
		else cout <<"ERROR: Invalid command"<< endl;
	}
	return 0;
}
