#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
 {
    if(argc != 2)
    {
        printf("That is not valid.\n");
        return 1;
    }
    
    string k = argv[1];
    int klen = strlen(argv[1]);
    
    char kletter;
    
    for(int i = 0; i < klen; i++)
    {
        kletter = k[i];
        
        if(!isalpha(kletter))
        {
            printf("That's not valid\n");
            return 1;
        }
    }
    
    int shift[klen];
    
    for(int i = 0; i < klen; i++)
    {
        if(isupper(k[i]))
            shift[i] = k[i] - 65;
        else
            shift[i] = k[i] - 97;   
    }

    string plaintext = GetString();
    
    int plen = strlen(plaintext);
    int next = 0;
    
    for(int j = 0; j < plen; j++)
    {
       
        if(isalpha(plaintext[j]))
        {
            if(islower(plaintext[j]))
            {
                if(plaintext[j] + shift[next] > 122)
                {  
                    printf("%c", (plaintext[j] + shift[next]) - 26);
                }
                else
                    printf("%c", plaintext[j] + shift[next]);
                next++;
                if(next == klen)
                    next = 0;
            }
            else if(isupper(plaintext[j]))
            {
                if(plaintext[j] + shift[next] > 90)
                {
                    printf("%c", (plaintext[j] + shift[next]) - 26);
                }
                else
                    printf("%c", plaintext[j] + shift[next]);
                next++;
                if(next == klen)
                    next = 0;
            }
        }
        else
            printf("%c", plaintext[j]);
    }
    printf("\n");
    return 0;
 }
