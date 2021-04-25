# llstring.h
This repository contains a library for C programming language. The library consist of a linked-list implementation of default string.h library. Still, there are functions left which are not implemented. I'm going to implement them all in my free time.


## Interface
| Function 	| Parameters 	| Returns 	| Explanation 	|
|:-:	|:-:	|:-:	|-	|
| create_llstring 	| `char[]` 	| LL_StringNode* 	| The function creates a llstring with given char array, then return the head of the linked list. 	|
| delete_character 	| `LL_StringNode*, u_int16_t` 	|  	| The function deletes a ll-node in llstring in given index. Index are 0-based. 	|
| append_llstring 	| `LL_StringNode* x, LL_StringNode* y, u_int16_t p` 	|  	| The function appends `x` to `y` in position `p`. 	|
| printf_llstring | `LL_StringNode*` | | Prints the string.|
| ll_strcpy | `LL_StringNode* d, LL_StringNode* s` | LL_StringNode *d | The function copies content of `s` to `d`. To use the function, `d` must be a next-letter-is-NULL LL_StringNode. |
| ll_strcpy | `LL_StringNode* d, LL_StringNode* s, u_int16_t n` | LL_StringNode *d | The function copies content of `s` to `d` for first `n` characters. To use the function, `d` must be a next-letter-is-NULL LL_StringNode. |
| ll_strlen | `LL_StringNode* | size_t | The function returns length of the llstring. |
| ll_strcat | `LL_StringNode* x, LL_StringNode* y` | LLStringNode* x | The function appends the y into end of the x. |
| ll_strcmp | `LL_StringNode*, LL_StringNode*` | 1, -1, or 0 | The function works exactly same as strcmp. 0 means both llstrings are equal. It compares two llstring and if there is a difference, return which one have higher ASCII number. | 
| ll_strcmp | `LL_StringNode*, LL_StringNode*, u_int16_t n` | 1, -1, or 0 |  The function works exactly same as strcmp. 0 means both llstrings are equal. It compares two llstring for first `n` characters and if there is a difference, return which one have higher ASCII number. |

## Further Works
* Need to implement remaining functions.
* Need to create a function to convert llstring to char[].

## License
Check out the LICENSE file in the repository. The software licensed under MIT License 2021.