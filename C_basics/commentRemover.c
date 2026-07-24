#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10000

void findEOC(char code[], int* i) {
  int n = strlen(code);

  while (*i < n) {
    if (*i + 1 < n && code[*i] == '*' && code[*i + 1] == '/') {
      *i += 2;
      return;
    }

    (*i)++;
  }
}

void removeComments(char code[], char codeWOcomments[]) {
  int i = 0;
  int n = strlen(code);

  int ansInd = 0;

  while (i < n) {
    if (i + 1 < n && code[i] == '/' && code[i + 1] == '*') {
      i += 2;
      findEOC(code, &i);
      continue;
    }

    else if (i + 1 < n && code[i] == '/' && code[i + 1] == '/') {
      while (i < n && code[i] != '\n') i++;
    }

    else {
      codeWOcomments[ansInd] = code[i];
      ansInd++;
      i++;
    }
  }

  codeWOcomments[ansInd] = '\0';
}

int main() {
  char code[MAX_SIZE] = "";
  char line[1000];

  while (fgets(line, sizeof(line), stdin) != NULL) {
    strcat(code, line);
  }

  char ans[MAX_SIZE];

  removeComments(code, ans);

  printf("%s", ans);

  return 0;
}
