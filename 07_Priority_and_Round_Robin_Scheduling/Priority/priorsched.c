#include <stdio.h>

struct Ambulance {
    char id[10];
    int burst;      // time needed to monitor patient (minutes)
    int priority;   // lower number = more critical
};

int main() {
    struct Ambulance amb[4] = {
        {"A1", 5, 2},
        {"A2", 3, 1},
        {"A3", 7, 3},
        {"A4", 4, 2}
    };
    int n = 4;

    // Sort by priority (lower number runs first)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (amb[j].priority > amb[j + 1].priority) {
                struct Ambulance temp = amb[j];
                amb[j] = amb[j + 1];
                amb[j + 1] = temp;
            }
        }
    }

    printf("=== Ambulance Priority Scheduling ===\n");
    printf("Ambulance | Priority | Start | Finish\n");

    int time = 0;
    for (int i = 0; i < n; i++) {
        int start = time;
        time += amb[i].burst;
        printf("%-9s | %8d | %5d | %6d\n", amb[i].id, amb[i].priority, start, time);
    }

    printf("\nAll ambulances monitored.\n");
    return 0;
}
