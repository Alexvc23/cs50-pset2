#include<string.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int lArray(char ** a);

int countL (char ** p);


int main(int argc, char *myArray[])
{

	
	if( lArray(myArray) != 2)
	{
		printf("Usage: ./subtitution key\n");
		exit(1);
	}

	// Checks if ther are at least 26 characters	
	int lenArray = strlen(myArray[1]);
	if(lenArray!=26)
	{
		printf("key must contain 26 characters.\n");
		exit(1);
	}
	
	if(countL(myArray) == 1)
	{
		printf("Invalid Key\n");
		exit(1);
	}

	// Variables 
	int i;
	char *plainText = malloc(1024 * sizeof(char));
	printf("plaitext:   ");
        scanf("%[^\n]s",plainText);	
	int len = strlen(plainText);
	plainText = (char *)realloc(plainText,len + 1);	
	char cipherText[len];

	// Checks characters different than the alphabet
	for(i = 0;i < len;i++)
	{
		if((myArray[1][i] >='a' && myArray[1][i] <='z') || (myArray[1][i] >='A'&&                                myArray[1][i] <='Z'))
		{
			break;
		}
		else
		{			
			printf("Usage: ./subtitution key");
		}
	}
	
	// Gets character position in the alphabet depending on lower or upper case
	for(i = 0;i < len;i++)
	{	
		int current = plainText[i];

		if(plainText[i] >='a' && plainText[i] <='z')
		{
			cipherText[i] = (myArray[1][current -'a']) >= 'a' && 
				        (myArray[1][current -'a']) <= 'z'? myArray[1][current - 'a']: 
				        (myArray[1][current - 'a']) + 32;
		}
		else if(plainText[i] >='A' && plainText[i] <='z')
		{
			cipherText[i] = (myArray[1][current -'A']) >= 'A' && 
		                        (myArray[1][current -'A']) <= 'Z'? myArray[1][current - 'A']: 
				        (myArray[1][current - 'A']) - 32;
		
		}	
		else 
		{
			cipherText[i] = plainText[i];
		}
	}
	
	printf("ciphertext: ");
	
	for(i = 0; i < len ; i++)
	{
		printf("%c",cipherText[i]);	
	}
	
	printf("\n");
			
}


// Checks if the users is providing the input key correctly no more than two words
int lArray(char ** a)
{
	int lenMyArray = 0;
	while ( a[lenMyArray] != 0 )
	{
		lenMyArray++;
	}
	return lenMyArray;
}

// Function to avoit duplicated letters 
int countL (char ** p)
{
	char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n'
		            ,'o','p','q','r','s','t','u','v','w','x','y','z'};
	int count = 0;
	int len = strlen(p[1]);

	for(int i = 0; i < 26; i++)
	{
		for(int j = 0; j < len; j++)
		{	if(p[1][j] >= 'A' && p[1][j] <= 'Z')
			{	
				if(p[1][j] == alphabet[i]-32)
				{
					count++;
				}
			}
			else 
			{
				if(p[1][j] == alphabet[i])
				{
					count++;
				}
			}
		}

			if(count > 1 || count == 0)
			{
			return 1;
			}
		
		count = 0;		
	}

        return 0;
		

}	
