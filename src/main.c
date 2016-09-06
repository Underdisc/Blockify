/*****************************************************************************/
/*!
\file main.c
\author Connor Deakin
\par E-mail: connortdeakin\@gmail.com
\par Project: Blockify
\date 30/08/2016
\brief
  Entry point for the Blockify program
\par
    Functions Include:
    - main
*/
/*****************************************************************************/

#include <string.h> /* strlen */

#include "../header/block_text.h" /* blockify, add_diagonal, print_block,
                                     free_block */
#include "../header/options.h" /* parse_options, free_options */


/*****************************************************************************/
/*!
\brief
  Main function
\param  argc
  main argc
\param argv
  main argv
\return
  main int
*/
/*****************************************************************************/
int main(int argc,  char ** argv)
{
  struct Options option_values = parse_options(argc, argv);

  int text_size = strlen(option_values.text);
  if(option_values.print_box)
  {
    char ** block = blockify(option_values.text, text_size);
    if (option_values.diagonal)
      add_diagonal(block, text_size);
    print_block(block, text_size);
    free_block(block, text_size);
    if(option_values.custom_text)
      free_options(option_values);
  }
  return 0;
}
