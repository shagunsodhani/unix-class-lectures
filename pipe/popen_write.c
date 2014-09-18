/*
 * =====================================================================================
 *
 *       Filename:  popen.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 18 September 2014 03:56:32  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shagun Sodhani (shagun), sshagunsodhani@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include<stdio.h>
#include<stdlib.h>

#define MAXLINE 100

int main(int argc, char **argv)
{
    size_t n;
    char buff [MAXLINE] , command [MAXLINE] ;
    FILE *fp;
    fgets (buff, MAXLINE, stdin) ;
    n = strlen(buff);
    if(buff[n - 1] == '\n')
        n-- ;
    fp = popen("cat " , "w");

    if (fp == NULL) 
    {
        printf("\nFailed command\n");
    }
    else
    {
        printf("\nSuccesss command\n");
    }

    fputc ( "popen.c\n\n", fp );

    while (fgets(buff, MAXLINE, fp) != NULL)
        fputs (buff , stdout) ;
    pclose (fp) ;
    exit (0) ;
}
