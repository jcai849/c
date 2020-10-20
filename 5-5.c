#include <stdio.h>

int strcmp(char *s, char *t);
void strcpy(char *s, char *t);
void strcat(char *s, char *t);

char strncpy(char *s, char *ct, int n); /* copy at most n chars of string ct to
					   s; return s. Pad with '\0's if t has
					   fewer than n characters */
char strncat(char *s, char *ct, int n); /* concat at most n characters of
					   string ct to string s, terminate s
					   with '\0'; return s */
int strncmp(char *cs, char *ct, int n); /* compare at most n characters of
					   string cs to string ct; return <0 if
					   cs<ct, 0 if cs==ct, or >0 if cs>ct
					   */

int main()
{
	char s[] = "test test",
	     low[] = "AA",
	     high[] = "ZZ";
	char t[strlen(s)+2], u[strlen(s)+2];

	strcpy(t, s);
	strcpy(u, s);

	strcat(t, low);
	strcat(u, high);

	strcmp(s, s);
	strcmp(t, s);
	strcmp(u, s);
	strcmp(t, u);

	return 0;
}
