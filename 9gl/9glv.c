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
/*#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h> 

int main() {
    if (execl("/sbin/ip", "ip", NULL) == -1)
        if (execlp("ipconfig", "ipconfig", NULL) == -1) {
            fprintf(stderr, "Не удалось запустить ipconfig: %s", strerror(errno));
            return 1;
        }
    return 0;
}\
*/

/*#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h> 

int main(int argc, char *argv[]) {
    char *my_env[] = {"FOOD=кофе", NULL};
    if (execle("./coffee", "./coffee", "пончики", NULL, my_env) == -1) {
        fprintf(stderr, "Не могу создать заказ: %s\n", strerror(errno));
        return 1;
    }
    return 0;
}
*/
/*#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h> 

int main(int argc, char *argv[]) {
    char *feeds[] = {"http://feeds.bbci.co.uk/news/rss.xml", 
                "http://feeds.reuters.com/reuters/topNews",
                "https://www.theguardian.com/world/rss"};
    int times = 3;
    char *phrase = argv[1];
    for(int i = 0; i < times; i++) {
        char var[255];
        sprintf(var, "RSS_FEED=%s", feeds[i]);
        char *vars[] = {var, NULL};
        pid_t pid = fork();
        if (pid == -1) {
            fprintf(stderr, "Не могу клонировать процесс: %s\n", strerror(errno));
            return 1;
        }
        if (!pid) {
            if(execle("/usr/bin/python3", "/usr/bin/python3", 
                "./rssgossip.py", phrase, NULL, vars) == -1) {
            fprintf(stderr, "Не могу запустить скрипт: %s\n", strerror(errno));
            return 1;
            }
        }
    }
    return 0;
}
*/