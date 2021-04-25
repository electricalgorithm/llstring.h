#include "llstring.h"
#include <stdlib.h>
#include <stdio.h>

/*    String Creation Functions     */
LL_StringNode* create_llstring (const char char_array[]) {
  // Creation of temporary letters' nodes
  LL_StringNode *head = NULL;
  LL_StringNode *temp = NULL;
  LL_StringNode *temp_before = NULL;

  u_int16_t char_pos = 0;
  while (char_array[char_pos] != '\0') {
    temp = (LL_StringNode *) malloc(sizeof(LL_StringNode));
    temp->character = char_array[char_pos];

    // Previous Letter Assignment
    if (!char_pos) temp->prev_letter = NULL;
    else temp->prev_letter = temp_before;

    // Next Letter Assigment
    temp->next_letter = NULL;
    if (char_pos) temp_before->next_letter = temp;

    // Assigning Node to Not Forget
    if (!char_pos) head = temp;
    temp_before = temp;

    // Next letter in the char[]
    char_pos++;
  }

  return head;
}

void delete_character (LL_StringNode *llstring, u_int16_t index) {
  LL_StringNode *node = llstring;

  // Going to (index)th node
  for (u_int16_t jndex = 0; jndex < index; jndex++) {
    node = node->next_letter;
  }

  // Extracting previous and next nodes
  LL_StringNode *_prev = node->prev_letter;
  LL_StringNode *_next = node->next_letter;

  // Changing next node of _prev to _next
  // and vice versa
  _prev->next_letter = _next;
  _next->prev_letter = _prev;

  // Freeing allocated memory
  free(node);
}

void append_llstring (LL_StringNode *appended, LL_StringNode *source, u_int16_t index) {
  LL_StringNode *_src = source;
  LL_StringNode *_appn = appended;

  // Going to (index)th node of source
  for (u_int16_t jndex = 0; jndex < index; jndex++) {
    _src = _src->next_letter;
  }
  // Going to last node of appended
  while (_appn->next_letter != NULL) {
    _appn = _appn->next_letter;
  }

  _appn->next_letter = _src->next_letter;
  _src->next_letter = appended;
}

/*    String Manipulation Functions   */
LL_StringNode *ll_strcpy (LL_StringNode* destination, LL_StringNode* source) {
  LL_StringNode *_cursor_src = source;
  LL_StringNode *_cursor_dest = destination;
  LL_StringNode *_cursor_dest_prev = NULL;

  while (_cursor_src != NULL) {
    // Assigning properties of that struct
    if (_cursor_src->next_letter != NULL) _cursor_dest->next_letter = (LL_StringNode *) malloc(sizeof(LL_StringNode));
    _cursor_dest->prev_letter = _cursor_dest_prev;
    _cursor_dest->character = _cursor_src->character;

    // Making a copy pointer of prev and go to next
    _cursor_dest_prev = _cursor_dest;
    _cursor_dest = _cursor_dest->next_letter;
    _cursor_src = _cursor_src->next_letter;
  }


  return destination;
}

/*    String Manipulation Functions   */
LL_StringNode *ll_strncpy (LL_StringNode* destination, LL_StringNode* source, u_int16_t count) {
  LL_StringNode *_cursor_src = source;
  LL_StringNode *_cursor_dest = destination;
  LL_StringNode *_cursor_dest_prev = NULL;
  u_int16_t counter = 0;

  while (_cursor_src != NULL && counter <= count-1) {
    // Assigning properties of that struct
    if (_cursor_src->next_letter != NULL && counter+1 <= count-1) _cursor_dest->next_letter = (LL_StringNode *) malloc(sizeof(LL_StringNode));
    _cursor_dest->prev_letter = _cursor_dest_prev;
    _cursor_dest->character = _cursor_src->character;

    // Making a copy pointer of prev and go to next
    _cursor_dest_prev = _cursor_dest;
    _cursor_dest = _cursor_dest->next_letter;
    _cursor_src = _cursor_src->next_letter;
    counter++;
  }

  return destination;
}

size_t ll_strlen (LL_StringNode* llstring) {
  LL_StringNode *cursor_counter = llstring;
  size_t length = 0;
  // Traveling throughout the linked list
  while (cursor_counter != NULL) {
    length++;
    cursor_counter = cursor_counter->next_letter;
  }

  return length;
}

LL_StringNode *ll_strcat (LL_StringNode *destination, LL_StringNode *source) {
  u_int16_t length_dest = (u_int16_t) ll_strlen(destination);
  append_llstring(source, destination, length_dest-1);
  return destination;
}

int ll_strcmp (LL_StringNode *llstr1, LL_StringNode *llstr2) {
  LL_StringNode *_cursor1  = llstr1;
  LL_StringNode *_cursor2  = llstr2;
  // Checking every element
  while (_cursor1 != NULL && _cursor2 != NULL) {
    // The conditions are prepared according to original strcmp function.
    if (_cursor1->character > _cursor2->character) return 1;
    else if (_cursor1->character < _cursor2->character) return -1;
    else {
      _cursor1 = _cursor1->next_letter;
      _cursor2 = _cursor2->next_letter;
    }
  }

  // If both llstrings are equal, returns 0.
  return 0;
}

int ll_strncmp (LL_StringNode* llstr1, LL_StringNode* llstr2, u_int16_t count) {
  LL_StringNode *_cursor1  = llstr1;
  LL_StringNode *_cursor2  = llstr2;
  u_int16_t counter = 0;
  // Checking every element
  while (_cursor1 != NULL && _cursor2 != NULL && counter <= count-1) {
    // The conditions are prepared according to original strcmp function.
    if (_cursor1->character > _cursor2->character) return 1;
    else if (_cursor1->character < _cursor2->character) return -1;
    else {
      _cursor1 = _cursor1->next_letter;
      _cursor2 = _cursor2->next_letter;
      counter++;
    }
  }
  // If both llstrings are equal, returns 0.
  return 0;
}

void printf_llstring (LL_StringNode* llstring) {
  // Clearing the stdout buffer
  fflush(stdout);

  // Creating a temp pointer to travel
  LL_StringNode *temp = llstring;
  while (1) {
    printf("%c", temp->character);

    if (temp->next_letter != NULL) {
      temp = temp->next_letter;
    } else {
      break;
    }
  }
}