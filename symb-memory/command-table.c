#define _GNU_SOURCE

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char* commands[] =
{
  "PING",
  "PONG",
  "FOO",
  "FOOBAR",
  "AWESOMENESS"
};

int main(int argc, char *argv[]) {

  int found = 0;
  char buf[1024];
  FILE *f = fopen("symb", "r");
  assert (f);

  fread(buf, 1023, 1, f);
  buf[1023] = 0;
  if (ferror(f)) {
    printf("Error\n");
    return 1;
  }

  char *space = strchrnul(buf, ' ');
  *space = 0;

  for (int i = 0; i < sizeof(commands) / sizeof(char *); i++) {

    if (strcmp(commands[i], buf) == 0) {
      printf("command %s found!\n", commands[i]);
      found = 1;
      break;
    }
  }

  if (found)
    return 0;
  else
    return 1;
}
