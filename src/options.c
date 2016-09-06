/*****************************************************************************/
/*!
\file options.c
\author Connor Deakin
\par E-mail: connortdeakin\@gmail.com
\par Project: Blockify
\date 30/08/2016
\brief
  Contains the implementation of all option argument related functions.
\par
    Functions Include:
    - free_options
    - print_help
    - parse_options
*/
/*****************************************************************************/

#include <getopt.h> /* getopt_long  */
#include <string.h> /* strlen       */
#include <stdlib.h> /* malloc, free */
#include <stdio.h> /* printf        */

#include "../header/options.h" /* struct Options */

/*****************************************************************************/
/*!
\brief
  Frees values from the Options struct that required dynamic memory allocation
\param  option_values
  The Options struct containing all of the option_values
*/
/*****************************************************************************/
void free_options(struct Options option_values)
{
  free(option_values.text);
}

/*****************************************************************************/
/*!
\brief
  Prints the help dialog for the program. This is printed if the user makes a
  mistake or asks for it with the -h or --help options.
*/
/*****************************************************************************/
void print_help()
{
  printf("--diagonal or -d          : Add a diagonal to the block\n");
  printf("--text \"text\" or -t \"text\": Specify custom text\n");
  printf("--help or -h              : Print this\n");
}

/*****************************************************************************/
/*!
\brief
  Given the argc and argv from main, this will parse the options given to the
  Blockify program so the program will work according to the users desire.
\param argc
  argc from main
\param argv
  argv from main
\return
  An Options struct containing all the information about the options provided
*/
/*****************************************************************************/
struct Options parse_options(int argc, char ** argv)
{
  int opt;
  struct Options option_values = {0, "SAMPLETEXT", 0, 1};
  while(1)
  {
    int opt_index = 0;
    int text_size;
    static struct option long_options[] =
    {
      {"diagonal", no_argument,       NULL, 'd'},
      {"text",     required_argument, NULL, 't'},
      {"help",     no_argument,       NULL, 'h'}
    };
    opt = getopt_long(argc, argv, ":dt:h", long_options, &opt_index);
    if(opt == -1)
      break;
    switch (opt)
    {
      case 'd' :
        option_values.diagonal = 1;
        break;
      case 't' :
        text_size = strlen(optarg);
        if(text_size > 0)
        {
          option_values.text = (char *)malloc(sizeof(char) * text_size);
          strcpy(option_values.text, optarg);
          option_values.custom_text = 1;
        }
        break;
      case 'h' :
        print_help();
        option_values.print_box = 0;
        break;
      case '?' :
        printf("The provided option [%c] is not an option.\n", (char)optopt);
        printf("Use --help or -h for help.\n");
        option_values.print_box = 0;
        break;
      case ':' :
        printf("The provided option [%c] requires an argument.\n",
          (char)optopt);
        printf("Use --help or -h for help.\n");
        option_values.print_box = 0;
        break;
    }
  }
  return option_values;
}
