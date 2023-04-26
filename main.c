#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#include "macros/keywords.h"
#include "macros/general.h"
#include "macros/instructions.h"
#include "types/linkedlist.h"


ListNode_i64* stack_top;
int64_t i, j, k, x;
int64_t registers[6];
int16_t* labels;
bool initialized;


inline
void initialize(int goto_count)
{

	if (!initialized) {
		stack_top = (ListNode_i64*) calloc(1, sizeof(ListNode_i64));
		labels = (int16_t*) calloc(goto_count, sizeof(int16_t));
		initialized = true;
	}

}


void interpreter(int64_t* instructions)
{

	int16_t curr_goto = 0;
	read_instructions:

	/* Instruction calls */
	if (INSTRUCTION == _MOV_) JUMP_AFTER_CALL(MOVE);
	if (INSTRUCTION == _ADD_) JUMP_AFTER_CALL(ADD);
	if (INSTRUCTION == _SUB_) JUMP_AFTER_CALL(SUBTRACT);
	if (INSTRUCTION == _OUT_) JUMP_AFTER_CALL(OUT);
	if (INSTRUCTION == _COUT_) JUMP_AFTER_CALL(COUT);
	if (INSTRUCTION == _NEWL_) JUMP_AFTER_CALL(NEWL);
	if (INSTRUCTION == _GOTO_) GOTO;
	if (INSTRUCTION == _TERMINATE_) TERMINATE;

	/* 'Parsing' calls */
	if (INSTRUCTION == _LABEL_) {
		labels[curr_goto] = INDEX;
	}

	INDEX_INCREMENT;
	goto read_instructions;

	//printf("INSTRUCTION: %d, INDEX: %d, \n", instructions[i], i);
	terminate_interpreter:
	printf("INDEX: %d\n", i);
	printf("RETURN_VALUE: %d\n", RETURN_VAL);

}


void parser(int64_t* instructions)
{
	/*
	This should be taken care of by the tokenizer,
	but there is no tokenizer yet, since I'm making
	the interpreter first.
	*/

	int goto_count = 0;
	INDEX--;

	while (INSTRUCTION != _TERMINATE_) {
		if (INSTRUCTION == _LABEL_) ++goto_count;
		INSTRUCTION = NEXT_INSTRUCTION;
	}

	INDEX = 0;
	initialize(goto_count);

}


void main()
{

	#define _INT_ARRAY(...) (int64_t[]){ __VA_ARGS__ }

	// #define _INSTRUCTIONS \
	// _LABEL_, \
	// _MOV_, 2, _LITERAL_, 50000, \
	// _MOV_, 0, _REGISTER_, 2, \
	// _SUB_, _REGISTER_, 2, _LITERAL_, 25000, \
	// _MOV_, 1, _REGISTER_, 0, \
	// _SUB_, _REGISTER_, 0, _LITERAL_, 5000, \
	// _ADD_, _REGISTER_, 0, _LITERAL_, 50, \
	// _GOTO_, _LITERAL_, 0, \
	// _TERMINATE_, \

	#define _INSTRUCTIONS \
	_COUT_, _L_, 'H', \
	_COUT_, _L_, 'e', \
	_COUT_, _L_, 'l', \
	_COUT_, _L_, 'l', \
	_COUT_, _L_, 'o', \
	_COUT_, _L_, ' ', \
	_COUT_, _L_, 'W', \
	_COUT_, _L_, 'o', \
	_COUT_, _L_, 'r', \
	_COUT_, _L_, 'l', \
	_COUT_, _L_, 'd', \
	_COUT_, _L_, '!', \
	_NEWL_, \
	_TERMINATE_, \

	parser(_INT_ARRAY(_INSTRUCTIONS));
	interpreter(_INT_ARRAY(_INSTRUCTIONS));

}