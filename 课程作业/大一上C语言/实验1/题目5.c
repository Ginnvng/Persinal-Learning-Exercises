#include<stdio.h>
#include<math.h>
int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a < 1 || a > 100 || b < 1 || b > 100 || c < 1 || c > 100) {
        printf("Data error\n");
        return 0;
    }
    if (a * a + b * b == c *c ) {
        printf("%d %d %d", a, b, c);
    }
    else if (a * a + c * c == b * b) {
        printf("%d %d %d", a, c, b);
    }
    else if (b * b + c * c == a * a) {
        printf("%d %d %d", b, c, a);
    }
    else {
        printf("No\n");
    }

    return 0;
}

