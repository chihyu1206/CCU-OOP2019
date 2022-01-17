#include <cctype>
#include <cstring>
#include "Portfolio.h"
const int N = 100;
int main(int argc, char **argv) {
  Portfolio P;
  int i = 0;
  char chr = '\0';
  char input[N], output[N];
  const char *MENU = "*** Portfolio Management menu ***\n"
                     "I   Import accounts from a file\n"
                     "S   Show accounts (brief)\n"
                     "E   Export a banking report (to file)\n"
                     "M   Show this menu\n"
                     "Q   Quit program\n";
  printf("%s", MENU);
  bool flag = true;
  while (flag) {
    printf("> ");
    chr = (char)getchar();
    getc(stdin);
    chr = tolower(chr);

    switch (chr) {
      case 'i': {
        printf("Enter filename: ");
        if (fgets(input, N, stdin) != NULL)
          input[strlen(input) - 1] = '\0';
        P.importFile(input);
        memset(input, '\0', sizeof(input));
        break;
      }
      case 's': {
        P.ShowAccounts();
        break;
      }
      case 'e': {
        printf("Enter filename: ");
        if (fgets(output, N, stdin) != NULL)
          output[strlen(output) - 1] = '\0';
        P.createReportFile(output);
        break;
      }
      case 'm': {
        printf("%s", MENU);
        break;
      }
      case 'q': {
        printf("Goodbye!\n");
        flag = false;
        break;
      }
      default: {
        printf("Warning!! This command is not supported. Try to check the menu.\n");
        break;
      }
    }
  }
	return 0;
}
