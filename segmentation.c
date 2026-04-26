#include <stdio.h>

int main() {
    int n, base[20], limit[20], seg, offset;

    printf("Enter number of segments: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter base and limit for segment %d: ", i);
        scanf("%d%d", &base[i], &limit[i]);
    }

    printf("Enter segment number and offset: ");
    scanf("%d%d", &seg, &offset);

    if(seg >= n || offset >= limit[seg])
        printf("Invalid address\n");
    else
        printf("Physical Address: %d\n", base[seg] + offset);

    return 0;
}
