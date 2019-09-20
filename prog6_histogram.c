//Name: Ko Ko Maung
/*
ECE Application Programming
Professor M.Geiger
4/4/2018
*/
#define _CRT_SECURE_NO_WARNINGS
#define ALPHABET 26

#include <stdio.h>
#include <ctype.h>

void main()
{
	char userInput;
	int i;
	int histArray[ALPHABET] = { 0 };
	int maxLetter = 0;

	do {
		printf("\nEnter a command (C (clear), R(read), P(print) or Q(quit the program)): ");
		scanf(" %c", &userInput);
		switch (userInput) {
		case 'C': case 'c':										// Clear recent histogram 
			maxLetter = 0;
			for (i = 0; i < ALPHABET; i++)
				histArray[i] = 0;
			break;
		case 'R': case 'r':										// Reading single line of text
			ReadText(histArray, &maxLetter);
			break;
		case 'P': case 'p':										// Printing histogram
			DrawHistogram(histArray, maxLetter);
			break;
		case 'Q': case 'q':										// Exit the program 
			return;
		default:												// Error with the input
			printf("Your command %c is invalid...\n", userInput);
			break;
		}
	} while (userInput != 'Q' || userInput != 'q');
}
  
