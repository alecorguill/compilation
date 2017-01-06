#ifndef SYM_H
#define SYM_H

#include <string.h>

#define S_NULL        0x0
#define S_INT        1//0x1//0x8
#define S_DOUBLE      1<<1//0x2//0x10
#define S_VOID       1<<2//0x0//0x4
#define S_WRITABLE   1<<3//0x8
#define S_DECLARED   1<<4//0x16
#define S_FUNCTION   1<<5//0x32
#define S_SPECIAL    1<<6//0x64
#define S_MODIFIED   1<<7//0x128
#define S_ARGS       0x1F<<8
#define SIZE_MAX 32

#include <stdio.h>

struct Sym {
  int flags;
  char name[SIZE_MAX];
  char llvm_name[SIZE_MAX];
  float value;
};

void sym_init(struct Sym*, const char*, const char*, int);

void sym_set_value(struct Sym*, double);

void sym_set_type(struct Sym*, int);

void sym_set_type(struct Sym*, int);

void sym_set_special(struct Sym*, int);

void sym_set_modified(struct Sym*, int);

void sym_info(const struct Sym*);

void sym_set_access(struct Sym*, int);

void sym_set_nb_args(struct Sym*, int);

int sym_is_declared(const struct Sym*);

int sym_is_writable(const struct Sym*);

int sym_is_special(const struct Sym* v);

int sym_is_modified(const struct Sym* v);

int sym_is_function(const struct Sym*);

int sym_is_int(const struct Sym*);

int sym_is_float(const struct Sym*);

int sym_get_nb_args(const struct Sym*);

int sym_get_type(const struct Sym*);

double sym_get_value(const struct Sym*);

void sym_reset(struct Sym*);

const char* sym_get_name(const struct Sym*);

const char* sym_get_llvm_name(const struct Sym*);

#endif
