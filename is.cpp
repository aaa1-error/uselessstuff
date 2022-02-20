#include <iostream>
#include <string>

using namespace std;

int main() {
  setlocale(LC_ALL, "Russian");

  string in;

  int i = 0;
  int mode = 0, dotCountAtEnd = 0;

  const int onWord = 0, onSeparator = 1, ended = 2;

  bool comaSet = false, quoteIsOpen = false, dotSet = false, caseCheck = false;

  bool repeatingCommas = false, unfinishedQuote = false,
       endedByExclamOrInterog = false;

  getline(cin, in);

  for (i = 0; i < in.length(); i++) {

    // printf("%3c", in[i]);

    switch (mode) {
    case onWord:
      switch (in[i]) {
      case ' ':
        mode = onSeparator;
        break;
      case ',':
        mode = onSeparator;
        comaSet = true;
        break;

      case '!':
      case '?':
        endedByExclamOrInterog = true;
        break;

      case '.':
        dotSet = true;
        mode = ended;
        break;

      case 'A' ... 'Z':
      case 'a' ... 'z':
      case '0' ... '9':
        break;

      default:
        printf("English, mf! Do you speak it?!\n");
        return -1;
      }
      break;

    case onSeparator:
      switch (in[i]) {
      case ' ':
        break;
      case ',':
        if (comaSet == true) {
          printf("На итерации %d обнаружена повторяющаяся запятая.\n", i);
        }
        break;

      case '!':
      case '?':
        endedByExclamOrInterog = true;
        break;

      case '.':
        if (dotSet == true) {
          printf("На итерации %d обнаружена повторяющаяся точка.\n", i);
        }
        dotSet = true;
        mode = ended;
        break;

      case 'A' ... 'Z':
      case 'a' ... 'z':
      case '0' ... '9':
        mode = onWord;
        break;

      default:
        printf("English, mf! Do you speak it?!\n");
        return -1;
      }
      break;

    case ended:
      switch (in[i]) {
      case '!':
      case '?':
      case ' ':
        break;
      case '.':
        dotCountAtEnd++;
        if (dotCountAtEnd > 3) {
          printf("Обнаружены лишние точки в конце предложения.\n");
        }
        break;
      default:
        printf("Обнаружены лишние символы в конце предложения.\n");
        break;
      }
      break;

    default:
      printf("abobus\n");
      return 993;
      break;

    } // switch

  } // while
  if (dotSet == false && endedByExclamOrInterog == false) {
    printf("В конце предложения отсутствует точка.\n");
  }
  cout << endl;
}
