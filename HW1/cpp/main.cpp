#include<iostream>
#include<cctype>
#include<algorithm>


int main(int argc, char**argv){
	bool flag=true;

	if(argc!=2){
		std::cout<<"Input format error!!\n";
		return 0;
	}

	std::string data=argv[1];

	std::transform(data.begin(), data.end(), data.begin(), tolower);

	for(int i=0, j=data.size()-1; i<=(int)data.size()/2; i++, j--){
		while(!isalpha(data[i]))i++;
		while(!isalpha(data[j]))j--;
		if(data[i]!=data[j]){
			flag=false;
			break;
		}
	}

	std::cout<< (flag ? "Yes" : "No") <<'\n';
	return 0;
}
