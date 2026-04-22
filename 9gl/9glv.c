/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* now()
{
    time_t t;
    time(&t);
    return asctime(localtime(&t));
}
int main() {
    char comment[80];
    char cmd[120];
    fgets(comment, 80, stdin);
    sprintf(cmd, 
    "echo '%s %s' >> reports.log",
    comment, now());
    system(cmd);
    return 0;
}
*/

/*#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *my_env[] = {"JUICE=персик и яблоко", NULL};

int main(int argc, char *argv[]) {
    int res;
    res = execl("4gl", "4glava", "4", NULL, my_env);
    printf("execle вернул %d\n", res);
    puts("Старик, код из данной программы");
    printf("Обедов: %s\n", argv[1]);
    printf("Сок: %s\n", getenv("JUICE"));
    return 0;
}
*/