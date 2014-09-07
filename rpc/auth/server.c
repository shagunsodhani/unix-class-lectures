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
#include "rpc/rpc.h"
#include "rpc/auth.h"
#include "rpc/auth_unix.h"
#include "stdlib.h"
#include "math.h"

void display_shagun(struct svc_req *rqstp)
{
    printf("Program Number = %ld\n",rqstp->rq_prog);
    printf("Version Number = %ld\n", rqstp->rq_vers);
    printf("Procedure Number = %ld\n", rqstp->rq_proc);
    printf("Auth = %d\n", rqstp->rq_cred.oa_flavor);
}

bool_t squareproc_2_svc(square_in *inp, square_out out, struct svc_req *rqstp)
{

    display_shagun(rqstp);
    
    sleep(5);

    if(rqstp->rq_cred.oa_flavor == AUTH_SYS)
    {
        struct authsys_parms *au;
        au = (struct authsys_parms *) rqstp->rq_clntcred;
        printf("AUTH_SYS : host %s, uid %ld, gid %ld\n", au->aup_machname, (long) au->aup_uid, (long) au->aup_gid); 
    }
    printf("thread %d done\n", pthread_self());

    out.res1 = inp->arg1 * inp->arg1;
    return (TRUE);
}
