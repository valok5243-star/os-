#include <stdio.h>

int main() {
    int p, f, i, page[20], frame[20], hit = 0, fault = 0, j;

    printf("Enter number of pages: ");
    scanf("%d", &p);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    printf("Enter page reference string:\n");
    for(i = 0; i < p; i++)
        scanf("%d", &page[i]);

    for(i = 0; i < f; i++)
        frame[i] = -1;

    int k = 0;

    for(i = 0; i < p; i++) {
        int found = 0;

        for(j = 0; j < f; j++) {
            if(frame[j] == page[i]) {
                hit++;
                found = 1;
                break;
            }
        }

        if(!found) {
            frame[k] = page[i];
            k = (k + 1) % f;
            fault++;
        }
    }

    printf("Page Hits: %d\n", hit);
    printf("Page Faults: %d\n", fault);

    return 0;
}
