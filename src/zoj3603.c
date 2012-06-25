#include <stdio.h>

int main()
{
    int t, n;
    char line[16];
    const int LetterSize = 26;
    int mapA[LetterSize];
    int mapB[LetterSize];
    int i, j;

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (i = 0; i < LetterSize; i++) {
            mapA[i] = mapB[i] = 0;
        }

        scanf("%s", line);
        for (i = 0; i < 12; i++) {
            mapA[line[i] - 'A']++;
        }

        for (j = 1; j < n; j++) {
            scanf("%s", line);
            for (i = 0; i < 12; i++) {
                mapB[line[i] - 'A']++;
            }
            
            for (i = 0; i < LetterSize; i++) {
                if (mapB[i] < mapA[i]) {
                    mapA[i] = mapB[i];
                }
                mapB[i] = 0;
            }
        }

        for (i = 0; i < LetterSize; i++) {
            for (j = 0; j < mapA[i]; j++) {
                putchar(i + 'A');
            }
        }
        putchar('\n');
    }

    return 0;
}
