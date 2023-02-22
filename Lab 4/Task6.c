#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_STUDENTS 100

struct student {
    char roll_no[10];
    int marks;
    char grade;
};

void update_grade(struct student* s) {
    if (s->marks >= 80) {
        s->grade = 'A';
    } else if (s->marks >= 70) {
        s->grade = 'B';
    } else if (s->marks >= 60) {
        s->grade = 'C';
    } else if (s->marks >= 50) {
        s->grade = 'D';
    } else {
        s->grade = 'F';
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s student_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    struct student students[MAX_STUDENTS];
    int num_students = 0;
    char line[100];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char* token = strtok(line, ",");
        strcpy(students[num_students].roll_no, token);
        token = strtok(NULL, ",");
        students[num_students].marks = atoi(token);
        update_grade(&students[num_students]);
        num_students++;
    }
    fclose(fp);

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        char* args[] = { "mkdir", "-p", "Resultpath", NULL };
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        int status;
        wait(&status);
        if (!WIFEXITED(status) || WEXITSTATUS(status) != 0) {
            fprintf(stderr, "Child process failed to create directory/file structure.\n");
            exit(EXIT_FAILURE);
        }
    }
    fp = fopen("Resultpath/LabResult.txt", "w");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < num_students; i++) {
        fprintf(fp, "%s,%d,%c\n", students[i].roll_no, students[i].marks, students[i].grade);
    }
    fclose(fp);

    return 0;
}
