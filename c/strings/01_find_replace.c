#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t calculate_new_size(const char *str, const char *found_str, const char *replace_str) {
  int count = 0;
  const char* pos = str;
  while(strstr(pos, found_str) != NULL) {
    count++;
    pos += strlen(found_str);
  }

  return strlen(str) + count * (strlen(replace_str) - strlen(found_str)) + 1;
}

char *str_replace(const char *str, const char *found_str, const char *replace_str) {
  if (strstr(str, found_str) == NULL) {
    return NULL;
  }

  size_t new_size = calculate_new_size(str, found_str, replace_str);
  char *result = (char *)malloc(new_size);
  if (result == NULL) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  const char *pos = str;
  char *current = result;
  size_t f_len = strlen(found_str);
  size_t r_len = strlen(replace_str);
  size_t position_len = 0;

  while ((pos = strstr(str, found_str)) != NULL) {
    position_len = pos - str;
    memcpy(current, str, position_len);
    current += position_len;

    memcpy(current, replace_str, r_len);
    current += r_len;

    str = pos + f_len;
  }

  memcpy(current, str, sizeof(str));

  return result;  
}

int main() {
  char string_a[64] = {0};
  char string_b[16] = {0};
  char string_c[16] = {0};
  
  printf("Enter the original string: ");
  fgets(string_a, 64, stdin);
  string_a[strcspn(string_a, "\n")] = '\0';

  printf("Enter the substring to find: ");
  fgets(string_b, 16, stdin);
  string_b[strcspn(string_b, "\n")] = '\0';

  printf("Enter the substring to replace with: ");
  fgets(string_c, 16, stdin);
  string_c[strcspn(string_c, "\n")] = '\0';

  char *ptr = str_replace(string_a, string_b, string_c);
  if (ptr == NULL) {
    printf("%s not found", string_b);
  } else {
    printf("main string: %s\n", ptr);
    free(ptr);
  }

  return 0;
}