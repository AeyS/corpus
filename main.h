#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

extern bool Greetings(const char *line, char *result);

extern int split(const char *src, const char *delim, char *result[]);

extern int str_index_of(char *line);

extern int count(char *src, const char *delim);

extern bool compare(char *src, const char *delim);

extern void clear_string(char *result);

extern void substring(char *src, int start, int end, char *result);

extern void debug(char *func_name, char *info);