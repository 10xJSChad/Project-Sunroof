#define INDEX (i)
#define INDEX_INCREMENT (++i)
#define INSTRUCTION (instructions[i])
#define NEXT_INSTRUCTION (instructions[++i])

#define REG (registers)
#define REG_DEST (registers[instructions[++i]])

#define NEXT_VALUE \
	((instructions[++i]) ? (registers[instructions[++i]]) : (instructions[++i]))
	
#define RETURN_VAL (registers[0])
#define ARG1 (registers[1])
#define ARG2 (registers[2])
#define ARG3 (registers[3])
#define ARG4 (registers[4])
#define ARG5 (registers[5])