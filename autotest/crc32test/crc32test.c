#include "stdio.h"
#include "crc32.h"

unsigned char g_buffer[0x100000];

int main(int argc, char *argv[])
{
    FILE  *fp;
    int    len = 0;
    int    totallen = 0;
    unsigned int crc = 0;

    fp = fopen(argv[1], "r");
    if (NULL == fp)
    {
        printf("open file fail \n");
        return -1;
    }

    while (!feof(fp))
    {
        len = fread(g_buffer, 1, sizeof(g_buffer), fp);

        crc = calc_crc32(crc, g_buffer, len);

        totallen += len;
    }

    printf("crc32=0x%08x totallen=%d \n", crc, totallen);
    
    fclose(fp);
}
