#include <stdio.h>

int main() {
    int n, f, page[20], frame[10];
    int i, j, k, pos, fault = 0;

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
            if(i < f) {
                frame[i] = page[i];
            } else {
                int farthest = -1;
                pos = -1;

                for(j = 0; j < f; j++) {
                    int next = -1;
                    for(k = i + 1; k < n; k++) {
                        if(frame[j] == page[k]) {
                            next = k;
                            break;
                        }
                    }

                    if(next == -1) {
                        pos = j;
                        break;
                    }

                    if(next > farthest) {
                        farthest = next;
                        pos = j;
                    }
                }
                frame[pos] = page[i];
            }
            fault++;
        }
    }

    printf("Page Faults: %d\n", fault);
    return 0;
}
