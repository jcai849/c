#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXWORD 100
#define MAXLINES 20

struct tnode {
	char *word;
	int count;
	int line[MAXLINES];
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode *);
int getword(char *, int, int *);
struct tnode *talloc(void);

int main()
{
	struct tnode *root;
	char word[MAXWORD];
	int linenum = 1;

	root = NULL;
	while (getword(word, MAXWORD, &linenum) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word, linenum);
	treeprint(root);
	return 0;
}

struct tnode *addtree(struct tnode *p, char *w, int linenum)
{
	int cond;

	if (p == NULL) {
		p = talloc();
		p->word = strdup(w);
		p->count = 1;
		p->line[0] = linenum;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0) {
		p->count++;
		if (p->count <= MAXLINES)
			p->line[p->count-1] = linenum;
	}
	else if (cond < 0)
		p->left = addtree(p->left, w, linenum);
	else
		p->right = addtree(p->right, w, linenum);
	return p;
}

void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		while (--p->count >= 0)
			printf("%4d ", p->line[p->count]);
		printf("%s\n", p->word);
		treeprint(p->right);
	}
}

struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

#define BUFSIZE	100

int getword(char *word, int lim, int *linenum)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		if (c == '\n')
			++*linenum;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}

char buf[BUFSIZE];	/* buffer for ungetch */
int bufp = 0;		/* next free position in buf */

int getch(void) /*get a (possibly pushed back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
