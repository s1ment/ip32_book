#include <stdio.h>
#include <string.h>

/*int NUM_ADS = 7;
char *ADS[] = {
    "Уильям: одинокий мужчина, афроамериканец, с хорошим чувством юмора, любит спорт, телевизор, перекусить",
    "Мэттью: одинокий мужчина, европеец, некурящий, любит живопись, кино, театр",
    "Луис: одинокий мужчина, латиноамериканец, непьющий, любит книги, театр, живопись",
    "Майк: разведенный мужчина, европеец, любит грузовики, спорт и Джастина Бибера",
    "Питер: одинокий мужчина, азиат, любит шахматы, тренироваться в зале и живопись",
    "Джош: одинокий мужчина, еврей, любит спорт, кино и театр",
    "Джед: разведенный мужчина, афроамериканец, любит театр, книги и перекусить"
};

void find()
{
    int i;
    puts("Search results:");
    puts("---");
    for (i = 0; i < NUM_ADS; i++) {
        if (strstr(ADS[i], "спорт") && !strstr(ADS[i], "Бибер")) {
            printf("%s\n", ADS[i]);
        }
    }
    puts("---");
}

int main() {
    find();
    return 0;
}*/

/*int NUM_ADS = 7;
char *ADS[] = {
    "Уильям: одинокий мужчина, афроамериканец, с хорошим чувством юмора, любит спорт, телевизор, перекусить",
    "Мэттью: одинокий мужчина, европеец, некурящий, любит живопись, кино, театр",
    "Луис: одинокий мужчина, латиноамериканец, непьющий, любит книги, театр, живопись",
    "Майк: разведенный мужчина, европеец, любит грузовики, спорт и Джастина Бибера",
    "Питер: одинокий мужчина, азиат, любит шахматы, тренироваться в зале и живопись",
    "Джош: одинокий мужчина, еврей, любит спорт, кино и театр",
    "Джед: разведенный мужчина, афроамериканец, любит театр, книги и перекусить"
};

int sports_no_bieber(char *s) {
    return strstr(s, "спорт") && !strstr(s, "Бибер");
}

int sports_or_workout(char *s) {
    return strstr(s, "спорт") || strstr(s, "тренироваться в зале");
}

int ns_theater(char *s) {
    return strstr(s, "некурящий") && strstr(s, "театр");
}

int arts_theater_or_dining(char *s) {
    return strstr(s, "живопись") || strstr(s, "театр") || strstr(s, "перекусить");
}

void find(int (*match)(char *)) {
    int i;
    puts("Результаты поиска:");
    puts("---");
    for (i = 0; i < NUM_ADS; i++) {
        if (match(ADS[i])) {
            printf("%s\n", ADS[i]);
        }
    }
    puts("---");
}

int main() {
    find(sports_no_bieber);
    find(sports_or_workout);
    find(ns_theater);
    find(arts_theater_or_dining);
    return 0;
}*/
/*#include <stdlib.h>

int compare_scores_desc(const void* a, const void* b) {
    int ia = *(int*)a;
    int ib = *(int*)b;
    return ib - ia;
}

int compare_names(const void* a, const void* b) {
    char** sa = (char**)a;
    char** sb = (char**)b;
    return strcmp(*sa, *sb);
}

int compare_names_desc(const void* a, const void* b) {
    return compare_names(b, a);
}

int main() {
    int scores[] = {543, 323, 32, 554, 11, 3, 112};
    int i;

    qsort(scores, 7, sizeof(int), compare_scores_desc);
    puts("Это упорядоченные оценки:");
    for (i = 0; i < 7; i++) {
        printf("Оценка = %i\n", scores[i]);
    }

    char* names[] = {"Карен", "Марк", "Бретт", "Молли"};
    qsort(names, 4, sizeof(char*), compare_names);
    puts("Это упорядоченные имена:");
    for (i = 0; i < 4; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}*/
/*enum response_type { DUMP, SECOND_CHANCE, MARRIAGE };

typedef struct {
    char *name;
    enum response_type type;
} response;

void dump(response r) {
    printf("Дорогой %s,\n", r.name);
    puts("К сожалению, Ваш недавний партнер по свиданию связался с нами,");
    puts("чтобы сообщить, что Вы с ним больше не увидитесь.\n");
}

void second_chance(response r) {
    printf("Дорогой %s,\n", r.name);
    puts("Хорошие новости: Ваш недавний партнер по свиданию попросил нас");
    puts("организовать еще одну встречу. Пожалуйста, перезвоните как можно скорее.\n");
}

void marriage(response r) {
    printf("Дорогой %s,\n", r.name);
    puts("Поздравляем! Ваш недавний партнер по свиданию");
    puts("связался с нами с предложением о браке.\n");
}

int main() {
    response r[] = {
        {"Майк", DUMP},
        {"Луис", SECOND_CHANCE},
        {"Мэттью", SECOND_CHANCE},
        {"Уильям", MARRIAGE}
    };

    void (*replies[])(response) = { dump, second_chance, marriage };

    for (int i = 0; i < 4; i++) {
        (replies[r[i].type])(r[i]);
    }

    return 0;
}*/
#include <stdarg.h>

enum drink {
    MUDSLIDE,
    FUZZY_NAVEL,
    MONKEY_GLAND,
    ZOMBIE
};

double price(enum drink d) {
    switch (d) {
        case MUDSLIDE:     return 6.79;
        case FUZZY_NAVEL:  return 5.31;
        case MONKEY_GLAND: return 4.82;
        case ZOMBIE:       return 5.89;
    }
    return 0.0;
}

double total(int args, ...) {
    double total = 0.0;
    va_list ap;
    va_start(ap, args);
    
    for (int i = 0; i < args; i++) {
        enum drink d = va_arg(ap, enum drink);
        total = total + price(d);
    }
    
    va_end(ap);
    return total;
}

int main() {
    printf("Цена равняется %.2f\n", total(2, MONKEY_GLAND, MUDSLIDE));
    printf("Цена равняется %.2f\n", total(3, MONKEY_GLAND, MUDSLIDE, FUZZY_NAVEL));
    printf("Цена равняется %.2f\n", total(1, ZOMBIE));
    return 0;
}