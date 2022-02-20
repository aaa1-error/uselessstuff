#include <iostream>
#include <string>
#include <vector>

std::string runsp(std::string in) {
	enum modes {
		onWord, onSpace
	};
	modes mode = modes::onWord;


	//getline(cin, in);

	size_t j = 0;
	for(j = 0; in[j] == ' ';j++) {
		in[j] = 0;
	}
	for(size_t i = j; i < in.length(); i++) {
			switch(mode) {

			case onWord:

				if(in[i] == ' ') {
					mode = onSpace;
				}
				break;

			case onSpace:

				if(in[i] == ' ' && in[i-1] == ' ') {

					int c = i;

					for(c = i; i < in.length();i++) {
						if(in[i] != ' ') break;
						if (in[i] == ' ') in.erase(in.begin() + i);
					}

					i = c;
				} else {
					mode = onWord;
				}
				break;

			default:
				return "ABOBA";
		}
	}
	return in;
}
