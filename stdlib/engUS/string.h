#ifndef _STDLIB_STRING
#define _STDLIB_STRING

#define NULL (void*)(0)

typedef unsigned long size_t;

extern void*  copyMemory              (void*, const void*, size_t)       __asm__ ("memcpy");
extern void*  moveMemory              (void*, const void*, size_t)       __asm__ ("memmove");
extern char*  copyString              (char*, const char*)               __asm__ ("strcpy");
extern char*  copyStringSafely        (char*, const char*, size_t)       __asm__ ("strncpy");

extern char*  concatenateString       (char*, const char*)               __asm__ ("strcat");
extern char*  concatenateStringSafely (char*, const char*)               __asm__ ("strncat");

extern int    compareMemory           (const void*, const void*, size_t) __asm__ ("memcmp");
extern int    compareString           (const char*, const char*)         __asm__ ("strcmp");
extern int    compareStringCulturally (const char*, const char*)         __asm__ ("strcoll");
extern int    compareStringSafely     (const char*, const char*, size_t) __asm__ ("strncmp");
extern size_t transformCulturalString (char*,       const char*, size_t) __asm__ ("strxfrm");

extern void*  findByteMemory          (const void*, int, size_t)         __asm__ ("memchr");
extern char*  findByteString          (const char*, int)                 __asm__ ("strchr");
extern size_t scanStringPosition      (const char*, const char*)         __asm__ ("strcspn");
extern char*  scanString              (const char*, const char*)         __asm__ ("strpbrk");
extern char*  findLastByteString      (const char*, int)                 __asm__ ("strrchr");
extern size_t scanStringLength        (const char*, const char*)         __asm__ ("strspn");
extern char*  findSubstring           (const char*, const char*)         __asm__ ("strstr");
extern char*  splitString             (char*, const char*)               __asm__ ("strtok");

extern void*  fillMemory              (void*, int, size_t)               __asm__ ("memset");
extern char*  getErrorString          (int)                              __asm__ ("strerror");
extern size_t stringLength            (const char*)                      __asm__ ("strlen");

#endif
