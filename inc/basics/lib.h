#ifndef LIB_H_
#define LIB_H_

/* C INCLUDES */
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>

#define matoi(x) my_getnbr(x)
#define len(x) my_strlen(x)
#define sput(x) my_putstr(x)
#define nput(x) my_putnbr(x)
#define putt(x) my_put_tab(x)
#define tab(x) my_put_tab(x)

typedef struct info_t
{
    int iter;
    int size;
    int bol;
    int nbr_null;
} info_t;

/* LIB */
void chain_free(char const *, ...);
void free_tab(char **);
char *return_get_line(char *, char *);
char *get_next_line(int);
char *int_to_char(int);
char *strconcat(char const *, char const *);
int len_tab(char **);
char **str_to_tab(char *, char);
int nbr_char_str(char *, char);
void puterror(char *);
void puti(int n);
void putl(long n);
void my_put_tab(char **);
char *my_revstr(char *);
int my_strlen(char const *);
char *my_strcpy(char *, char *);
char *my_strstr(char *, char *);
void my_putstr(char const *);
void my_putchar(char);
bool my_strcmp(char const *, char const *);
bool my_strncmp(char const *s1, char const *s2, size_t size);
int matoi(char const *s);
long matol(char const *s);
char *my_strdup(char *s);
void address_put(long long n);
void bin_put(long long n);
void hexa_put(long long n);
void float_put(double n, int prec);
void long_put(long n);
long long power(long long max, int power);
void print(char const *format, ...);

#endif
