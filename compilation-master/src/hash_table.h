#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdio.h>
#include "sym.h"

#define NB_SYM_MAX 1993


struct Hash_table {
  struct Sym v[NB_SYM_MAX];
};


//Calcule le hash d'une chaine de caractere
int ht_hash(const char*);

//Renvoie la variable du nom correpondant
struct Sym* ht_get(struct Hash_table*, const char*);

//Renvoie la variable du nom correpondant
struct Sym* ht_get_nth(struct Hash_table*, int);


//Ajoute une entree et renvoie l'indice concerne
int ht_add(struct Hash_table*, const char*, const char*, int);

//Retourne le nom llvm de la varible de nom correspondant
const char* ht_get_llvm_name(struct Hash_table*, const char*);

//Renvoie vrai si la variable est dans la table
int ht_exists(struct Hash_table*, const char*);

//Initialise la table de hashes (tout a 0)
void ht_init(struct Hash_table*);

//Supprime une valeur dans la table de hashage (renvoie 0 si pas d'erreur)
int ht_remove(struct Hash_table*, const char*);

#endif
