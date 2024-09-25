#include <stdio.h>

void fibonacci(int n, int *t1, int *t2) {
    int nextTerm;

    for (int i = 1; i <= n; ++i) {
        printf("%d, ", *t1);
        nextTerm = *t1 + *t2;
        *t1 = *t2;
        *t2 = nextTerm;
    }
}

int main() {
    int n, t1 = 0, t2 = 1;

    printf("Ingrese el numero de terminos: ");
    scanf("%d", &n);

    fibonacci(n, &t1, &t2);

    return 0;
}