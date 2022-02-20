#include <iostream>
#include <string>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	string s;

	int mode = 0, dotsRow = 0;
	const int onWord = 0, onSeparator = 1, onEnding = 2; // onBlocks = 3;

	bool comaSet = false, dotSet = false, firstWordCheck = true, specCharUser = false, quoteIsOpen = false, wordsPresent = false;

	bool missingUpperCaseAtStart = false;
	string specs = "-_=+()*&^%$#@№%\\|/";
	getline(cin,s);

	for(int i = 0; i < s.length();i++) {

		switch(mode) {
			case onWord:
				dotSet = false;
				switch(s[i]) {
				case 'a'...'z':
					if(firstWordCheck == true) {
						missingUpperCaseAtStart = true;
					}
					firstWordCheck = false;
					//break;
				case 'A'...'Z':
				case '0'...'9':
				case '\'':
					if(firstWordCheck == true) {
						missingUpperCaseAtStart = false;
					}
					firstWordCheck = false;
					wordsPresent = true;
					break;

				case ',':
					comaSet = true;
					mode = onSeparator;
					break;
				case ' ':

					mode = onSeparator;
					break;

				case '.':
					dotSet = true;
					for(i = i; i < s.length();i++) {
						switch(s[i]) {
							case '.':
								dotSet = true;
								dotsRow++;
								if(dotsRow == 3) {
									printf("Обнаружено троеточие. (ок)\n");
								} else if(dotsRow > 3) {
									printf("Обнаружено затяжное троеточие.\n");
								}
								break;

							case 'A'...'Z':
							case 'a'...'z':
							case '0'...'9':
								wordsPresent = true;
							case '\'':
								if(dotsRow >= 3) {
									printf("Обнаружено продолжение предложения после троеточия.\n");
								} else if(dotsRow == 2) {
									printf("Обнаружены двойные точки.\n");
									}
								dotSet = false;
								mode = onWord;
								dotsRow = 0;
								break;

							case ' ':
								mode = onSeparator;
								break;

							case '!':
							case '?':
								mode = onEnding;
								dotSet = true;
								break;

							case 35 ... 37:
							case 40 ... 45:
							case 60 ... 62:
							case 64:
								break;


							default:
								printf("dotset default\n");
								bool aboba = false;
								break;
						}
					}
					break;

				case '!':
				case '?':
					mode = onEnding;
					dotSet = true;
					break;

				case '\"':
					if(quoteIsOpen == true) quoteIsOpen = false;
					else quoteIsOpen = true;

				default:
					printf("English, mf! Do you speak it?\n");
					return -1;
					break;
				} //switch onWord mode

			case onSeparator:

				break;

			case onEnding:
				for(i = i; i < s.length();i++) {
					switch(s[i]) {
						case '!':
						case '?':
						case '.':
						dotSet = true;
							break;
						default:
							printf("Лишние символы в конце.\n");
							return -1;
					}

				}
				break;
			}
		} //switch mode

	printf("missingUpperCaseAtStart = %d\ndotSet = %d\nquoteIsOpen = %d\nwordsPresent = %d\n", missingUpperCaseAtStart, dotSet, quoteIsOpen, wordsPresent);
}
