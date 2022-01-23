#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"fsm.h"

int main()
{
  /*Createing an FSM*/
  char transition_key_0 = '0',transition_key_1 = '1';
  int transition_keysize = 1;
  
  fsm_ *fsm = create_new_fsm("FSM Alt");

  /*Creating FSM states*/
  state_ *state_q0, *state_q1, *state_q2, *state_q3, *D;
  state_q0 = create_new_state("q0",FSM_FALSE);
  set_state_as_intial_state(fsm,state_q0);
  state_q1 = create_new_state("q1",FSM_TRUE);
  state_q2 = create_new_state("q2",FSM_TRUE);
  D = create_new_state("D",FSM_FALSE);


  /*creating the transition table for each of the states*/

  create_and_insert_new_tt_entry(&state_q0->state_tt,&transition_key_1, transition_keysize, state_q1);
  create_and_insert_new_tt_entry(&state_q0->state_tt,&transition_key_0, transition_keysize, state_q2);

  create_and_insert_new_tt_entry(&state_q1->state_tt,&transition_key_1, transition_keysize, D);
  create_and_insert_new_tt_entry(&state_q1->state_tt,&transition_key_0, transition_keysize, state_q2);

  create_and_insert_new_tt_entry(&state_q2->state_tt,&transition_key_1, transition_keysize, D);
  create_and_insert_new_tt_entry(&state_q2->state_tt,&transition_key_0, transition_keysize, state_q2);

  create_and_insert_new_tt_entry(&D->state_tt,&transition_key_1, transition_keysize, D);
  create_and_insert_new_tt_entry(&D->state_tt,&transition_key_0, transition_keysize, D);


  /*Using the FSM*/
  fsm_bool fsm_result;
  fsm_error_t fsm_error;
  
  fsm_error = execute_fsm(fsm, "01010101010101\0", strlen("01010101010101\0"), &fsm_result);

  if(fsm_error == fsm_no_error)
  {
    if(fsm_result == FSM_TRUE)
    {
        printf("\nThe string is validated \n");
    }
    else
    {
       printf("\nThe string is not validated \n");
    }
  }

  return 0;

}