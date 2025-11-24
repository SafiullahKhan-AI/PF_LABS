#include <stdio.h>

struct Box {
    int length;
    int width;
    int height;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Box b;

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &b.length, &b.width, &b.height);

        if (b.height < 41) {
            int volume = b.length * b.width * b.height;
            printf("%d\n", volume);
        }
    }

    return 0;
}
