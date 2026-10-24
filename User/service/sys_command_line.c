#include "main.h"
#include <stdbool.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include "sys_command_line.h"

typedef struct 
{
    uint8_t buff[MAX_LINE_LEN];
    uint8_t len;
} HANDLE_TYPE_S;

typedef struct 
{
    const char *pCmd;
    const char *pHelp;
    uint8_t (*pFun)(int argc,char *argv[]);
} COMMAND_S;

COMMAND_S   CLI_commands[MAX_COMMAND_NB];

typedef struct
{
    char cmd[HISTORY_MAX][MAX_LINE_LEN];
    uint8_t count;
    uint8_t latest;
    uint8_t show;
} HISTORY_S;
