#include "const_file.h"

int main() {
    start(arr.old);
    return 0;
}

int start(int old[Y][X]) {
    int neww[Y][X];
    control(old);
    char key;
    FILE *fp;
    fp = freopen("/dev/tty", "r", stdin);
    while (1) {
            key = getch();
            if (key == 'Q' || key == 'q') {
                break;
            } else if (key == ' ') {
                    draw(old, Y, X);
                    extra_mas(old, neww);
                    check_cell(old, neww);
                    draw(old, Y, X);
                }
    }
    fclose(fp);
    return 0;
}

void control(int old[Y][X]) {
    printf("Choose a pattern:\n1. long\n2. gun\n3. pulsar\n");
    printf("4. cowboy\n5. train\n6. cow\n7. stripe\n");
    char number = getchar();
    FILE *input;
    int tmp;
    switch (number) {
        case '1':
            input = freopen("1_long.txt", "r", stdin);
            break;
        case '2':
            input = freopen("2_gun.txt", "r", stdin);
            break;
        case '3':
            input = freopen("3_pulsar.txt", "r", stdin);
            break;
        case '4':
            input = freopen("4_cowboy.txt", "r", stdin);
            break;
        case '5':
            input = freopen("5_train.txt", "r", stdin);
            break;
        case '6':
            input = freopen("6_cow.txt", "r", stdin);
            break;
        case '7':
            input = freopen("7_stripe.txt", "r", stdin);
            break;
        default:
        printf("Pattern with this number doesn't exist");
    }
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X+1; j++) {
            tmp = fgetc(input);
            if (tmp == '0') {
                old[i][j] = 0;
            }
            if (tmp == '1') {
                old[i][j] = 1;
            }
        }
    }
    fclose(input);
}

int draw(int old[Y][X], int rows, int col) {
     for (int i = 0; i < rows; i ++) {
  for (int j = 0; j <col; j ++) {
      if (old[i][j] == 1 && i < rows-1 && j < col-1 && i != 0 && j != 0) {
          printf(LIVE_CELL);
          continue;
      }
      if (old[i][j] != 1 && i < rows-1 && j < col-1 && j != 0 && i != 0) {
          printf(DEAD_CELL);
          continue;
      }
      if ((j == 0 || j == col-1) && i != 0) {
          printf(SYMBOL_BORD_VERT);
          continue;
      }
      if (i == 0 || i == rows-1) {
          printf(SYMBOL_BORD_GHOR);
          continue;
      }
  }
}
printf("\nControls: SPACE\nExit: Q\n");
return 0;
}

void extra_mas(int old[Y][X], int neww[Y][X]) {
    for (int i = 0; i < Y; i++) {
        for (int j = 0 ; j < X; j++) {
            neww[i][j] = old[i][j];
        }
    }
}

void check_cell(int old[Y][X], int neww[Y][X]) {
    for (int i = 0; i < Y; i++) {
        for (int j = 0 ; j < X; j++) {
            if (old[i][j] == 0) {
                old[i][j] = death_cell(neww, i, j);
            }
            if (old[i][j] == 1) {
                old[i][j] = life_cell(neww, i, j);
            }
        }
    }
}

int death_cell(int neww[Y][X], int i, int j) {
int count = 0;
if (neww[(i-1+Y)%25][(j-1+X)%80] == 1)
count++;
if (neww[(i-1+Y)%25][(j+X)%80] == 1)
count++;
if (neww[(i-1+Y)%25][(j+1+X)%80] == 1)
count++;
if (neww[(i+Y)%25][(j-1+X)%80] == 1)
count++;
if (neww[(i+Y)%25][(j+1+X)%80] == 1)
count++;
if (neww[(i+1+Y)%25][(j-1+X)%80] == 1)
count++;
if (neww[(i+1+Y)%25][(j+X)%80] == 1)
count++;
if (neww[(i+1+Y)%25][(j+1+X)%80] == 1)
count++;

if (count == 3) {
    return 1;
} else {
    return 0;
}
}

int life_cell(int neww[Y][X], int i, int j) {
    int count = 0;
if (neww[(i-1+Y)%25][(j-1+X)%80] == 1)
count++;
if (neww[(i-1+Y)%25][(j+X)%80] == 1)
count++;
if (neww[(i-1+Y)%25][(j+1+X)%80] == 1)
count++;
if (neww[(i+Y)%25][(j-1+X)%80] == 1)
count++;
if (neww[(i+Y)%25][(j+1+X)%80] == 1)
count++;
if (neww[(i+1+Y)%25][(j-1+X)%80] == 1)
count++;
if (neww[(i+1+Y)%25][(j+X)%80] == 1)
count++;
if (neww[(i+1+Y)%25][(j+1+X)%80] == 1)
count++;

if (count == 2 || count == 3) {
    return 1;
} else {
    return 0;
}
}

int getch() {
  struct termios oldattr, newattr;
  int ch;
  tcgetattr(STDIN_FILENO, &oldattr);
  newattr = oldattr;
  newattr.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
  return ch;
}
