#include <stdio.h>

void copyString(char *source, char *destination) {
    if (*source == '\0') {
        *destination = '\0'; 
        return;
    }
    *destination = *source;
    copyString(source + 1, destination + 1);
}

int main() {
    char source[100], destination[100];

    printf("Enter a string: ");
    fgets(source, sizeof(source), stdin);

    for (int i = 0; source[i] != '\0'; ++i) {
        if (source[i] == '\n') {
            source[i] = '\0';
            break;
        }
    }

    copyString(source, destination);

    printf("Source string: %s\n", source);
    printf("Copied string: %s\n", destination);

    return 0;
}

