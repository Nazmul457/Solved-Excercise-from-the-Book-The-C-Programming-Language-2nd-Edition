#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000 /* max length of any input line */
char *lineptr[MAXLINES];

int readlines(char *lineptr[], char *lines, int maxlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);
int getline(char s[], int lim);

#define ARRAYSIZE 10000

main()
{
    int nlines; /* number of input lines read */
    char holder[MAXLEN];
    if ((nlines = readlines(lineptr, holder, MAXLINES)) >= 0)
    {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}

int getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* readlines: read input lines */
int readlines(char *lineptr[], char *lines, int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    p = lines; // Set the initial pointer to the start of the supplied holder array
    while ((len = getline(line, MAXLEN)) > 0)
    {
        if (nlines >= MAXLINES || (p - lines + len) > ARRAYSIZE)
            return -1;
        else
        {
            line[len - 1] = '\0'; /* delete newline(\n) */
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len; // Move the pointer to the next available position
        }
    }

    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);
    if (left >= right) /* do nothing if array contains */
        return;        /* fewer than two elements */
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

