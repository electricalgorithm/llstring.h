//
// Created by pop49 on 25/04/2021.
//
#include <stdlib.h>

#ifndef LL_STRING__LLSTRING_H_
#define LL_STRING__LLSTRING_H_

/*   The Node for Linked-Lists  */
typedef struct ll_letter_node {
  char character;
  struct ll_letter_node *next_letter;
  struct ll_letter_node *prev_letter;
} LL_StringNode;

/*    String Creation Functions     */
LL_StringNode* create_llstring (const char[]);
void delete_character (LL_StringNode*, u_int16_t);
void append_llstring (LL_StringNode*, LL_StringNode*, u_int16_t);

/*    String Manipulation Functions   */
LL_StringNode *ll_strcpy (LL_StringNode*, LL_StringNode*);
LL_StringNode *ll_strncpy (LL_StringNode*, LL_StringNode*, u_int16_t);
size_t ll_strlen (LL_StringNode*);
LL_StringNode *ll_strcat (LL_StringNode*, LL_StringNode*);
int ll_strcmp (LL_StringNode*, LL_StringNode*);
int ll_strncmp (LL_StringNode*, LL_StringNode*, u_int16_t);
void printf_llstring (LL_StringNode*);

/*    Not Implemented   */
//LL_StringNode *ll_strncat (LL_StringNode*, LL_StringNode*, u_int16_t);
//int ll_strcoll (LL_StringNode* ,LL_StringNode*);
//LL_StringNode *ll_strchr (LL_StringNode*, char);
//size_t ll_strcspn (LL_StringNode*, LL_StringNode*);
//LL_StringNode *ll_strpbrk (LL_StringNode*, LL_StringNode*);
//LL_StringNode *ll_strrchr (LL_StringNode*, LL_StringNode*);
//size_t ll_strspn (LL_StringNode*, LL_StringNode*);
//LL_StringNode *ll_strstr (LL_StringNode*, LL_StringNode*);
//LL_StringNode *ll_strtok (LL_StringNode*, LL_StringNode*);


#endif //LL_STRING__LLSTRING_H_
