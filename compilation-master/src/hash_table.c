#include "hash_table.h"

void ht_init(struct Hash_table* table) {
  int i=0;
  for(i=0;i<NB_VAR_MAX;i++){
    var_reset(&(table->v)[i]);
  }
}


int ht_hash(const char *name){
  int h=0;
  while(*name != 0){
    h+= *(name++) * 19;
  }
  return h%NB_VAR_MAX;
}


struct Variable* ht_get_nth(struct Hash_table* table, int n) {
  return &(table->v[n]);
}

int ht_remove(struct Hash_table* table, const char* name) {
  if(!ht_exists(table, name)){
    return -1;
  }
  struct Variable* v = ht_get(table, name);
  var_reset(v);
  
  return 0;
}


int ht_add(struct Hash_table* table, const char* name, const char* llvm_name, int type) {
  /* Modifiee ici llvm_name->name */
  int index = ht_hash(name);

  if(var_is_declared(ht_get(table, name))){
    printf("Collision dans la table de hashes pour '%s'", name);
  }
  
  var_init(&(table->v[index]), name, llvm_name, type);

  return index;
}

int ht_exists(struct Hash_table* table, const char* name) {
  int index = ht_hash(name);

  return var_is_declared(&(table->v[index]));
}

const char* ht_get_llvm_name(struct Hash_table* table, const char* name){
  return table->v[ht_hash(name)].llvm_name;
}

struct Variable* ht_get(struct Hash_table* table, const char* name) {
  int index = ht_hash(name);
  return &(table->v[index]);
}


