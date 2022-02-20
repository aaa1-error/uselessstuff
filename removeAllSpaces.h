#include <iostream>
#include <string>
#include <vector>

std::string rsp(std::string in) {
	enum modes {
		onWord, onSpace
	};
	modes mode = modes::onWord;


	//getline(cin, in);

	for(size_t i = 0; i < in.length(); i++) {
			if(in[i] == ' ') in.erase(in.begin() + i--);

		}
	return in;
}
