#include "shell.h"

int var_count = 0; 
keyvalue variables[MAX_VARIABLE];

void set_variable(char* key, char* value) {
    if (key == NULL || value == NULL) { 
        printf("Error: Key or value cannot be NULL.\n");
        return;
    }

    for (int i = 0; i < var_count; i++) {
        if (strcmp(variables[i].key, key) == 0) { 
            free(variables[i].value); 
            variables[i].value = strdup(value); 
            return;
        }
    }

    if (var_count < MAX_VARIABLE) {
        variables[var_count].key = strdup(key); 
        variables[var_count].value = strdup(value); 
        if (variables[var_count].key == NULL || variables[var_count].value == NULL) {
            printf("Error: Memory allocation failed.\n");
            return;
        }
        var_count++;
    } else {
        printf("Max variable limit reached!\n");
    }
}

void unset_variable(char* key) {
    if (key == NULL) { 
        printf("Error: Key cannot be NULL.\n");
        return;
    }

    for (int i = 0; i < var_count; i++) {
        if (strcmp(variables[i].key, key) == 0) {
            free(variables[i].key); 
            free(variables[i].value); 
            for (int j = i; j < var_count - 1; j++) {
                variables[j] = variables[j + 1]; 
            }
            var_count--;
            return;
        }
    }
    printf("Error: Variable with key '%s' not found.\n", key);
}