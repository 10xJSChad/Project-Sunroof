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


#define TERMINATE { \
	goto terminate_interpreter; \
}

#define EQ ARG1 == ARG2

#define IF { \
	ARG1 = NEXT_VALUE; \
	ARG2 = NEXT_VALUE; \
	REG[3] = NEXT_INSTRUCTION; \
	switch (REG[3]) { \
		case 10: RETURN_VAL = ARG1 == ARG2; break; \
		case 11: RETURN_VAL = ARG1 != ARG2; break; \
		case 12: RETURN_VAL = ARG1 > ARG2; break; \
		case 13: RETURN_VAL = ARG1 >= ARG2; break; \
		case 14: RETURN_VAL = ARG1 < ARG2; break; \
		case 15: RETURN_VAL = ARG1 <= ARG2; break; \
		default: break; \
	} \
}

#define ADD (RETURN_VAL = NEXT_VALUE + NEXT_VALUE)
#define SUBTRACT (RETURN_VAL = NEXT_VALUE - NEXT_VALUE)
#define LABEL (NEXT_INSTRUCTION) // Skip, should be taken care of by a parser
#define GOTO (INDEX = NEXT_INSTRUCTION)
#define OUT printf("%d", NEXT_VALUE)
#define COUT printf("%c", NEXT_VALUE)
#define NEWL printf("\n")


