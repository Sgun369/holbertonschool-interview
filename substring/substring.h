#ifndef SUBSTRING_H
#define SUBSTRING_H
int *find_substring(char const *s, char const **words, int nb_words, int *n);
int match_words(const char *start, int word_len, const char **words,
	int nb_words, int *ref_count);
#endif
