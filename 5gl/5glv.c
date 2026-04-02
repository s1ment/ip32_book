#include <stdio.h>

/*typedef struct {
    const char *name;
    const char *species;
    int age;
} turtle;

void happy_birthday(turtle *t)
{
    (*t).age = (*t).age + 1;
    printf("С днем рождения, %s! Теперь тебе %i лет!\n",
    (*t).name, (*t).age);
}

int main()
{
    turtle myrtle = {"Тортилла", "Кожистая черепаха", 99};
    happy_birthday(&myrtle);
    printf("%s прожила %i лет\n", myrtle.name, myrtle.age);
    return 0;
}*/

/*typedef struct {
    const char *description;
    float value;
} swag;

typedef struct {
    swag *swag;
    const char *sequence;
} combination;

typedef struct {
    combination numbers;
    const char *make;
} safe;

void method1(swag* t) {
    printf("Ценность: %s; Его стоимость: %.1f\n", (*t).description, (*t).value);
}

void method2(combination* t) {
    printf("Комбинация: %s; Ее ценность: %s; Стоимость: %.1f\n", (*t).sequence, t->swag->description, t->swag->value);
}

void method3(safe* t) {
    printf("Модель сейфа: %s; Комбинация: %s; Ценность: %s; Стоимость: %.1f\n", (*t).make, (*t).numbers.sequence, t->numbers.swag->description, t->numbers.swag->value);
}

int main(){
swag gold = {"ЗОЛОТО!", 1000000.0};
combination numbers = {&gold, "6502"};
safe s = {numbers, "RAMACON250"};
method1(&gold);
method2(&numbers);
method3(&s);
}*/

/*typedef union {
    float lemon;
    int lime_pieces;
} lemon_lime;

typedef struct {
    float tequila;
    float cointreau
    lemon_lime citrus;
} margarita;

int main(){
    margarita m1 = (2.0, 1.0, {2.0});
    printf("Рецепт 1\n");
    printf("%2.1f порции текилы\n%2.1f порции куантро\n%2.1f порции сока\n\n", m1.tequila, m1.cointreau, m1.citrus.lemon);

    margarita m2 = (2.0, 1.0, {0.5});
    printf("Рецепт 2\n");
    printf("%2.1f порции текилы\n%2.1f порции куантро\n%2.1f порции сока\n\n", m2.tequila, m2.cointreau, m2.citrus.lemon);

    margarita m3 = (2.0, 1.0, {.lime_pieces = 1});
    printf("Рецепт 3\n");
    printf("%2.1f порции текилы\n%2.1f порции куантро\n%i порции сока\n", m3.tequila, m3.cointreau, m3.lime_pieces);

    return 0;
}*/

#include <stdio.h>

typedef enum {
    COUNT, POUNDS, PINTS
} unit_of_measure;

typedef union {
    short count;
    float weight;
    float volume;
} quantity;

typedef struct {
    const char *name;
    const char *country;
    quantity amount;
    unit_of_measure units;
} fruit_order;

void display(fruit_order order) {
    printf("Этот заказ содержит ");
    if (order.units == PINTS) {
        printf("%.2f пинт %s\n", order.amount.volume, order.name);
    } else if (order.units == POUNDS) {
        printf("%.2f пинт %s\n", order.amount.volume, order.name);
    } else {
        printf("%d штук %s\n", order.amount.count, order.name);
    }
}

int main() {
    fruit_order apples = {"яблок", "Англия", .amount.count=144, COUNT};
    fruit_order strawberries = {"клубники", "Испания", .amount.weight=17.6, POUNDS};
    fruit_order oj = {"апельсинового сока", "США", .amount.volume=10.5, PINTS};

    display(apples);
    display(strawberries);
    display(oj);

    return 0;
}
