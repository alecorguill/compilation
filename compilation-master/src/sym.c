#include "sym.h"

void sym_init(struct Sym* v, const char* name, const char* llvm_name, int type) {
  v->value = 0;
  strncpy(v->name, name, SIZE_MAX);
  strncpy(v->llvm_name, llvm_name, SIZE_MAX);
  v->flags = 0|S_DECLARED|S_WRITABLE|type;
}


int sym_is_declared(const struct Sym* v) {
  return (v->flags & S_DECLARED);
}
int sym_is_writable(const struct Sym* v) {
  return (v->flags & S_WRITABLE);
}
int sym_is_function(const struct Sym* v) {
  return (v->flags & S_FUNCTION);
}
int sym_is_int(const struct Sym* v) {
  return (v->flags & S_INT);
}
int sym_is_double(const struct Sym* v) {
  return (v->flags & S_DOUBLE);
}

int sym_is_special(const struct Sym* v) {
  return (v->flags & S_SPECIAL);
}

int sym_is_modified(const struct Sym* v) {
  return (v->flags & S_MODIFIED);
}

int sym_get_nb_args(const struct Sym* v) {
  return ((v->flags & S_ARGS) >> 6);
}
int sym_get_type(const struct Sym* v) {
  return (v->flags & (S_INT | S_DOUBLE | S_VOID));
}
const char* sym_get_name(const struct Sym* v) {
  return v->name;
}
const char* sym_get_llvm_name(const struct Sym* v) {
  return v->llvm_name;
}

double sym_get_value(const struct Sym* v) {
  return v->value;
}

void sym_info(const struct Sym* v){
  int i=0;
  int bit;
  printf(";;");
  for(i=0;i<32;i++){
    bit = ((v->flags & (1 << i)) == 0)?0:1;
    printf("%d", bit);
  }
  printf("\n");
  printf(";;Nom : %s\n", v->name);
  printf(";;Nom llvm : %s\n", v->llvm_name);
}

void sym_set_value(struct Sym* v, double val) {
  if(!sym_is_writable(v)){
    return;
  }

  v->value = val;
}

void sym_set_access(struct Sym* v, int wflag) {
  if(wflag != S_WRITABLE) {
    v->flags &= ~S_WRITABLE;
  }
  else {
    v->flags |= S_WRITABLE;
  }
}

void sym_reset(struct Sym* v) {
  v->flags = S_NULL;
  *(v->name) = S_NULL;
  *(v->llvm_name) = S_NULL;
  v->value = S_NULL;
}

void sym_set_type(struct Sym* v, int type) {
  v->flags &= ~(S_INT | S_DOUBLE | S_VOID);
  v->flags |= type;
}

void sym_set_special(struct Sym* v, int special) {
  if(special != S_SPECIAL) {
    v->flags &= ~(S_SPECIAL);
  }
  else {
    v->flags |= S_SPECIAL;
  }
}

void sym_set_modified(struct Sym* v, int modified) {
  if(modified != S_MODIFIED) {
    v->flags &= ~(S_MODIFIED);
  }
  else {
    v->flags |= S_MODIFIED;
  }
}


void sym_set_register(struct Sym* v, int reg) {
  if(reg > 63){
    return;
  }
  int nb_reg = reg << 11;
  v->flags |= nb_reg;
}

void sym_set_nb_args(struct Sym* v, int args) {
  if(args > 31){
    return;
  }
  int nb_args = args << 6;
  v->flags |= nb_args;
}

