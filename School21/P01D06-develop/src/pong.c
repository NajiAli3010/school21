// I WANT TO PLAY WITH YOU
//        YOUR FRIEND, AI
#include <stdio.h>
#include <stdlib.h>  // 18 G-5 left

void clrscr(void);
void clrstdin();
int rac1Move(int coordCentrRac1_y, char curBut1);
int rac2Move(int coordCentrRac2_y, char curBut2);
int ballMove(int coordCentrRac1_y, int coordCentrRac2_y);
int ballSpeed = 1;
int ballSpeed_2 = 1;
int coordBall_x = 39;
int coordBall_y = 12;
int flag = 0;
int pts1 = 0;
int pts2 = 0;
char playGround[25][80];

int main() {
    int coordCentrRac1_x, coordCentrRac1_y, coordCentrRac2_x, coordCentrRac2_y;
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            playGround[i][j] = ' ';
            }
    }
    playGround[12][39] = '*';
    playGround[11][0] = '|';
    playGround[12][0] = '|';
    playGround[13][0] = '|';
    coordCentrRac1_x = 0;
    coordCentrRac1_y = 12;
    playGround[11][79] = '|';
    playGround[12][79] = '|';
    playGround[13][79] = '|';
    coordCentrRac2_x = 79;
    coordCentrRac2_y = 12;
    clrscr();
    while (1) {
        playGround[coordBall_y][coordBall_x] = ' ';
        ballMove(coordCentrRac1_y, coordCentrRac2_y);
        playGround[coordBall_y][coordBall_x] = '*';
        playGround[coordCentrRac1_y-1][coordCentrRac1_x] = ' ';
        playGround[coordCentrRac1_y][coordCentrRac1_x] = ' ';
        playGround[coordCentrRac1_y+1][coordCentrRac1_x] = ' ';
        char curBut1, curBut2, space;
        scanf("%c%c%c", &curBut1, &space, &curBut2);
        if (curBut1 == 'q' || curBut2 == 'q')
            return 0;
        clrstdin();
        clrscr();
        printf("First turn: %c \nSecond turen: %c\n", curBut1, curBut2);
        coordCentrRac1_y = rac1Move(coordCentrRac1_y, curBut1);
        playGround[coordCentrRac1_y-1][coordCentrRac1_x] = '|';
        playGround[coordCentrRac1_y][coordCentrRac1_x] = '|';
        playGround[coordCentrRac1_y+1][coordCentrRac1_x] = '|';
        playGround[coordCentrRac2_y-1][coordCentrRac2_x] = ' ';
        playGround[coordCentrRac2_y][coordCentrRac2_x] = ' ';
        playGround[coordCentrRac2_y+1][coordCentrRac2_x] = ' ';
       // printf("Second player turn: ");
        coordCentrRac2_y = rac2Move(coordCentrRac2_y, curBut2);
        playGround[coordCentrRac2_y-1][coordCentrRac2_x] = '|';
        playGround[coordCentrRac2_y][coordCentrRac2_x] = '|';
        playGround[coordCentrRac2_y+1][coordCentrRac2_x] = '|';
        int k = 0;
        printf("\tPlayer 1: %d\tPlayer 2: %d\n", pts1, pts2);
        if (pts1 > pts2 && pts1 > 2) {
            clrscr();
            printf("PLAYER 1 WIN!!!");
            return 0;
        } else if (pts2 > pts1 && pts2 > 2) {
            clrscr();
            printf("PLAYER 2 WIN!!!");
            return 0;
        }
        while (k < 80) {
            printf("_");
            k++;
        }
        printf("\n");
        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 80; j++) {
                printf("%c", playGround[i][j]);
            }
            printf("\n");
        }
        k = 0;
        while (k < 80) {
            printf("_");
            k++;
        }
        printf("\n");
       // break;
    }
    return 0;
}


int ballMove(int coordCentrRac1_y, int coordCentrRac2_y) {
    coordBall_x+=ballSpeed;
    if (flag == 1) {  // izmenenie traektorii pod yglom
        coordBall_y += ballSpeed_2;
    }
    if (coordBall_y == 0 || coordBall_y == 24) {  // ydar verh niz
        ballSpeed_2 *= -1;
    }
    if (coordBall_y != coordCentrRac2_y || coordBall_y != coordCentrRac2_y + 1
        || coordBall_y != coordCentrRac2_y - 1) {
        if (coordBall_x == 0) {  // pts++2
            pts2++;
            flag = 0;
            coordBall_x = 39;
            coordBall_y = 12;
        } else if (coordBall_x == 79) {  // pts++1
            pts1++;
            flag = 0;
            coordBall_x = 39;
            coordBall_y = 12;
        }
    }
    if (coordBall_x == 78 && ballSpeed == 1 && coordBall_y == coordCentrRac2_y + 1) {  // Niz2Rac
        ballSpeed *= -1;
        ballSpeed_2 *= -1;
        coordBall_x += ballSpeed;
        coordBall_y -= 1;
        flag = 1;
    } else if (coordBall_x == 78 && ballSpeed == 1 && coordBall_y == coordCentrRac2_y - 1) {  // Verh2Rac
        ballSpeed*=-1;
        ballSpeed_2 *= -1;
        coordBall_x+=ballSpeed;
        coordBall_y+=1;
        flag = 1;
    }
    if (coordBall_x == 1 && ballSpeed == -1 && coordBall_y == coordCentrRac1_y + 1) {  // Niz1Rac
        ballSpeed*=-1;
        ballSpeed_2 *= -1;
        coordBall_y -= 1;
        coordBall_x += ballSpeed;
        flag = 1;
    } else if (coordBall_x == 1 && ballSpeed == -1 && coordBall_y == coordCentrRac1_y - 1) {  // Verh1Rac
        ballSpeed *= -1;
        ballSpeed_2 *= -1;
        coordBall_y += 1;
        coordBall_x += ballSpeed;
        flag = 1;
    }
    if (coordBall_x == 78 && ballSpeed == 1 && coordBall_y == coordCentrRac2_y) {  // Centr
        ballSpeed *= -1;
    }
    if (coordBall_x == 1 && ballSpeed == -1 && coordBall_y == coordCentrRac1_y) {  // Centr
        ballSpeed *= -1;
    }
    return 0;
}

void clrstdin() {
    int c;
    while ((c = getchar()) != EOF && c != '\n') {
        int k = 0;
    } /* <note the semicolon! */
}
void clrscr(void) {
    printf("\033[2J");   // Clear the entire screen.
    printf("\033[0;0f");  // Move cursor to the top left hand corner
}

int rac1Move(int coordCentrRac1_y, char curBut1) {
    switch (curBut1) {
        case 'A': coordCentrRac1_y--; break;  // A
        case 'Z': coordCentrRac1_y++; break;  // Z
    }
    if (coordCentrRac1_y == 0) {
        coordCentrRac1_y++;
    } else if (coordCentrRac1_y == 24) {
        coordCentrRac1_y--;
    }
    return coordCentrRac1_y;
}

int rac2Move(int coordCentrRac2_y, char curBut2) {
    switch (curBut2) {
        case 'K': coordCentrRac2_y--; break;  // K
        case 'M': coordCentrRac2_y++; break;  // M
    }
    if (coordCentrRac2_y == 0) {
        coordCentrRac2_y++;
    } else if (coordCentrRac2_y == 24) {
        coordCentrRac2_y--;
    }
    return coordCentrRac2_y;
}
