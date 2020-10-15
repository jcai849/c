#include <stdio.h>

#define LIM	10000
#define B_SLASH	0x5c
#define N_LWR	0x6E
#define T_LWR	0x74
#define RS	0x1E

void escape(char s[], char t[]);
void unescape(char t[], char s[]);

int main()
{
	int c, i;
	char s[LIM], t[LIM], u[LIM];

	for (i = 0; (c = getchar()) != EOF && i<LIM; ++i) 
		s[i] = c;
	s[i+1] = '\0';
	escape(s, t);
	printf("%s%c", t, RS);
	unescape(t, u);
	printf("%s%c", u, RS);
	return 0;
}

void unescape(char t[], char s[])
{
	int i, j;

	j = 0;
	for (i=0; t[i] != '\0' && j<LIM; ++i)
		switch(t[i]) {
			case '\\':
				switch(t[++i]) {
					case 't':
						s[j++] = '\t';
						break;
					case 'n':
						s[j++] = '\n';
						break;
					default:
						s[j++] = t[--i];
						break;
				}
				break;
			default:
				s[j++] = t[i];
				break;
		}
}

void escape(char s[], char t[])
{
	int i, j;

	j = 0;
	for (i = 0; s[i] != '\0' && j<LIM; ++i)
		switch(s[i]) {
			case '\t':
				t[j++] = B_SLASH;
				t[j++] = T_LWR;
				break;
			case '\n':
				t[j++] = B_SLASH;
				t[j++] = N_LWR;
				break;
			default:
				t[j++] = s[i];
				break;
		}
	t[j] = '\0';
}
