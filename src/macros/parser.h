#define PARSER_FIND_LABEL(label_i64) ({ \
    i = 0; \
    while (instructions[i+1] != -1) { \
        if (instructions[i] == 3 && instructions[i+1] == label_i64) { \
            break; \
        } \
        ++i; \
    } \
	i; \
})

