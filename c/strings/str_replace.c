#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Count occurrences of a substring in a string
int count_occurrences(const char *str, const char *find) {
    int count = 0;
    const char *pos = str;
    
    while ((pos = strstr(pos, find)) != NULL) {
        count++;
        pos += strlen(find);
    }
    
    return count;
}

// Calculate the new size needed for the replaced string
size_t calculate_new_size(const char *str, const char *find, const char *replace) {
    int count = count_occurrences(str, find);
    return strlen(str) + count * (strlen(replace) - strlen(find)) + 1;
}

// Replace all occurrences of 'find' with 'replace' in 'str'
char* str_replace(const char *str, const char *find, const char *replace) {
    // Handle null pointers
    if (!str || !find || !replace) {
        return NULL;
    }
    
    // If 'find' is empty or not found in string, return a copy of the original
    if (strlen(find) == 0 || strstr(str, find) == NULL) {
        return strdup(str);
    }
    
    // Calculate the space needed for the new string
    size_t new_size = calculate_new_size(str, find, replace);
    char *result = (char*)malloc(new_size);
    
    if (!result) {
        return NULL;  // Memory allocation failed
    }
    
    const char *pos = str;            // Current position in original string
    const char *next_pos;             // Position of next occurrence
    char *current = result;           // Current position in result string
    size_t find_len = strlen(find);
    
    // Copy and replace parts until no more occurrences are found
    while ((next_pos = strstr(pos, find)) != NULL) {
        // Copy everything up to the occurrence
        size_t prefix_len = next_pos - pos;
        memcpy(current, pos, prefix_len);
        current += prefix_len;
        
        // Copy the replacement string
        strcpy(current, replace);
        current += strlen(replace);
        
        // Move position forward
        pos = next_pos + find_len;
    }
    
    // Copy the remaining part of the string
    strcpy(current, pos);
    
    return result;
}

// Example usage and test cases
void test_str_replace() {
    // Test case 1: Basic replacement
    char *result1 = str_replace("hello elephant this is elephant", "elephant", "apple");
    printf("Test 1: %s\n", result1);
    free(result1);
    
    // Test case 2: Multiple replacements
    char *result2 = str_replace("ha ha ha", "ha", "he");
    printf("Test 2: %s\n", result2);
    free(result2);
    
    // Test case 3: Replace with longer string
    char *result3 = str_replace("cat", "cat", "kitten");
    printf("Test 3: %s\n", result3);
    free(result3);
    
    // Test case 4: Replace with shorter string
    char *result4 = str_replace("kitten", "kitten", "cat");
    printf("Test 4: %s\n", result4);
    free(result4);
    
    // Test case 5: No match found
    char *result5 = str_replace("Hello World", "xyz", "abc");
    printf("Test 5: %s\n", result5);
    free(result5);
    
    // Test case 6: Empty strings
    char *result6 = str_replace("", "test", "");
    printf("Test 6: %s\n", result6);
    free(result6);
}

int main() {
    test_str_replace();
    return 0;
}