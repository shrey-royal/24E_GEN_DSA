#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void removePunctuation(char *str) {
    int i, j = 0;
    for (int i = 0; str[i]; i++) {
        if (isalpha(str[i]) || isspace(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

int main() {
    char text[256];
    WordFrequency words[MAX_WORDS];
    int wordCount = 0;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;

    toLowerCase(text);
    removePunctuation(text);

    char *token = strtok(text, " ");
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i].word, token) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }
        if (!found && wordCount < MAX_WORDS) {
            strcpy(words[wordCount].word, token);
            words[wordCount].count = 1;
            wordCount++;
        }
        token = strtok(NULL, " ");
    }

    printf("Word Frequencies: \n");
    for (int i = 0; i < wordCount; i++) {
        printf("- %s: %d\n", words[i].word, words[i].count);
    }
    
    return 0;
}