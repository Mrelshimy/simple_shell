#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <limits.h>
#include <dirent.h>

#define prompt "Simple Shell $ "
#define error_mess "%s: not found\n"
#define exit_comm "exit"

extern char **environ;

void err_format(char *obj_file, char *comm, int index);
char *path_find(char *comm);
int exec_comm(char **comm, char **argv, int index);
char *get_ipcomm(void);
void free_arr(char **arr);
void check_bin(char *comm);
char **token_gen(char *inbuffer);
char *_itoa(int index);
void str_rev(char *input, int l);
void exec_bin(char **comm, char **argv, int *ret,  int index);
int bin_fn(char *comm);
void exit_fn(char **comm, char **argv, int *ret, int index);
void env_fn(char **comm);
int pos_num(char *buff);
void cd_fn(char **comm, char **argv, int *ret,  int index);
void cd_err_format(char *argv, char *comm, int index);

#endif

