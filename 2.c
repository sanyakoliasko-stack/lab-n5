#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main() {
    int n, task_choice, fill_choice, i;
    printf("Оберіть задачу для виконання:\n");
    printf("1 - Обчислити середнє геометричне додатніх елементів\n");
    printf("2 - Знайти мін. за модулем та добуток між нулями\n");
    printf("Ваш вибір: ");
    scanf("%d", &task_choice);
    printf("\nВведіть кількість елементів масиву (n): ");
    scanf("%d", &n);
    int a[n];
    printf("\nОберіть спосіб заповнення масиву:\n");
    printf("1 - З клавіатури\n");
    printf("2 - Випадковими числами [-100; 100]\n");
    printf("Ваш вибір: ");
    scanf("%d", &fill_choice);
    switch (fill_choice) {
        case 1:
            printf("Введіть %d цілих чисел:\n", n);
            for (i = 0; i < n; i++) {
                printf("a[%d] = ", i);
                scanf("%d", &a[i]);
            }
            break;
        case 2:
            srand(time(NULL));
            printf("Згенерований масив: ");
            for (i = 0; i < n; i++) {
                a[i] = rand() % 201 - 100;
                printf("%d ", a[i]);
            }
            printf("\n");
            break;
        default:
            printf("Невірний вибір способу заповнення!\n");
            return 1;
    }
    switch (task_choice) {
        case 1: { 
            double product_geom = 1.0;
            int count_pos = 0;
            for (i = 0; i < n; i++) {
                if (a[i] > 0) {
                    product_geom *= a[i];
                    count_pos++;
                }
            }
            if (count_pos > 0) {
                double res = pow(product_geom, 1.0 / count_pos);
                printf("\nРезультат: Середнє геометричне %d додатніх чисел = %.4f\n", count_pos, res);
            } else {
                printf("\nДодатніх чисел не знайдено.\n");
            }
            break;
        }

        case 2: {
            int minAbs = abs(a[0]);
            int minVal = a[0];
            for (i = 1; i < n; i++) {
                if (abs(a[i]) < minAbs) {
                    minAbs = abs(a[i]);
                    minVal = a[i];
                }
            }
            printf("\n1) Мінімальний за модулем елемент: %d\n", minVal);
            int firstZ = -1, lastZ = -1;
            for (i = 0; i < n; i++) {
                if (a[i] == 0) {
                    if (firstZ == -1) firstZ = i;
                    lastZ = i;
                }
            }
            if (firstZ != -1 && lastZ != -1 && firstZ != lastZ) {
                long long prod = 1;
                for (int j = firstZ + 1; j < lastZ; j++) {
                    prod *= a[j];
                }
                printf("2) Добуток елементів між першим і останнім нулями: %lld\n", prod);
            } else {
                printf("2) Неможливо обчислити добуток (потрібно мінімум два нулі).\n");
            }
            break;
        }
default:
            printf("Такої задачі не існує.\n");
    }
    return 0;
}