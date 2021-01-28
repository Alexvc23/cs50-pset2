#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

float countW(char * p);
float countSen(char * t);
float alphaLen(char * z);



int main(void)
{
	char * input;
	input = (char *)malloc(2024);
	// assign input to variable input
	printf("Text: ");
	scanf("%[^\n]s\n", input);
	// Realloc memory 
	input = realloc(input,strlen(input) + 1);
	input[strlen(input) + 1] = '\0';
	// Variables
	int stringLen = strlen(input);
	float l = (alphaLen(input) / countW(input)) * 100;
	float s = (countSen(input) / countW(input)) * 100;
	float index = 0.0588 * l - 0.296 * s - 15.8;	
	
	if(index >= 16)
	{
		printf("Grade 16+\n");

	}
	else if(index < 1)
	{
		printf("Before Grade 1\n");
	}
	else
	{
		printf("Grade %1.0f\n",index);
	}

}

float countW(char * p)
{
	int count = 0;
	
	for( int i = 0; i < strlen(p); i++)
	{
		if(p[i] == 32)
		{
			count++;
		}
	}
	
	if(count < 1 )
	{
		return 0;
	}

	return count + 1;
}

float countSen(char * t)
{
	int count = 0;

	for( int i = 0; i < strlen(t); i++)
	{
		if(t[i] == 33 || t[i] == 46 || t[i] == 63)
		{
			count++;
		}
	}

	if( count < 1 )
	{
		return 1;
	} 

	return count;
}

float alphaLen(char * z) 
{
	int count = 0;
	while ( *z != '\0')
	{
		if((*z >= 'a' && *z <= 'z') || (*z >= 'A' && *z <= 'Z'))
		{
			count++;
		}
		
		z++;
	}

	return count;
}
	


