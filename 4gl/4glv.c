#include <stdio.h>
/*float total = 0.0;
short count = 0;
short tax_percent = 6;

float add_with_tax(float f)
{
    float tax_rate = 1 + tax_percent / 100.0;
    total = total + (f * tax_rate);
    count = count + 1;
    return total;
}
int main()
{
    float val;
    printf("Цена блюда: ");
    while (scanf("%f", &val) == 1){
        printf("Итого на текущий момент: %.2f\n", add_with_tax(val));
        printf("Цена блюда: ");
    }
    printf("\nИтоговый счет: %.2f\n", total);
    printf("Количество блюд: %hi\n", count);
    return 0;
}*/
/*int main()
{
    catalog("Зубастик", "пиранья", 69, 4);
    label("Зубастик", "пиранья", 69, 4);
    return 0;
}*/
/*void encrypt(char *message)
{
    char c;
    while (*message){
       *message = *message ^ 31;
       message ++;
    }
}
int main()
{
    char msg[80];
    while(fgets(msg, 80, stdin)){
        encrypt(msg);
        printf("%s", msg);
    }
}*/
struct preferences {
    const char *food;
    float exercise_hours;
};
struct fish{
    const char *name;
    const char *species;
    int teeth;
    int age;
    struct preferences care;
};
void catalog(struct fish f)
{
    printf("%s - это %s с %i зубами. Ему %i года\n", f.name, f.species, f.teeth, f.age);
}
void label(struct fish f)
{
    printf("Кличка:%s\nРазновидность:%s\n%i зуба(ов), %i года(лет)\n", f.name, f.species, f.teeth, f.age);
    printf("Давать %.2f кг %s и распереть %s на протяжении %.2f часов\n", f.food_weight_kg, f.food_type, f.activity, f.duration_hours);
}
int main()
{
    struct fish snappy = {"Зубастик", "пиранья", 69, 4};
    catalog(snappy);
    label(snappy);
    return 0;
}