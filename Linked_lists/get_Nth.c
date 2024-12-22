#include <stddef.h>

struct List {
	struct List *next;
	int data;
};

// return the nth node, or NULL if n >= length(list)
struct List *get_nth_node (const struct List *list, size_t n)
{
    while (n-- && list)
        list = list->next;

	return list;
}