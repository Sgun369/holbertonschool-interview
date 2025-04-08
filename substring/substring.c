#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * match_words - compares word count in a window
 * @start: start of the window
 * @word_len: length of each word
 * @s: string
 * @words: list of words
 * @nb_words: number of words
 * @ref_count: reference word counts
 * Return:  if valid substring, 0 otherwise
 */
int match_words(const char *start, int word_len, const char **words,
	int nb_words, int *ref_count)
{
int *seen = calloc(nb_words, sizeof(int));
int i, j;
char *sub;

if (!seen)
return (0);

for (i = 0; i < nb_words; i++)
{
sub = strndup(start + i * word_len, word_len);
if (!sub)
{
free(seen);
return (0);
}

for (j = 0; j < nb_words; j++)
{
if (strncmp(sub, words[j], word_len) == 0)
{
	seen[j]++;
	if (seen[j] > ref_count[j])
	{
		free(seen);
		free(sub);
		return (0);
	}
	break;
}
}

free(sub);

if (j == nb_words)
{
free(seen);
return (0);
}
}

free(seen);
return (1);
}

/**
* find_substring - finds all starting indices of substrings formed
* @s: input string
* @words: array of words
* @nb_words: number of words
* @n: pointer to store result count
*
* Return: array of starting indices
*/
int *find_substring(const char *s, const char **words, int nb_words, int *n)
{
int word_len, sub_len, s_len;
int *indices, *ref_count;
int i, j, count = 0;

*n = 0;
if (!s || !words || nb_words == 0)
return (NULL);

word_len = strlen(words[0]);
sub_len = word_len * nb_words;
s_len = strlen(s);

if (s_len < sub_len)
return (NULL);

ref_count = calloc(nb_words, sizeof(int));
if (!ref_count)
return (NULL);

for (i = 0; i < nb_words; i++)
{
for (j = 0; j < nb_words; j++)
{
if (strncmp(words[i], words[j], word_len) == 0)
{
	ref_count[j]++;
	break;
}
}
}

indices = malloc(sizeof(int) * (s_len - sub_len + 1));
if (!indices)
{
free(ref_count);
return (NULL);
}

for (i = 0; i <= s_len - sub_len; i++)
{
if (match_words(s + i, word_len, words, nb_words, ref_count))
indices[count++] = i;
}

free(ref_count);

if (count == 0)
{
free(indices);
return (NULL);
}

*n = count;
return (indices);
}
