
#include <iostream>
#include <sched.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>

int childFunc(void *hostname) { //Это функция, которая будет выполнена в дочернем процессе. 
    sethostname((char*)hostname, strlen((char*)hostname)); //Она принимает указатель на hostname, устанавливает новый hostname, используя sethostname, и возвращает
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Необходимо передать новое имя компьютера в качестве аргумента." << std::endl;
        return 1;
    }

    const int STACK_SIZE = 65536;
    void *child_stack = malloc(STACK_SIZE);
    char *new_hostname = argv[1];

    if (child_stack == nullptr) {
        std::cerr << "Ошибка при выделении памяти для стека дочернего процесса." << std::endl;
        return 1;
    }

    auto pid = clone(childFunc, (char*)child_stack + STACK_SIZE, CLONE_NEWUTS | SIGCHLD, new_hostname);
    if (pid == -1) {
        std::cerr << "Ошибка при создании дочернего процесса." << std::endl;
        free(child_stack);
        return 1;
    }

    waitpid(pid, NULL, 0);

    char parent_hostname[64];
    gethostname(parent_hostname, sizeof(parent_hostname));//Получает и выводит имя компьютера родительского процесса 

    std::cout << "Родительский процесс: Текущее имя компьютера: " << parent_hostname << std::endl;

    free(child_stack);
    return 0;
}

