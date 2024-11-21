#include <stdio.h>
#include <string.h> 

struct student {
  int id;
  char name[64];
};

int main()
{
  struct student var;

  var.id = 6;
  strcpy(var.name, "seshu");

  printf("id: %d\nname: %s\n\n", var.id, var.name);
  return 0;
}