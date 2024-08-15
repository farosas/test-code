#ifndef ERROR_INJECT_H
#define ERROR_INJECT_H

#define ERROR_INJECT_ENABLE_HOOK(sym)           \
    do {                                        \
        if (error_inject_enable_hook_##sym) {   \
            error_inject_enable_hook_##sym();   \
        }                                       \
    } while (0)

#define ERROR_INJECT_DISABLE_HOOK(sym)          \
    do {                                        \
        if (error_inject_disable_hook_##sym) {  \
            error_inject_disable_hook_##sym();  \
        }                                       \
    } while(0)

#define ERROR_INJECT_DECLARE(sym)                                       \
    __attribute__((weak)) void error_inject_enable_hook_##sym(void);    \
    __attribute__((weak)) void error_inject_disable_hook_##sym(void);   \

ERROR_INJECT_DECLARE(__fxstat64)

#endif /* ERROR_INJECT_H */
