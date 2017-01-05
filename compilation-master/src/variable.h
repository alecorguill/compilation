#ifndef VARIABLE_H
#define VARIABLE_H

#include <string.h>

#define V_NULL        0x0
#define V_INT        1//0x1//0x8
#define V_DOUBLE      1<<1//0x2//0x10
#define V_VOID       1<<2//0x0//0x4
#define V_WRITABLE   1<<3//0x8
#define V_DECLARED   1<<4//0x16
#define V_FUNCTION   1<<5//0x32
#define V_SPECIAL    1<<6//0x64
#define V_MODIFIED   1<<7//0x128
#define V_ARGS       0x1F<<8
#define SIZE_MAX 32

#include <stdio.h>

struct Variable {
  int flags;
  char name[SIZE_MAX];
  char llvm_name[SIZE_MAX];
  float value;
};


/*
|||||||||||||||||S|reg|reg|reg|reg|reg|reg|nargs|nargs|nargs|nargs|nargs|f|I|F|V|W|D|
*/
//typedef struct Variable;

/* Initialise la variable avec son nom, son nom llvm, et son type */
void var_init(struct Variable*, const char*, const char*, int);

/* Assigne la valeur (convertie apres eventuellement) */
void var_set_value(struct Variable*, double);

/* Assigne le type */
void var_set_type(struct Variable*, int);

/* Assigne le type */
void var_set_type(struct Variable*, int);

/* Assigne le type */
void var_set_special(struct Variable*, int);

/* Indique que la variable a ete modifiee */
void var_set_modified(struct Variable*, int);

/* Affiche les infos sur la variable */
void var_info(const struct Variable*);

/* Restreint ou pas l'acces en ecriture */
void var_set_access(struct Variable*, int);

/* Assigne un nombre d'argument a la fonction (ENTRE 0 ET 31)*/
void var_set_nb_args(struct Variable*, int);

/* Renvoie vrai si la variable a ete declaree */
int var_is_declared(const struct Variable*);

/* Renvoie vrai si on peut ecrire dans la variable */
int var_is_writable(const struct Variable*);

/* Revoie vrai si c'est une variable special */
int var_is_special(const struct Variable* v);

/* Revoie vrai si la variable a ete modifiee */
int var_is_modified(const struct Variable* v);

/* Renvoie vrai si la variable est une fonction */
int var_is_function(const struct Variable*);

/* Renvoie vrai si la variable est un entier */
int var_is_int(const struct Variable*);

/* Renvoie vrai si la variable est un flottant */
int var_is_float(const struct Variable*);

/* Renvoie le nombre d'argument dans le cas ou c'est une fonction */
int var_get_nb_args(const struct Variable*);

/* Renvoie un entier correspondant au type de la variable */
int var_get_type(const struct Variable*);

/* Renvoie la valeur de la variable (au format float pour eviter les problemes) */
double var_get_value(const struct Variable*);

/* Efface le contenu d'une varialbe */
void var_reset(struct Variable*);

/* Revoie le nom de la variable utilise dans enseirbot.bot */
const char* var_get_name(const struct Variable*);

/* Revoie le nom de la variable utilise dans le code llvm*/
const char* var_get_llvm_name(const struct Variable*);

#endif
