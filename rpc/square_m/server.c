/*
 * =====================================================================================
 *
 *       Filename:  server.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Saturday 06 September 2014 11:02:35  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shagun Sodhani (shagun), sshagunsodhani@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "square.h"
#include "stdio.h"
#include"rpc/rpc.h"
#include"stdlib.h"
#include"math.h"

bool_t squareproc_2_svc(square_in *inp, square_out *outp, struct svc_req *rqstp)
{
    sleep(5);
    printf("thread %d done\n", pthread_self());

    outp->res1 = inp->arg1 * inp->arg1;
    return (TRUE);
}

int square_prog_2_freeresult(SVCXPRT *transp, xdrproc_t xdr_result, caddr_t result)
{
    xdr_free(xdr_result, result);
    return 1;
}
