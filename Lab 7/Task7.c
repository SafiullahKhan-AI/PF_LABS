#include <stdio.h>
int main()
{
    int i;
	char arr[100];
    printf("Enter the word or sensor code: ");
    scanf("%s", &arr);
    for (i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] >= 'A' && arr[i] <= 'Z')
        {
            arr[i] = arr[i] + 32;
        }
    }
    int vowel = 0, consonent = 0;
    for (i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] >= 'a' && arr[i] <= 'z')
        {
            switch (arr[i])
            {
            case 'a':
                vowel = vowel + 1;
            break;
            
            case 'e':
                vowel = vowel + 1;
            break;
            
            case 'i':
                vowel = vowel + 1;
            break;
            
            case 'o':
                vowel = vowel + 1;
            break;
            
            case 'u':
                vowel = vowel + 1;
            break;
            
            default:
                consonent++;
            }
        }
    }
    printf("%s\n", arr);
    printf("Number of Vowels are : %d\n", vowel);
    printf("Number of Consonents are : %d\n", consonent);
}
