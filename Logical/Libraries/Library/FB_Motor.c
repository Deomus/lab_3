
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FB_Motor(struct FB_Motor* inst)
{
	inst->integrator.in = (inst->in/inst->k_e - inst->out_w) * (inst->dt/inst->T_m);
	FB_Integrator(&inst->integrator);
	inst->out_w = inst->integrator.out;
	inst->integrator.in = inst->out_w * inst->dt;
	FB_Integrator(&inst->integrator);
	inst->out_phi = inst->integrator.out;
}
