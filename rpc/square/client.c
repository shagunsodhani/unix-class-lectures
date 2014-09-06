/*
 * =====================================================================================
 *
 *       Filename:  client.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Saturday 06 September 2014 10:58:06  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shagun Sodhani (shagun), sshagunsodhani@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "square.h"

int main(int argc, char **argv)
{

    CLIENT *cl;
    square_in inp;
    square_out *outp;
    cl = clnt_create(argv[1], SQUARE_PROG, SQUARE_VERS, "tcp");
    inp.arg1 = atol(argv[2]);
    if ( (outp = squareproc_1(&inp, cl)) == NULL)
        printf("%sU", clnt_sperror(cl, argv[1]));
    printf("resu1t: %ld\n", outp->res1);
    exit (0) ;
}
