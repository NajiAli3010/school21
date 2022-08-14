#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID 100000

void initialize_doors(struct door* doors);

int main() {
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    for (int i = 0; i < DOORS_COUNT -1; i++) {
        doors[i].status = 0;
        printf("%d %d\n", doors[i].id, doors[i].status);
    }
    printf("%d %d", doors[DOORS_COUNT - 1].id, doors[DOORS_COUNT -1].status = 0);
    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));
    int seed = rand() % MAX_ID;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % MAX_ID;
        doors[i].status = rand() % 2;
    }
}
