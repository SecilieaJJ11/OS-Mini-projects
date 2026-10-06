#include <stdio.h>

struct Ambulance {
    char id[10];
    int burst;      // total monitoring time needed (minutes)
    int remaining;
};

int main() {
    struct Ambulance amb[4] = {
        {"A1", 5, 5},
        {"A2", 3, 3},
        {"A3", 7, 7},
        {"A4", 4, 4}
    };
    int n = 4, tq = 2, time = 0;

    struct Ambulance queue[100];
    for (int i = 0; i < n; i++) queue[i] = amb[i];
    int front = 0, rear = n;

    printf("=== Ambulance Round Robin Scheduling (Time Quantum = %d) ===\n", tq);
    printf("Time | Ambulance | Remaining\n");

    while (front < rear) {
        struct Ambulance current = queue[front++];
        int run = (current.remaining < tq) ? current.remaining : tq;
        time += run;
        current.remaining -= run;
        printf("%4d | %-9s | %d\n", time, current.id, current.remaining);
        if (current.remaining > 0) queue[rear++] = current;
    }

    printf("\nAll ambulances completed monitoring.\n");
    return 0;
}
