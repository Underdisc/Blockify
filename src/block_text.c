/*****************************************************************************/
/*!
\file block_text.c
\author Connor Deakin
\par E-mail: connortdeakin\@gmail.com
\par Project: Blockify
\date 30/08/2016
\brief
  Contains the implementation of all the functions used to create, manipulate,
  and print blocks.
\par
    Functions Include:
    - print_block
    - free_block
    - blockify
    - add_diagonal
*/
/*****************************************************************************/

#include <stdio.h>  /* printf       */
#include <stdlib.h> /* malloc, free */

/*****************************************************************************/
/*!
\brief
  Prints the block to console
\param block
  The block to be printed to the screen
\param num_strings
  The number of strings contiained in the block (The length of the input string)
*/
/*****************************************************************************/
void print_block(char ** block, int num_strings)
{
  for(int str = 0; str < num_strings; ++str)
    printf("%s\n", *(block + str));
}

/*****************************************************************************/
/*!
\brief
  Fress the block from memory
\param block
  The block to be freed from memory
\param num_elements
  The number of null terminated strings contained in the block
*/
/*****************************************************************************/
void free_block(char ** block, int num_elements)
{
  for(int str = 0; str < num_elements; ++str)
    free(*(block + str));
  free(block);
}

/*****************************************************************************/
/*!
\brief
  Creates a block version of text given to the function
\param text
  The text that will be blockified
\param text_size
  The length of the text that is to be blockified
\return
  The block created by the blockify function from the text
*/
/*****************************************************************************/
char ** blockify(char * text, int text_size)
{
  int spaced_size = (text_size * 2) - 1;
  char ** block = (char **)malloc(sizeof(char *) * text_size);
  *block = (char *)malloc(sizeof(char *) * spaced_size);
  *(block + text_size - 1) = (char *)malloc(sizeof(char **) * spaced_size);
  //Top and Bottom
  for(int c = 0; c < spaced_size; ++c)
  {
    if(c % 2 == 0)
    {
      *(*block + c) =  *(text + (c / 2));
      *(*(block + text_size - 1) + spaced_size - 1 - c) = *(text + (c / 2));
    }
    else
    {
      *(*block + c) = ' ';
      *(*(block + text_size - 1) + spaced_size - 1 - c) = ' ';
    }
  }
  //Right and Left
  for(int c = 1; c < (text_size - 1); ++c)
  {
    *(block + c) = (char *)malloc(sizeof(char) * spaced_size);
    // first char
    **(block + c) = *(text + c);
    //spaces
    for(int s = 1; s < (spaced_size - 1); ++s)
      *(*(block + c) + s) = ' ';
    // last char
    *(*(block + c) + (spaced_size - 1)) = *(text + text_size - 1 - c);
  }
  return block;
}

/*****************************************************************************/
/*!
\brief
  Adds a diagonal element to a created block
\param block
  The block that a diagonal will be added to
\param num_elements
  The number of null terminated string elements in the block
*/
/*****************************************************************************/
void add_diagonal(char ** block, int num_elements)
{
  int half = (num_elements - 1) / 2;
  int text_size =  (num_elements * 2) - 1;
  for(int c = 1; c < (num_elements - 1); ++c)
  {
    char cur_char = *(*block + (c * 2));
    if(c <= half)
    {
      //Top left
      *(*(block + c) + (c * 2)) = cur_char;
      //Bottom right
      *(*(block + num_elements  - 1 - c) + text_size - 1 - (c * 2)) = cur_char;
    }
    else
    {
      //Top Right
      *(*(block + num_elements - 1 - c) + (c * 2)) = cur_char;
      //Bottom left
      *(*(block + c) + text_size - 1 - (c * 2)) = cur_char;
    }
  }
}
