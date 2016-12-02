#include "stdio.h"

static unsigned int crc_table[256];  

/*  
 *初始化crc表,生成32位大小的crc表  
 *也可以直接定义出crc表,直接查表,  
 *但总共有256个,看着眼花,用生成的比较方便.  
 */  
static void init_crc_table(void)  
{  
    unsigned int c;  
    unsigned int i, j;  
      
    for (i = 0; i < 256; i++) {  
        c = (unsigned int)i;  
        for (j = 0; j < 8; j++) {  
            if (c & 1)  
                c = 0xedb88320L ^ (c >> 1);  
            else  
                c = c >> 1;  
        }  
        crc_table[i] = c;  
    }  
}

/*计算buffer的crc校验码*/  
unsigned int calc_crc32(unsigned int crc,unsigned char *buffer, unsigned int size)  
{  
    unsigned int  i;
    unsigned char init = 0;

    if (0 == init)
    {
        init_crc_table();
        init = 1;
    }
    
    for (i = 0; i < size; i++) {  
        crc = crc_table[(crc ^ buffer[i]) & 0xff] ^ (crc >> 8);  
    }  
    return crc ;  
}

