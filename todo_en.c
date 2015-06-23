#include <string.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
  printFormatted("Hello\n\n");

  File* file       = openFile("todo.txt", "r+");
  File* production = NULL;

  if (file == NULL) {
    printFormatted("File not found. Creating!\n\n");

    file = openFile("todo.txt", "w+");
  }

  int indexToRemove = -2;
  if (argc > 2) {
    if (compareString(argv[1], "--add") == 0) {
      printFormatted("Adding \"%s\" to the list.\n\n", argv[2]);
      repositionFile(file, 0, FROM_THE_END);
      writeFile(argv[2], stringLength(argv[2]), 1, file);
      writeFile("\n", 1, 1, file);
      repositionFile(file, 0, FROM_THE_START);
    }
    else if (compareString(argv[1], "--remove") == 0) {
      scanFormattedString(argv[2], "%d", &indexToRemove);
      production = openFile(".todo.txt", "w+");
    }
  }

  char line[1024];

  int numLines = 0;

  printFormatted("Things to do:\n");
  while(!endOfFile(file)) {
    copyString(line, "");
    getStringFile(line, 1024, file);

    if (stringLength(line) > 1) {
      if (indexToRemove == numLines) {
        printFormatted(" \xE2\x9C\x93: %s", line);
        indexToRemove = -1;
      }
      else {
        if (indexToRemove > -2) {
          writeFile(line, stringLength(line), 1, production);
        }

        printFormatted("%2d: %s", numLines, line);
        numLines++;
      }
    }
  }

  if (numLines == 0) {
    printFormatted("Nothing to do!\n");
  }
  else {
    printFormatted("\nStill have %d thing%s to do. :(\n",
                   numLines,
                   (numLines == 1) ? "" : "s");
  }

  closeFile(file);
  if (production != NULL) {
    closeFile(production);

    renameFile(".todo.txt", "todo.txt");

    production = NULL;
    return 1;
  }

  return 0;
}
