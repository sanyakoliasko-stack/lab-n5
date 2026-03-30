#include <stdio.h>
#include <math.h>
int main() {
    int n, i;
    int count = 0;
    double product = 1.0; 
    printf("Введіть кількість елементів масиву (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Помилка: n має бути додатнім числом.\n");
        return 1;
    }
    int a[n];
    printf("Введіть %d цілих чисел:\n", n);
    for (i = 0; i < n; i++) {
        printf("a[%d] = ", i + 1);
        scanf("%d", &a[i]);
        if (a[i] > 0) {
            product *= a[i];
            count++;
        }
    }
    if (count > 0) {
        double geometricMean = pow(product, 1.0 / count);
        printf("\nКількість додатніх елементів: %d", count);
        printf("\nСереднє геометричне: %.4f\n", geometricMean);
    } else {
        printf("\nУ масиві немає додатніх елементів. Обчислення неможливе.\n");
    }
    return 0;
}