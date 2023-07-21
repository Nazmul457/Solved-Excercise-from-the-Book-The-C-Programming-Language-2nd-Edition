#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000 /* max #lines to be sorted */
#define MAXLEN 1000   /* max length of any input line */

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void my_qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *, int), int reverse, int fold);
int numcmp(const char *s1, const char *s2, int fold);

/* sort input lines */
int main(int argc, char *argv[]) {
    int nlines; /* number of input lines read */
    int numeric = 0; /* 1 if numeric sort */
    int reverse = 0; /* 1 if reverse sort */
    int fold = 0;    /* 1 if case folding */

    int i;
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0)
            numeric = 1;
        else if (strcmp(argv[i], "-r") == 0)
            reverse = 1;
        else if (strcmp(argv[i], "-f") == 0)
            fold = 1;
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        my_qsort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *, int))(numeric ? numcmp : strcasecmp), reverse, fold);
        writelines(lineptr, nlines);
        return 0;
    }
    else {
        printf("input too big to sort\n");
        return 1;
    }
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = malloc(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0'; /* remove newline character */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines) {
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

/* qsort: sort v[left]...v[right] into increasing order */
void my_qsort(void *v[], int left, int right, int (*comp)(void *, void *, int), int reverse, int fold) {
    int i, last;
    void swap(void *v[], int i, int j);

    if (left >= right)
        return;

    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if ((reverse && (*comp)(v[i], v[left], fold) > 0) || (!reverse && (*comp)(v[i], v[left], fold) < 0))
            swap(v, ++last, i);
    }
    swap(v, left, last);
    my_qsort(v, left, last - 1, comp, reverse, fold);
    my_qsort(v, last + 1, right, comp, reverse, fold);
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(const char *s1, const char *s2, int fold) {
    double v1 = atof(s1);
    double v2 = atof(s2);

    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

/* swap: interchange v[i] and v[j] */
void swap(void *v[], int i, int j) {
    void *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int getline(char *s, int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

