#include <stdio.h>
#include <stdlib.h>

#define MAX_TAB_STOPS 100

void entab(int tab_stops[], int num_stops) {
    int c;
    int current_pos = 0;
    int space_count = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            space_count++;
            current_pos++;

            if (current_pos % tab_stops[0] == 0) {
                putchar('\t');
                space_count = 0;
            }
        } else {
            while (space_count > 0) {
                putchar(' ');
                space_count--;
            }

            putchar(c);
            current_pos++;

            if (c == '\n')
                current_pos = 0;
        }

        if (current_pos >= tab_stops[0])
            tab_stops++;
    }
}

void detab(int tab_stops[], int num_stops) {
    int c;
    int current_pos = 0;
	int i;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int next_tab_stop = tab_stops[0] - (current_pos % tab_stops[0]);

            for (i = 0; i < next_tab_stop; i++) {
                putchar(' ');
                current_pos++;
            }

            tab_stops++;
        } else {
            putchar(c);
            current_pos++;

            if (c == '\n')
                current_pos = 0;

            if (current_pos >= tab_stops[0])
                tab_stops++;
        }
    }
}

int main(int argc, char *argv[]) {
    int tab_stops[MAX_TAB_STOPS];
    int num_stops = 0;
	int i;
    if (argc > 1) {
        for (i = 1; i < argc && num_stops < MAX_TAB_STOPS; i++) {
            tab_stops[num_stops] = atoi(argv[i]);
            num_stops++;
        }
    } else {
        // Default tab settings
        tab_stops[0] = 8;
        num_stops = 1;
    }

    entab(tab_stops, num_stops);
    // detab(tab_stops, num_stops);

    return 0;
}

