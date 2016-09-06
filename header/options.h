/*****************************************************************************/
/*!
\file options.h
\author Connor Deakin
\par E-mail: connortdeakin\@gmail.com
\par Project: Blockify
\date 30/08/2016
\brief
  Contains the prototypes and data structs used for the blockify program.

\par
  Functions Include
    - free_options
    - print_help
    - parse_options
*/
/*****************************************************************************/

/******************************************************************************/
#ifndef OPTIONS_H
#define OPTIONS_H
/******************************************************************************/

/*****************************************************************************/
/*!
\struct Options
\brief
  Contains all the variables that will be used to store the information about
  the arguments added to the blockify command by the user.

\deprecated
    - Nothing
*/
/*****************************************************************************/
struct Options
{
  /*! Determines whether a diagonal is added to the block */
  char diagonal;
  /*! Used to store the text specified by the user */
  char * text;
  /*! If the user has custom text, this will be set to 1 to indicate memory */
  char custom_text;
  /*! Determines if any block should be printed to the screen because of user
   * error */
  char print_box;
};

void free_options(struct Options option_values);
void print_help();
struct Options parse_options(int argc, char ** argv);

#endif
/******************************************************************************/
