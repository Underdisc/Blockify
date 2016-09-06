/*****************************************************************************/
/*!
\file block_text.h
\author Connor Deakin
\par E-mail: connortdeakin\@gmail.com
\par Project: Blockify
\date 30/08/2016
\brief
  The interface for creating, manipulating, and printing blocks.
*/
/*****************************************************************************/

/* All function comments contained in the source file */
void free_block(char ** block, int num_elements);
void print_block(char ** text, int num_strings);
char ** blockify(char * text, int text_size);
void add_diagonal(char ** block, int nuum_elements);
