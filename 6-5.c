#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define HASHSIZE 101

struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
};

struct nlist *install(char *name, char *defn);
struct nlist *lookup(char *s);
unsigned hash(char *s);
void undef(char *name);

static struct nlist *hashtab[HASHSIZE];

int main() 
{
	struct nlist *p;

	p = install("Hello", "world");
	printf("%s:\t%s\n", p->name, p->defn);
	undef("Hello");
	printf("%s:\t%s\n", p->name, p->defn);
	p = install("Hello", "world");
	printf("%s:\t%s\n", p->name, p->defn);
}

unsigned hash(char *s)
{
	unsigned hashval;

	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
	struct nlist *np;

	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np;
	return NULL;
}

struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) {
		np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL || (np->name = strdup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} else
		free((void *) np->defn);
	if ((np->defn = strdup(defn)) == NULL)
		return NULL;
	return np;
}

void undef(char *name)
{
	struct nlist *p;

	if ((p = lookup(name)) == NULL)
		return;
	hashtab[hash(name)] = p->next;
	free((void *) p->name);
	free((void *) p->defn);
	free((void *) p);
}
