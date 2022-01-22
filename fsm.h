#ifndef FSM_H
#define FSM_H

#include<stdbool.h>

#define MAX_STATES 20
#define MAX_BUF_SIZE 20
#define MAX_FSM_NAME 30
#define MAX_STATE_NAME 10
#define MAX_TRANSITION_KEY_SIZE 20
#define MAX_TRANSITION_TABLE_ENTRIES 20
#define MAX_STATES_TO_POINT 5


typedef enum{FSM_FALSE, FSM_TRUE}fsm_bool;

struct transition_table_entry
{
  /*transition key to be compared with the input string*/
  char transition_key[MAX_TRANSITION_KEY_SIZE];

  /*transition key size, it refers to the size input taken by the state*/
  int transition_key_size;

  /*pointer ti the next state if key matches with input*/
  state_ *next_state[MAX_STATES_TO_POINT];

};
typedef struct transition_table_entry tt_entry;

struct finite_state_table
{
  /*number of transisiton table entries per state*/
  tt_entry tt_entries[MAX_TRANSITION_TABLE_ENTRIES];
};
typedef struct finite_state_table tt_;

struct finite_state
{
  /*Name of the state*/
  char state_name[MAX_STATE_NAME];

  /*Transition table of the state*/
  tt_ *state_tt;

  /*a boolean to tell if it is a final state(1) or not(0)*/
  bool IS_FINAL; 
};
typedef struct finite_state state_;

struct finite_state_machine
{
  /*pointer to initial state of a finite stae machine*/
  state_ *initial_state;

  /*name of the finite state machine*/
  char fsm_name[MAX_FSM_NAME];

  /*a character array that stores the input string given to the finite state machine*/
  char input_buf[MAX_BUF_SIZE];

  /*a cursor that points to current state in the finite state machine*/
  int cursor;

};
typedef struct finite_state_machine fsm_;




#endif 