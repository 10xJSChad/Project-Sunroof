#define JUMP_AFTER_CALL(MACRO) { \
	MACRO; \
	INDEX_INCREMENT; \
	goto read_instructions; \
}

/*
REG[NEXT_INSTRUCTION] += NEXT_VALUE
did *not* behave how I thought it would
serious issues, definitely due to the
horrible macro that is NEXT_VALUE
doing shit the compiler does not expect it to
so I just used extended assembly instead, works fine.
*/
#define MOVE { \
	asm \
	("mov %1, %0\n" \
	: "=r" (REG[NEXT_INSTRUCTION]) \
	: "r"  (NEXT_VALUE) \
	); \
}

#define ADD { \
	RETURN_VAL = NEXT_VALUE + NEXT_VALUE; \
}

#define SUBTRACT { \
	RETURN_VAL = NEXT_VALUE - NEXT_VALUE; \
}

#define GOTO { \
	INDEX = NEXT_VALUE; \
}

#define OUT printf("%d", NEXT_VALUE)
#define COUT printf("%c", NEXT_VALUE)
#define NEWL printf("\n")


#define TERMINATE { \
	goto terminate_interpreter; \
}
