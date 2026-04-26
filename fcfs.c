#include <stdio.h>

int main() {
    int n, f, page[20], frame[10], i, j, k = 0, fault = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &page[i]);

    for(i = 0; i < f; i++)
        frame[i] = -1;

    for(i = 0; i < n; i++) {
        int found = 0;
        for(j = 0; j < f; j++) {
            if(frame[j] == page[i]) {
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

    printf("Page Faults: %d\n", fault);
    return 0;
}
