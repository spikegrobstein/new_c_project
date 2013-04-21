#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>

#define DEFAULT_USERNAME "spike" /* default name for the user */
#define USERNAME_SIZE    256     /* the max length a username can be */

// getopt long options
static struct option longopts[] = {
  { "verbose", optional_argument, NULL, 'v' },
  { "user", optional_argument, NULL, 'u' },
  { 0, 0, 0, 0 }
};

int
main(int argc, char **argv, char **env)
{
  printf("y0\n");

  // whether we're verbose or not.
  int verbose_flag = 0,
      ch,
      ind;

  char username[USERNAME_SIZE] = DEFAULT_USERNAME;

  while ((ch = getopt_long(argc, argv, "vu:", longopts, &ind)) != -1) {
    switch (ch) {
      case 'v':
        verbose_flag++;
        break;
      case 'u':
        // FIXME: verify that the new name isn't too long
        strcpy(username, optarg);
        break;
      default:
        printf("Error!\n");
    }
  }

  printf("optind:   %d/%d\n", optind, argc);
  printf("verbose:  %d\n", verbose_flag);
  printf("username: %s\n", username);

  return 0;
}
