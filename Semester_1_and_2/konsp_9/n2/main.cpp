#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        std::cerr << "Error creating child process" << std::endl;
        return 1;
    } else if (pid == 0) {
        execlp("expr", "expr", "2", "+", "2", "*", "2", NULL);
        std::cerr << "Error executing command" << std::endl;
        return 1;
    } else {
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            std::clog << "Child process finished with exit code: " << WEXITSTATUS(status) << std::endl;
        } else {
            std::cerr << "Child process terminated abnormally" << std::endl;
        }
    }

    return 0;
}
