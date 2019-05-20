//////////////////////////////////////////////////////////////////////////////
// * File name: aic3204_test.c
// *                                                                          
// * Description:  AIC3204 Test common functions.
// *                                                                          
// * Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/ 
// * Copyright (C) 2011 Spectrum Digital, Incorporated
// *                                                                          
// *                                                                          
// *  Redistribution and use in source and binary forms, with or without      
// *  modification, are permitted provided that the following conditions      
// *  are met:                                                                
// *                                                                          
// *    Redistributions of source code must retain the above copyright        
// *    notice, this list of conditions and the following disclaimer.         
// *                                                                          
// *    Redistributions in binary form must reproduce the above copyright     
// *    notice, this list of conditions and the following disclaimer in the   
// *    documentation and/or other materials provided with the                
// *    distribution.                                                         
// *                                                                          
// *    Neither the name of Texas Instruments Incorporated nor the names of   
// *    its contributors may be used to endorse or promote products derived   
// *    from this software without specific prior written permission.         
// *                                                                          
// *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS     
// *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT       
// *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR   
// *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT    
// *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,   
// *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT        
// *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,   
// *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY   
// *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT     
// *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE   
// *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.    
// *                                                                          
//////////////////////////////////////////////////////////////////////////////

#define AIC3204_I2C_ADDR 0x18
#include "ezdsp5502.h"
#include "ezdsp5502_i2c.h"
#include "ezdsp5502_i2cgpio.h"
#include "stdio.h"

extern Int16 aic3204_tone_headphone( );
extern Int16 aic3204_loop_linein( );

/*
 *
 *  AIC3204_rget( regnum, *regval )
 *
 *      Return value of codec register regnum
 *
 */
Int16 AIC3204_rget(  Uint16 regnum, Uint16* regval )
{
    Int16  retcode = 0;
    Uint16 cmd[2];

    cmd[0] = regnum & 0x007F;       // 7-bit Device Register
    cmd[1] = 0;

    /* Send AIC3204 register name */
    retcode |= EZDSP5502_I2C_write( AIC3204_I2C_ADDR, cmd, 1 );
    
    /* Return AIC3204 register value */
    retcode |= EZDSP5502_I2C_read( AIC3204_I2C_ADDR, cmd, 1 );
    *regval = cmd[0];
    EZDSP5502_waitusec( 50 );
    
    return retcode;
}

/*
 *
 *  AIC3204_rset( regnum, regval )
 *
 *      Set codec register regnum to value regval
 *
 */
Int16 AIC3204_rset( Uint16 regnum, Uint16 regval )
{
    Uint16 cmd[2];
    cmd[0] = regnum & 0x007F;       // 7-bit Device Register
    cmd[1] = regval;                // 8-bit Register Data

    EZDSP5502_waitusec( 100 );

    /* Write to AIC3204 Register */
    return EZDSP5502_I2C_write( AIC3204_I2C_ADDR, cmd, 2 );
}

/*
 * 
 *  aic3204_test( )
 *
 *      Test different configurations of the AIC3204
 */
Int16 aic3204_test( )
{
    /* Set to McBSP1 mode */
    EZDSP5502_I2CGPIO_configLine( BSP_SEL1, OUT );
    EZDSP5502_I2CGPIO_writeLine(  BSP_SEL1, LOW );
    
    /* Enable McBSP1 */
    EZDSP5502_I2CGPIO_configLine( BSP_SEL1_ENn, OUT );
    EZDSP5502_I2CGPIO_writeLine(  BSP_SEL1_ENn, LOW );

    /* Codec tests */
    /*printf( " -> 1 KHz Tone on Headphone.\n" );
    if ( aic3204_tone_headphone( ) )           // Output test
        return 1;*/
        
    EZDSP5502_wait( 100 );  // Wait    
    printf( "<-> Audio Loopback from Stereo IN --> to HP OUT\n" );
    if ( aic3204_loop_linein( ) )              // Loop test
        return 3;
        
    return 0;
}
