#define INDEX (i)
#define INDEX_INCREMENT (++i)
#define INSTRUCTIONS (instructions)
#define INSTRUCTION (instructions[i])
#define NEXT_INSTRUCTION (instructions[++i])

#define REG (registers)
#define REG_DEST (registers[instructions[++i]])

#define NEXT_VALUE \
	((instructions[++i]) ? (registers[instructions[++i]]) : (instructions[++i]))
	
#define RETURN_VAL (registers[0])
#define ARG1 (arg_registers[1])
#define ARG2 (arg_registers[2])
#define ARG3 (arg_registers[3])
#define ARG4 (arg_registers[4])
#define ARG5 (arg_registers[5])