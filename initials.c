#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = GetString();
    if(name[0] != ' ')
        {
            printf("%c", toupper(name[0]));
        }
    int q = strlen(name);
    for(int i = 0; i <= q; i++)
    {
        if(name[i] == 32 && name[i + 1] != 32 && i + 1 < q)
        {
            printf("%c", toupper(name[i + 1]));
        }
    }
    printf("\n");
}   
