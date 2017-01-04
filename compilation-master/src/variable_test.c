#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "variable.h"



int main(){
  struct Variable var;
  
  var_init(&var, "lol", "lolllvm", V_INT);
  assert (strcmp("lol", var_get_name(&var)) == 0);
  assert (strcmp("lolllvm", var_get_llvm_name(&var)) == 0);
  assert (var_is_int(&var) != 0);
  assert (var_is_float(&var) == 0);
  assert (var_get_type(&var) == V_INT);
  assert (var_is_special(&var) == 0);


  var_init(&var, "lol", "lolllvm", V_FLOAT|V_SPECIAL);
  var_info(&var);
  assert (var_is_int(&var) == 0);
  assert (var_is_float(&var) != 0);
  assert (var_get_type(&var) == V_FLOAT);
  assert (var_is_special(&var) != 0);
  
  var_set_value(&var, -131);
  assert (var_get_value(&var) == -131);

  var_set_value(&var, 1.234);
  assert (((var_get_value(&var)) - 1.234) < 0.00001);
  assert (var_get_value(&var) != 1);
      
  var_set_modified(&var, V_MODIFIED);
  assert (var_is_modified(&var) != 0);
  var_set_modified(&var, V_NULL);
  assert (var_is_modified(&var) == 0);

  
  var_set_type(&var, V_FLOAT);
  assert (var_is_int(&var) == 0);
  assert (var_is_float(&var) != 0);
  assert (var_get_type(&var) == V_FLOAT);

  var_set_special(&var, V_SPECIAL);
  assert (var_is_special(&var) != 0);


  var_set_type(&var, V_INT);
  assert (var_is_int(&var) != 0);
  assert (var_is_float(&var) == 0);
  assert (var_get_type(&var) == V_INT);

  var_set_access(&var, V_NULL);
  assert (var_is_writable(&var) == 0);
  var_set_access(&var, V_WRITABLE);
  assert (var_is_writable(&var) != 0);

  var.flags |= 1;
  assert (var_is_declared(&var) != 0);

  /* var_set_nb_args(&var, 13); */
  /* assert (var_get_nb_args(&var) == 13); */

  printf("Tests OK (sauf get_nb_args)\n");
}  


/* int var_is_function(const struct Variable*); */


