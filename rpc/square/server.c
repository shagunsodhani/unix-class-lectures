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
square_out * squareproc_1_svc(square_in *inp, struct svc_req *rqstp)
{
    static square_out out;
    
    sleep(5);
    printf("thread %d done\n", pthread_self());

    out.res1 = inp->arg1 * inp->arg1;
    return (&out);
}
