#ifndef _STDLIB_STDIO
#define _STDLIB_STDIO

#define DESDE_EL_ORIGEN  0
#define DESDE_EL_PUNTERO 1
#define DESDE_EL_EXTREMO 2

#include <string.h>

typedef struct {} Archivo;
typedef unsigned long apos_t;
typedef struct { long _; long __; } fpos_t;

typedef int va_list;

extern int      eliminarArchivo(const char*)                                     __asm__ ("remove");
extern int      cambiarNombreDeArchivo(const char*, const char*)                 __asm__ ("rename");
extern Archivo* archivoTemporal(void)                                            __asm__ ("tmpfile");
extern char*    nombreTemporal(char*)                                            __asm__ ("tmpnam");

extern int      cerrarArchivo(Archivo*)                                          __asm__ ("fclose");
extern int      enjuagarArchivo(Archivo*)                                        __asm__ ("fflush");
extern Archivo* abrirArchivo(const char*, const char*)                           __asm__ ("fopen");
extern Archivo* reabrirArchivo(const char*, const char*, Archivo*)               __asm__ ("freopen");
extern void     ajustarRegulador(Archivo*, char*)                                __asm__ ("setbuf");
extern int      cambiarRegulador(Archivo*, char*, int, capacidad_t)              __asm__ ("setvbuf");

extern int      imprimirFormateada(const char*, ...)                             __asm__ ("printf");
extern int      escanearFormateada(const char*, ...)                             __asm__ ("scanf");
extern int      imprimirFormateadaArchivo(Archivo*, const char*, ...)            __asm__ ("fprintf");
extern int      escanearFormateadaArchivo(Archivo*, const char*, ...)            __asm__ ("fscanf");
extern int      imprimirFormateadaSarta(char*, const char*, ...)                 __asm__ ("sprintf");
extern int      escanearFormateadaSarta(char*, const char*, ...)                 __asm__ ("sscanf");
extern int      vimprimirFormateada(const char*, va_list)                        __asm__ ("vprintf");
extern int      vimprimirFormateadaArchivo(Archivo*, const char*, va_list)       __asm__ ("vfprintf");
extern int      vimprimirFormateadaSarta(char*, const char*, va_list)            __asm__ ("vsprintf");

extern int      sacarLetreArchivo(Archivo*)                                      __asm__ ("fgetc");
extern int      ponerLetreArchivo(int, Archivo*)                                 __asm__ ("fputc");
extern int      sacarLetre(void)                                                 __asm__ ("getchar");
extern int      ponerLetre(int)                                                  __asm__ ("putchar");

extern char*    sacarSartaArchivo(char*, int, Archivo*)                          __asm__ ("fgets");
extern int      ponerSartaArchivo(const char*, Archivo*)                         __asm__ ("fputs");
extern char*    sacarSarta(char*)                                                __asm__ ("gets");
extern int      ponerSarta(const char*)                                          __asm__ ("puts");

extern int      anularSacarLetreArchivo(int, Archivo*)                           __asm__ ("ungetc");

extern int      obtenerArchivoPosición(Archivo*, fpos_t*)                        __asm__ ("fgetpos");
extern int      reposicionarArchivo(Archivo*, long, int)                         __asm__ ("fseek");
extern long     informarArchivoPosición(Archivo*)                                __asm__ ("ftell");
extern int      cambiarArchivoPosición(Archivo*, const fpos_t*)                  __asm__ ("fsetpos");
extern void     rebobinarArchivo(Archivo*)                                       __asm__ ("rewind");

extern void     limpiarArchivoErrores(Archivo*)                                  __asm__ ("clearerr");

extern int      leerArchivo(void*, capacidad_t, capacidad_t, Archivo*)           __asm__ ("fread");
extern int      escribirArchivo(const void*, capacidad_t, capacidad_t, Archivo*) __asm__ ("fwrite");
extern int      finalDelArchivo(Archivo*)                                        __asm__ ("feof");
extern int      archivoErrores(Archivo*)                                         __asm__ ("ferror");

extern void     imprimirErrores(const char*)                                     __asm__ ("perror");

#endif
