#include <string.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
  imprimirFormateada("Hola\n\n");

  Archivo* archivo    = abrirArchivo("todo.txt", "r+");
  Archivo* producción = NULO;

  if (archivo == NULO) {
    imprimirFormateada("Archivo no encontrado... creando!\n\n");

    archivo = abrirArchivo("todo.txt", "w+");
  }

  int índiceParaEliminar = -2;
  if (argc > 2) {
    if (compararSarta(argv[1], "--poner") == 0) {
      imprimirFormateada("Añadiendo \"%s\" a la lista.\n\n", argv[2]);
      reposicionarArchivo(archivo, 0, DESDE_EL_EXTREMO);
      escribirArchivo(argv[2], longitudDeSarta(argv[2]), 1, archivo);
      escribirArchivo("\n", 1, 1, archivo);
      reposicionarArchivo(archivo, 0, DESDE_EL_ORIGEN);
    }
    else if (compararSarta(argv[1], "--eliminar") == 0) {
      escanearFormateadaSarta(argv[2], "%d", &índiceParaEliminar);
      producción = abrirArchivo(".todo.txt", "w+");
    }
  }

  char línea[1024];

  int númLíneas = 0;

  imprimirFormateada("Cosas que hacer:\n");
  while(!finalDelArchivo(archivo)) {
    copiarSarta(línea, "");
    sacarSartaArchivo(línea, 1024, archivo);

    if (longitudDeSarta(línea) > 1) {
      if (índiceParaEliminar == númLíneas) {
        imprimirFormateada(" \xE2\x9C\x93: %s", línea);
        índiceParaEliminar = -1;
      }
      else {
        if (índiceParaEliminar > -2) {
          escribirArchivo(línea, longitudDeSarta(línea), 1, producción);
        }

        imprimirFormateada("%2d: %s", númLíneas, línea);
        númLíneas++;
      }
    }
  }

  if (númLíneas == 0) {
    imprimirFormateada("¡nada!\n");
  }
  else {
    imprimirFormateada("\nTodavía hay %d cosa%s que hacer. :(\n",
                       númLíneas,
                       (númLíneas == 1) ? "" : "s");
  }

  cerrarArchivo(archivo);
  if (producción != NULO) {
    cerrarArchivo(producción);

    cambiarNombreDeArchivo(".todo.txt", "todo.txt");

    producción = NULO;
    return 1;
  }

  return 0;
}
