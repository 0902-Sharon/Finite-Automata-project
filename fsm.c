#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include "fsm.h"

fsm_* create_new_fsm(char *fsm_name)
{
  fsm_ *new_fsm = calloc(1,sizeof(struct finite_state_machine));
  strncpy(new_fsm->fsm_name,fsm_name,MAX_FSM_NAME-1);
  new_fsm->fsm_name[MAX_FSM_NAME-1] = '\0';
  return new_fsm;
}

state_* create_new_state(char *state_name, bool is_final)
{
  state_* new_state = calloc(1,sizeof(struct finite_state));
  strncpy(new_state->state_name,state_name,MAX_STATE_NAME-1);
  new_state->state_name[MAX_STATE_NAME-1] = '\0';
  new_state->IS_FINAL = is_final;
  return new_state;
}

void set_state_as_intial_state(fsm_ *fsm, state_ *state)
{
  fsm->initial_state = state;
}

tt_entry* get_next_avail_tt_entry(tt_ *transition_table)
{
  int i=0;
  while(i <= MAX_TRANSITION_TABLE_ENTRIES)
  {
    if((transition_table->tt_entries[i])->next_state == NULL) /*checking if transition table entry is empty or not*/
    {
      break;
    }  
    else
    {
      i++;
    }
  }
  if(i > MAX_TRANSITION_TABLE_ENTRIES)
  {
     return NULL;
  }
  return (transition_table->tt_entries[i]);
}

tt_entry* create_and_insert_new_tt_entry(tt_ *transition_table, char *transition_key, int transition_key_size, state_ *next_state)
{
  if(transition_key_size <= MAX_TRANSITION_KEY_SIZE)
  {
    tt_entry *new_tt_entry = get_next_empty_tt_entry(transition_table);
    if(new_tt_entry == NULL)
    {
      printf("\nFatal error: Transition table is full!\n");
    }
    memcpy(new_tt_entry->transition_key, transition_key, transition_key_size);
    new_tt_entry->transition_key[transition_key_size] = '\0';
    new_tt_entry->transition_key_size = transition_key_size;
    new_tt_entry->next_state = next_state;

    return new_tt_entry;
    
  }
  else
  {
    printf("\ntransisiton key size cannot be greater than %d",MAX_TRANSITION_KEY_SIZE);
    exit(0);
  }
}