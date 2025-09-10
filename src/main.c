#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALF_S 26

static const char *m_alpha[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", 
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." 
};

static const char *alpha[] = {
    "A","B","C","D","E","F","G","H","I","J",
    "K","L","M","N","O","P","Q","R","S","T",
    "U","V","W","X","Y","Z"
};

void encode(const char *str) {
    for (size_t i = 0; i < strlen(str); i++) {
        char c = toupper(str[i]);
        if (c >= 'A' && c <= 'Z') {
            printf("%s ", m_alpha[c - 'A']);
        } else if (c == ' ') {
            printf("/ ");
        }
    }
    printf("\n");
}

void decode(const char *str) {
    char *input = strdup(str);
    char *token = strtok(input, " ");

    while (token != NULL) {
        if (strcmp(token, "/") == 0) {
            printf(" ");
        } else {
            int found = 0;
            for (int i = 0; i < ALF_S; i++) {
                if (strcmp(token, m_alpha[i]) == 0) {
                    printf("%s", alpha[i]);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("?");
            }
        }
        token = strtok(NULL, " ");
    }
    printf("\n");
    free(input);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s < -e | -d > <string>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "-e") == 0) {
        encode(argv[2]);
    } else if (strcmp(argv[1], "-d") == 0) {
        decode(argv[2]);
    } else {
        fprintf(stderr, "Invalid flag. Use -e (encode) or -d (decode)\n");
        return 1;
    }

    return 0;
}
