#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *fp_1;
    char ch;
    int n = 0, flag = 0;
    char filename[1000] = {};
    scanf("%d", &n);
    while (n != -1) {
        switch (n) {
            case 1:
                scanf("%s", filename);
                if ((fp_1 = fopen(filename, "r+")) == NULL) {
                    printf("n/a\n");
                    break;
                } else {
                    if ((ch = fgetc(fp_1)) == EOF) {
                        printf("n/a");
                    } else {
                        printf("%c", ch);
                        while ((ch = fgetc(fp_1)) != EOF) {
                            printf("%c", ch);
                        }
                    }
                    printf("\n");
                    flag = 1;
                    break;
                }
            case 2:
                if ((fp_1 = fopen(filename, "a+")) == NULL) {
                    printf("n/a\n");
                    break;
                } else {
                    scanf("\n%c", &ch);
                    while (ch != '\n') {
                        fprintf(fp_1, "%c", ch);
                        scanf("%c", &ch);
                    }
                    fclose(fp_1);
                    fp_1 = fopen(filename, "r");
                    if ((ch = fgetc(fp_1)) == EOF) {
                        printf("n/a");
                    } else {
                        printf("%c", ch);
                        while ((ch = fgetc(fp_1)) != EOF) {
                            printf("%c\n", ch);
                        }
                    }
                }
                printf("\n");
                break;
        }
        if (n != 1 && n != 2) {
            printf("n/a");
            break;
        }
        scanf("%d", &n);
    }
    fclose(fp_1);
    return 0;
}
