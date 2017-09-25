#include "scp_debugger.h"
#include "scp_lib.h"
#include "scp_keynodes.h"
#include "scp_operator_interpreter_functions.h"

scp_operand *current_scp_procedure;
scp_operand current_breakpoints_set;

scp_result set_current_scp_procedure(scp_operand *scp_procedure)
{
    current_scp_procedure = scp_procedure;
    return SCP_RESULT_TRUE;
}

scp_result find_breakpoints_set()
{
    scp_operand arc1, arc2;
    scp_operand breakpoints_set;
    MAKE_DEFAULT_OPERAND_ASSIGN(breakpoints_set);
    MAKE_COMMON_ARC_ASSIGN(arc1);
    MAKE_DEFAULT_ARC_ASSIGN(arc2);

    scp_iterator5 *breakpoints_set_finder = scp_iterator5_new(s_default_ctx,
                                                             current_scp_procedure, &arc1, &breakpoints_set, &arc2, &nrel_breakpoints);

    if (SCP_RESULT_TRUE != scp_iterator5_next(s_default_ctx,
                                              breakpoints_set_finder, current_scp_procedure, &arc1, &breakpoints_set, &arc2, &nrel_breakpoints))
    {
        scp_iterator5_free(breakpoints_set_finder);
        return SCP_RESULT_FALSE;
    }

    current_breakpoints_set = breakpoints_set;
    return SCP_RESULT_TRUE;
}

scp_result is_procedure_operator_breakpoint(scp_operand *scp_operator)
{
    if (SCP_RESULT_TRUE != find_breakpoints_set())
    {
        return SCP_RESULT_FALSE;
    }

    scp_operand arc;
    MAKE_DEFAULT_ARC_ASSIGN(arc);

    current_breakpoints_set.param_type = SCP_FIXED;
    scp_operator->param_type = SCP_FIXED;

    scp_iterator3 *it = scp_iterator3_new(s_default_ctx, &current_breakpoints_set, &arc, scp_operator);
    if (SCP_RESULT_TRUE != scp_iterator3_next(s_default_ctx, it, &current_breakpoints_set, &arc, scp_operator))
    {
        return SCP_RESULT_FALSE;
    }

    scp_iterator3_free(it);
    return SCP_RESULT_TRUE;
}

scp_result is_process_operator_breakpoint(scp_operand *scp_operator)
{
//    scp_operand curr_scp_process, arc1;
//    MAKE_DEFAULT_ARC_ASSIGN(arc1);
//    MAKE_DEFAULT_OPERAND_ASSIGN(curr_scp_process);
//    scp_iterator3 *iter = scp_iterator3_new(s_default_ctx, &curr_scp_process, &arc1, scp_operator);
//    while (SCP_RESULT_TRUE == scp_iterator3_next(s_default_ctx, iter, &curr_scp_process, &arc1, scp_operator)) {
//        scp_operand arc2;
//        MAKE_DEFAULT_ARC_ASSIGN(arc2);
//        if (SCP_RESULT_TRUE == searchElStr3(s_default_ctx, &scp_process, &arc2, &curr_scp_process)) {
//            break;
//        }
//    }

//    printEl(s_default_ctx, &curr_scp_process);

//    MAKE_DEFAULT_ARC_ASSIGN(arc1);
//    if (SCP_RESULT_TRUE != searchElStr3(s_default_ctx, &scp_process, &arc1, &curr_scp_process))
//    {
//       return SCP_RESULT_FALSE;
//    }

//    MAKE_DEFAULT_ARC_ASSIGN(arc1);
//    if (SCP_RESULT_TRUE != searchElStr3(s_default_ctx, &scp_debug_executing_process, &arc1, &curr_scp_process))
//    {
//        return SCP_RESULT_FALSE;
//    }


    scp_operand arc, something;
    MAKE_DEFAULT_ARC_ASSIGN(arc);
    MAKE_DEFAULT_NODE_ASSIGN(something);
    breakpoint.param_type = SCP_FIXED;
    scp_operator->param_type = SCP_FIXED;
    scp_iterator3 *it = scp_iterator3_new(s_default_ctx, &breakpoint, &arc, scp_operator);
    if (SCP_RESULT_TRUE != scp_iterator3_next(s_default_ctx, it, &breakpoint, &arc, scp_operator))
    {
        return SCP_RESULT_FALSE;
    }
    return SCP_RESULT_TRUE;
}
