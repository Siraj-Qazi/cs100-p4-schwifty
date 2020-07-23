#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void left(char word[]);

void right(char word[]);

void inc(char word[]);

void dec(char word[]);

int main(int argc, char **argv)
 {
    if (argc != 3) 
    {
        printf("Invalid number of arguments");
        exit(1);
    }

    FILE *inFile = fopen(argv[1], "r");
    if (!inFile) 
    {
        printf("Could not open file '%s'", argv[1]);
        exit(1);
    }

    for (int i = 0; i < strlen(argv[2]); ++i) 
    {
        if (
            argv[2][i] != 'L' && 
            argv[2][i] != 'R' && 
            argv[2][i] != 'I' && 
            argv[2][i] != 'D'
            )
             {
                printf("You threw off my schwiftiness with schwifty '%c'!", argv[2][i]);
                exit(1);
        }
    }

    //printf("\n %s, strlen: %zu",argv[2],strlen(argv[2]));
    char line[1000];
    while (fgets(line, 999, inFile))
     {
        line[strlen(line) - 1] = '\0';
        char *token = strtok(line, " ");

        while (token)
         {
            for (int i = 0; i < strlen(argv[2]); ++i) 
            {
                switch (argv[2][i])
                 {
                    case 'L':
                        left(token);
                        //printf("\n left = %s",token);
                        break;

                    case 'R':
                        right(token);
                        //printf("\n right = %s",token);
                        break;

                    case 'I':
                        inc(token);
                        //printf("\n inc= %s",token);
                        break;

                    case 'D':
                        dec(token);
                        //printf("\n dec = %s",token);
                        break;
                }
            }
            printf("%s\n", token);
            token = strtok(NULL, " ");
        }

    }

    return 0;
}

void left(char word[]) 
{
    char *temporary_string = strdup(word);
    int str_length = strlen(word);
    int shifting_value = -1;
    shifting_value = str_length + (shifting_value % str_length);
    for (int i = 0; word[i] != 0; i++)
     {
        int new_index = (i + shifting_value) % str_length;
        temporary_string[new_index] = word[i];
    }

    memcpy(word, temporary_string, str_length);
    free(temporary_string);
}

void right(char word[]) 
{
    char *temporary_string = strdup(word);
    int str_length = strlen(word);
    int shifting_value = 1;
    for (int i = 0; word[i] != 0; i++) 
    {
        int new_index = (i + shifting_value) % str_length;
        temporary_string[new_index] = word[i];
    }

    memcpy(word, temporary_string, str_length);
    free(temporary_string);

}

void inc(char word[]) 
{
    for (int i = 0; i < strlen(word); ++i) 
    {
        if (isalpha(word[i])) 
        {
            if (word[i] == 'Z') {
                word[i] = 'A';
            }
            else if (word[i] == 'z') {
                word[i] = 'a';
            }
            else if (isalnum(word[i])) {
                word[i]++;
            }
        } 
        else if (isdigit(word[i])) {
            if (word[i] == '9') {
                word[i] = '0';
            }
            else if (isalnum(word[i])) {
                word[i]++;
            }
        }
    }

}

void dec(char word[])
{
    for (int i = 0; i < strlen(word); ++i)
     {
        if (isalpha(word[i])) 
        {
            if (word[i] == 'A') {
                word[i] = 'Z';
            }
            else if (word[i] == 'a') {
                word[i] = 'z';
            }
            else if (isalnum(word[i])) {
                word[i]--;
            }
        } 
        else if (isdigit(word[i])) {
            if (word[i] == '0') {
                word[i] = '9';
            }
            else if (isalnum(word[i])) {
                word[i]--;
            }
        }
    }

}
