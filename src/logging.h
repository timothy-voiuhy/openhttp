
#ifndef __LOGGING
#define __LOGGING

typedef struct {
    char *filename;
    int file_fd;
    char *format;
}Logger;

int logInfo(Logger *logger, char *mesg);

int logError(Logger *logger, char *mesg);

int logWarn(Logger logger, char *mesg);

int logCritical(Logger logger, char *mesg);

Logger CreateLogger();

int writeLogFile();

void closeLogger();

#endif