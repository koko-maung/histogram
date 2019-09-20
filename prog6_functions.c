//Name: Ko Ko Maung
/*
ECE Application Programming
Professor M.Geiger
4/4/2018
*/
#define _CRT_SECURE_NO_WARNINGS
#define ALPHABET 26

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "prog6_functions.h"
void ReadText(int histo[], int* max)
{
	char ch;
	int i;

	printf("Please enter a line of text:\n\n");
	scanf("%c", &ch);


	do {
		scanf("%c", &ch);
		if (isalpha(ch) > 0) {
			ch = toupper(ch);

			for (i = 0; i < ALPHABET; i++) {
				if (ch == 'A' + i) {
					histo[i]++;
				}
			}
		}
	} while (ch != '\n');


	for (i = 0; i < ALPHABET; i++)
	{
		if (histo[i] > * max)
			* max = histo[i];
	}
}
void DrawHistogram(int histo[], int max)
{
	int i;
	int histoCopy[ALPHABET] = { 0 };
	int nmax = max;															// Çounting how much the most frequently typed letter is used

	printf("\nLETTER FREQUENCIES IN TEXT:\n\n");
	for (i = 0; i < ALPHABET; i++)
		histoCopy[i] = histo[i];
	do {																	// prints '|' for every time the letter is given
		for (i = 0; i < ALPHABET; i++) {
			if (histoCopy[i] == nmax && histoCopy[i] != 0)					// If read
			{
				printf("| ");
				histoCopy[i]--;
			}
			else
				printf("  ");												// If not read
		}
		nmax--;
		printf("\n");
	} while (nmax > 0);														// Prints new lines as the most frequent letter

	printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");		// This is X-axis of the histogram
	printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n");
}
