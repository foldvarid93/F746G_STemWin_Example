  /**
  ******************************************************************************
  * @file    GUI_App.c
  * @author  MCD Application Team
  * @brief   Simple demo drawing "Hello world"  
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright © 2018 STMicroelectronics International N.V. 
  * All rights reserved.</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
#include "GUI_App.h"
#include "GUI.h"

#include "DIALOG.h"
extern  WM_HWIN CreateWindow(void);  
extern GRAPH_DATA_Handle PhaseDataA;
extern GRAPH_DATA_Handle PhaseDataB;
extern GRAPH_DATA_Handle PhaseDataC;
void GRAPHICS_MainTask(void) {
	CreateWindow();
	int AngleA=0;
	int AngleB=0x555;
	int AngleC=0xAAA;
	while(1) {
		int NewPhaseDataA =GUI_sin(AngleA)/10;
		int NewPhaseDataB =GUI_sin(AngleB)/10;
		int NewPhaseDataC =GUI_sin(AngleC)/10;
		AngleA+=10;
		AngleB+=10;
		AngleC+=10;
		if(AngleA==0xfff){
			AngleA=0;
			AngleB=0x555;
			AngleC=0xAAA;
		}
		GRAPH_DATA_YT_AddValue(PhaseDataA, NewPhaseDataA+131);
		GRAPH_DATA_YT_AddValue(PhaseDataB, NewPhaseDataB+131);
		GRAPH_DATA_YT_AddValue(PhaseDataC, NewPhaseDataC+131);
		GUI_Exec();
		GUI_Delay(10);
	}
}

/*************************** End of file ****************************/
