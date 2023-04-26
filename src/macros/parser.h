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

#define PARSER_FIND_ENDIF ({ \
    ++i; \
    x = 1; \
    while (instructions[i+1] != -1) { \
        if (instructions[i] == _IF_) ++x; \
        if (instructions[i] == _ENDIF_) --x; \
        if (x == 0) break; \
        ++i; \
    } \
	i; \
})

