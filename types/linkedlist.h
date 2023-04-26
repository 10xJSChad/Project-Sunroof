typedef struct ListNode_i64{
	int64_t val;
	struct ListNode_i64* next;
	struct ListNode_i64* prev;
} ListNode_i64;


/* Stack macros */
#define STACK_PUSH(value) do { \
	ListNode_i64* node = (ListNode_i64*) malloc(sizeof(ListNode_i64)); \
	node->next = NULL; \
	node->prev = stack_top; \
	node->val = (value); \
	stack_top = node; \
} while (0)


#define STACK_POP ({ \
	RETURN_VAL = stack_top->val; \
	stack_top = stack_top->prev; \
	free(stack_top->next); \
	RETURN_VAL; \
})
