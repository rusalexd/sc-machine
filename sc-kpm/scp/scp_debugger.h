
#ifndef SCP_DEBUGGER_H
#define SCP_DEBUGGER_H

#include "scp_lib.h"


#endif // SCP_DEBUGGER_H

scp_result set_current_scp_procedure(scp_operand*);

scp_result is_procedure_operator_breakpoint(scp_operand*);

scp_result find_breakpoints_set();

scp_result is_process_operator_breakpoint(scp_operand*);

