#include <stdio.h>

void PromptAndGetStrings(char*prompt, char output[][256]);
unsigned int StrLen(char*string);
void ReverseString(char*string);
void MakeUpperCase(char*string);

int main(void)
{
    char output[3][256];
    unsigned int length;

    printf("*** Welcome to Lab 7 ***\n");
    PromptAndGetStrings("Please enter a string: ",output);

    for(int i=0;i<3;i++){
       length=StrLen(output[i]);
       printf("You entered: %s with a length of: %u\n",output[i],length);
    }    

    for(int i=0;i<3;i++){
        length=StrLen(output[i]);
        ReverseString(output[i]);
        printf("Reversed string: %s with a lengthe of: %u\n",output[i],length);
    }
    
    printf("*** Thanks for doing Lab7 ***\n");
}

void PromptAndGetStrings(char *prompt, char output[][256])
{
    for(int i=0;i<3;i++)
    {
        printf("%d. %s",i+1,prompt);
        scanf("%s",output[i]);
    }
}

unsigned int StrLen(char*string)
{   
    int i=0;
    while(*string!='\0'){
        string++;
        i++;
    }
    return i;    
}

void ReverseString(char*string)
{   

    if(*string=='\0'){
        return;
    }
    char *src=string;
    char *end=src+StrLen(string)-1;

    while(end>src){
        char t= *end;
        *end--=*src;
        *src++=t;
    }
}

