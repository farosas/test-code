#define _GNU_SOURCE

#include <stdio.h>
#include <assert.h>
#include <dlfcn.h>
#include <sys/stat.h>
#include <unistd.h>

#define ERROR_INJECT_DECLARE_HOOK(sym)          \
    static int sym##_enabled;                   \
    void error_inject_enable_hook_##sym(void)   \
    {                                           \
        printf("%s\n", __func__);               \
        sym##_enabled = 1;                      \
    }                                           \
    void error_inject_disable_hook_##sym(void)  \
    {                                           \
        printf("%s\n", __func__);               \
        sym##_enabled = 0;                      \
    }                                           \

ERROR_INJECT_DECLARE_HOOK(__fxstat64);

static void *error_inject_old_symbol_addr(const char *sym)
{
    void *addr;
    char *err;

    dlerror();
    addr = dlsym(RTLD_NEXT, sym);
    err = dlerror();

    if (err) {
        return NULL;
    }

    return addr;
}

typedef int (*orig_sym_t)(int ver, int __fd, struct stat64 *__statbuf);
int __fxstat64 (int ver, int __fd, struct stat64 *__statbuf)
{
    static orig_sym_t fxstat64 = NULL;

    if (!fxstat64) {
        fxstat64 = error_inject_old_symbol_addr("__fxstat");
        assert(fxstat64);
    }

    if (__fxstat64_enabled) {
        printf("run %s hook\n", __func__);
        sleep(10);
    }

    return fxstat64(_STAT_VER, __fd, __statbuf);
}
