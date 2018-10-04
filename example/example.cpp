#include "linse.hpp"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static const char* examples[] = {
  "db", "hello", "hallo", "hans", "hansekogge", "seamann", "quetzalcoatl", "quit", "power", NULL
};

linse::completions completionHook (std::string_view prefix) {
  linse::completions lc;
  for (std::size_t i = 0; examples[i] != NULL; ++i) {
    if (strncmp(prefix.data(), examples[i], prefix.size()) == 0) {
      lc.add_completion(std::string_view{examples[i]}.substr(prefix.size()));
    }
  }
  return lc;
}

int main (int argc, char** argv) {
  linse ls;
  ls.install_window_change_handler();

  while(argc > 1) {
    argc--;
    argv++;
    if (!strcmp(*argv, "--keycodes")) {
      ls.print_key_codes();
      exit(0);
    }
  }

  const char* file = "./history";

  ls.history.load(file);
  ls.completion_callback = linse::word_completion{&completionHook};

  printf("starting...\n");

  char const* prompt = "\x1b[1;32mlinse\x1b[0m> ";

  while (1) {
    auto result = ls(prompt);

    if (!result || (*result)[0] == '\0') {
      break;
    } else if (!strncmp(result->data(), "/history", 8)) {
      /* Display the current history. */
      for (int index = 0; ; ++index) {
        auto hist = ls.history(index);
        if (!hist) break;
        printf("%4d: %s\n", index, hist->data());
       }
    }

    printf("thanks for the input.: %s\n", result->c_str());
    ls.history.add(result->data());
  }

  ls.history.save(file);
}
