#include <stdio.h>
#include <stdlib.h> // Для rand() та srand()
#include <time.h>   // Для time()
#include <math.h>   // Для abs() - модуль числа

int main() {
    int n, choice;

    printf("Введіть розмір масиву n: ");
    scanf("%d", &n);

    int a[n];

    printf("\nВиберіть спосіб заповнення масиву:\n");
    printf("1. Введення з клавіатури\n");
    printf("2. Генератор випадкових чисел [-100; 100]\n");
    printf("Ваш вибір: ");
    scanf("%d", &choice);

    // --- ЗАПОВНЕННЯ МАСИВУ ---
    if (choice == 1) {
        // Спосіб А: Введення з клавіатури
        for (int i = 0; i < n; i++) {
            printf("a[%d] = ", i);
            scanf("%d", &a[i]);
        }
    } else {
        // Спосіб Б: Випадкові числа
        srand(time(NULL)); // Ініціалізація генератора часом
        for (int i = 0; i < n; i++) {
            // Формула для діапазону [min; max]: rand() % (max - min + 1) + min
            a[i] = rand() % 201 - 100; 
            printf("%d ", a[i]);
        }
        printf("\n");
    }

    // --- 1) ПОШУК МІНІМАЛЬНОГО ЗА МОДУЛЕМ ---
    int min_mod = a[0]; // Припускаємо, що перший елемент мінімальний
    for (int i = 1; i < n; i++) {
        // Якщо модуль поточного елемента менший за модуль мінімального
        if (abs(a[i]) < abs(min_mod)) {
            min_mod = a[i]; // Запам'ятовуємо нове мінімальне число
        }
    }
    printf("\n1) Мінімальний за модулем елемент: %d\n", min_mod);

    // --- 2) ДОБУТОК МІЖ ПЕРШИМ ТА ОСТАННІМ НУЛЯМИ ---
    int first_zero = -1; // Індекс першого нуля
    int last_zero = -1;  // Індекс останнього нуля

    // Шукаємо індекси нулів
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (first_zero == -1) {
                first_zero = i; // Знайшли перший нуль
            }
            last_zero = i;      // Кожен наступний знайдений нуль стає останнім
        }
    }

    // Перевірка, чи знайдено хоча б два нулі
    if (first_zero != -1 && last_zero != -1 && first_zero != last_zero) {
        long long product = 1; // Використовуємо long long для великих добутків
        
        // Множимо елементи, що розташовані МІЖ ними
        for (int i = first_zero + 1; i < last_zero; i++) {
            product *= a[i];
        }
        
        // Якщо між нулями нічого немає (вони стоять поруч), добуток буде 1 (або можна вивести 0)
        if (last_zero - first_zero == 1) product = 0;

        printf("2) Добуток елементів між нулями (індекси %d та %d): %lld\n", first_zero, last_zero, product);
    } else {
        printf("2) Неможливо обчислити добуток: потрібно мінімум два нульових елементи.\n");
    }

    return 0;
}