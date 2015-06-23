#ifndef _STDLIB_STDIO
#define _STDLIB_STDIO

#define FROM_THE_START 0
#define FROM_CURRENT   1
#define FROM_THE_END   2

#include <string.h>

typedef struct {} File;
typedef struct { long _; long __; } fpos_t;

typedef int va_list;

extern int   removeFile(const char*)                            __asm__ ("remove");
extern int   renameFile(const char*, const char*)               __asm__ ("rename");
extern File* temporaryFile(void)                                __asm__ ("tmpfile");
extern char* temporaryName(char*)                               __asm__ ("tmpnam");

extern int   closeFile(File*)                                   __asm__ ("fclose");
extern int   flushFile(File*)                                   __asm__ ("fflush");
extern File* openFile(const char*, const char*)                 __asm__ ("fopen");
extern File* reopenFile(const char*, const char*, File*)        __asm__ ("freopen");
extern void  setBuffer(File*, char*)                            __asm__ ("setbuf");
extern int   changeBuffer(File*, char*, int, size_t)            __asm__ ("setvbuf");

extern int   printFormatted(const char*, ...)                   __asm__ ("printf");
extern int   scanFormatted(const char*, ...)                    __asm__ ("scanf");
extern int   printFormattedFile(File*, const char*, ...)        __asm__ ("fprintf");
extern int   scanFormattedFile(File*, const char*, ...)         __asm__ ("fscanf");
extern int   printFormattedString(char*, const char*, ...)      __asm__ ("sprintf");
extern int   scanFormattedString(char*, const char*, ...)       __asm__ ("sscanf");
extern int   vprintFormatted(const char*, va_list)              __asm__ ("vprintf");
extern int   vprintFormattedFile(File*, const char*, va_list)   __asm__ ("vfprintf");
extern int   vprintFormattedString(char*, const char*, va_list) __asm__ ("vsprintf");

extern int   getCharacterFile(File*)                            __asm__ ("fgetc");
extern int   putCharacterFile(int, File*)                       __asm__ ("fputc");
extern int   getCharacter(void)                                 __asm__ ("getchar");
extern int   putCharacter(int)                                  __asm__ ("putchar");

extern char* getStringFile(char*, int, File*)                   __asm__ ("fgets");
extern int   putStringFile(const char*, File*)                  __asm__ ("fputs");
extern char* getString(char*)                                   __asm__ ("gets");
extern int   putString(const char*)                             __asm__ ("puts");

extern int   ungetCharacterFile(int, File*)                     __asm__ ("ungetc");

extern int   getFilePosition(File*, fpos_t*)                    __asm__ ("fgetpos");
extern int   repositionFile(File*, long, int)                   __asm__ ("fseek");
extern long  readFilePosition(File*)                            __asm__ ("ftell");
extern int   setFilePosition(File*, const fpos_t*)              __asm__ ("fsetpos");
extern void  rewindFile(File*)                                  __asm__ ("rewind");

extern void  cleanFileErrors(File*)                             __asm__ ("clearerr");

extern int   readFile(void*, size_t, size_t, File*)             __asm__ ("fread");
extern int   writeFile(const void*, size_t, size_t, File*)      __asm__ ("fwrite");
extern int   endOfFile(File*)                                   __asm__ ("feof");
extern int   fileErrors(File*)                                  __asm__ ("ferror");

extern void  printError(const char*)                            __asm__ ("perror");

#endif
