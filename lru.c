#include <stdio.h>

int main() {
    int n, f, page[20], frame[10], time[10];
    int i, j, k, pos, fault = 0, count = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &page[i]);

    for(i = 0; i < f; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    for(i = 0; i < n; i++) {
        int found = 0;
        for(j = 0; j < f; j++) {
            if(frame[j] == page[i]) {
                count++;
                time[j] = count;
                found = 1;
                break;
            }
        }

        if(!found) {
            if(i < f) {
                frame[i] = page[i];
                count++;
                time[i] = count;
            } else {
                int min = time[0];
                pos = 0;
                for(k = 1; k < f; k++) {
                    if(time[k] < min) {
                        min = time[k];
                        pos = k;
                    }
                }
                frame[pos] = page[i];
                count++;
                time[pos] = count;
            }
            fault++;
        }
    }

    printf("Page Faults: %d\n", fault);
    return 0;
}
