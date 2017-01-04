#include "variable.h"

void var_init(struct Variable* v, const char* name, const char* llvm_name, int type) {
  v->value = 0;
  strncpy(v->name, name, SIZE_MAX);
  strncpy(v->llvm_name, llvm_name, SIZE_MAX);
  v->flags = 0|V_DECLARED|V_WRITABLE|type;
}


int var_is_declared(const struct Variable* v) {
  return (v->flags & V_DECLARED);
}
int var_is_writable(const struct Variable* v) {
  return (v->flags & V_WRITABLE);
}
int var_is_function(const struct Variable* v) {
  return (v->flags & V_FUNCTION);
}
int var_is_int(const struct Variable* v) {
  return (v->flags & V_INT);
}
int var_is_double(const struct Variable* v) {
  return (v->flags & V_DOUBLE);
}

int var_is_special(const struct Variable* v) {
  return (v->flags & V_SPECIAL);
}

int var_is_modified(const struct Variable* v) {
  return (v->flags & V_MODIFIED);
}

int var_get_nb_args(const struct Variable* v) {
  return ((v->flags & V_ARGS) >> 6);
}
int var_get_type(const struct Variable* v) {
  return (v->flags & (V_INT | V_DOUBLE | V_VOID));
}
const char* var_get_name(const struct Variable* v) {
  return v->name;
}
const char* var_get_llvm_name(const struct Variable* v) {
  return v->llvm_name;
}

double var_get_value(const struct Variable* v) {
  return v->value;
}

void var_info(const struct Variable* v){
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

void var_set_value(struct Variable* v, double val) {
  if(!var_is_writable(v)){
    return;
  }
  
  v->value = val;
}

void var_set_access(struct Variable* v, int wflag) {
  if(wflag != V_WRITABLE) {
    v->flags &= ~V_WRITABLE;
  }
  else {
    v->flags |= V_WRITABLE;
  }
}     

void var_reset(struct Variable* v) {
  v->flags = V_NULL;
  *(v->name) = V_NULL;
  *(v->llvm_name) = V_NULL;
  v->value = V_NULL;
}

void var_set_type(struct Variable* v, int type) {
  v->flags &= ~(V_INT | V_DOUBLE | V_VOID);
  v->flags |= type;
}

void var_set_special(struct Variable* v, int special) {
  if(special != V_SPECIAL) {
    v->flags &= ~(V_SPECIAL);
  }
  else {
    v->flags |= V_SPECIAL;
  }
}

void var_set_modified(struct Variable* v, int modified) {
  if(modified != V_MODIFIED) {
    v->flags &= ~(V_MODIFIED);
  }
  else {
    v->flags |= V_MODIFIED;
  }
}


void var_set_register(struct Variable* v, int reg) {
  if(reg > 63){
    return;
  }
  int nb_reg = reg << 11;
  v->flags |= nb_reg;
}

void var_set_nb_args(struct Variable* v, int args) {
  if(args > 31){
    return;
  }
  int nb_args = args << 6;
  v->flags |= nb_args;
}
  
