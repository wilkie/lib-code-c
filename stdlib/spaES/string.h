#ifndef _STDLIB_STRING
#define _STDLIB_STRING

#define NULO (void*)(0)

typedef unsigned long capacidad_t;

extern void*       copiarMemoria           (void*, const void*, capacidad_t)       __asm__ ("memcpy");
extern void*       moverMemoria            (void*, const void*, capacidad_t)       __asm__ ("memmove");
extern char*       copiarSarta             (char*, const char*)                    __asm__ ("strcpy");
extern char*       copiarSartaSeguro       (char*, const char*, capacidad_t)       __asm__ ("strncpy");

extern char*       concatenarSarta         (char*, const char*)                    __asm__ ("strcat");
extern char*       concatenarSartaSeguro   (char*, const char*)                    __asm__ ("strncat");

extern int         compararMemoria         (const void*, const void*, capacidad_t) __asm__ ("memcmp");
extern int         compararSarta           (const char*, const char*)              __asm__ ("strcmp");
extern int         compararSartaCultura    (const char*, const char*)              __asm__ ("strcoll");
extern int         compararSartaSeguro     (const char*, const char*, capacidad_t) __asm__ ("strncmp");
extern capacidad_t transformarCulturaSarta (char*,       const char*, capacidad_t) __asm__ ("strxfrm");

extern void*       buscarByteMemoria       (const void*, int, capacidad_t)         __asm__ ("memchr");
extern char*       buscarByteSarta         (const char*, int)                      __asm__ ("strchr");
extern capacidad_t escanearSartaPosición   (const char*, const char*)              __asm__ ("strcspn");
extern char*       escanearSarta           (const char*, const char*)              __asm__ ("strpbrk");
extern char*       buscarÚltimaByteSarta   (const char*, int)                      __asm__ ("strrchr");
extern capacidad_t escanearSartaLongitud   (const char*, const char*)              __asm__ ("strspn");
extern char*       buscarSubsarta          (const char*, const char*)              __asm__ ("strstr");
extern char*       dividirseSarta          (char*, const char*)                    __asm__ ("strtok");

extern void*       llenarMemoria           (void*, int, capacidad_t)               __asm__ ("memset");
extern char*       obtenerSartaDeError     (int)                                   __asm__ ("strerror");
extern capacidad_t longitudDeSarta         (const char*)                           __asm__ ("strlen");

#endif
