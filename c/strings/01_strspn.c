#include <stdio.h>
#include <string.h>

int main() {
  char name[128] = {0};
  
  printf("Enter name: ");
  fgets(name, 128, stdin);
  
  printf("Strlen: %ld\n", strlen(name));
  printf("Return of strspn: %ld\n", strspn(name, "seshu"));
  printf("Return of strcspn: %ld\n", strcspn(name, "a"));
  printf("Name wth newline: %s\n", name);
  name[strcspn(name, "\n")] = '\0';
  printf("Strlen After: %ld\n", strlen(name));
  printf("Return of strcspn: %ld\n", strcspn(name, "\n"));
  printf("Name wth newline: %s\n", name);
  name[strcspn(name, "\n")] = '\0';
  printf("Strlen After: %ld\n", strlen(name));
  printf("Return of strspn: %ld\n", strspn(name, "\n"));
  printf("Name wth newline: %s\n", name);
  return 0;
}