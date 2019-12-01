/*******************************************************************************
Copyright:      Bupt
File name:      karman.c
Description:    �������˲�����
Author:         Leo
Version��       1.0
Data:           2019/11/24
History:        ��
Bug:            ��
*******************************************************************************/
#include "karman.h"

Kal_Struct kal_distance_L={1,0,0.01,37.1160,0,1};
Kal_Struct kal_distance_R={1,0,0.01,37.1160,0,1};

Kal_Struct kal_adc_L={1,0,0.01,37.1160,0,1};
Kal_Struct kal_adc_R={1,0,0.01,37.1160,0,1};


float KalMan(Kal_Struct *kal,float x){
  
  float kalman_pre;  //��������Ԥ��ֵ
  float cov_pre;  //������Ԥ��ֵ��Э����
  float kg;//����
  
  kalman_pre=kal->kal_out*kal->A;  //���㱾�ο�������Ԥ��ֵ
  
  cov_pre=kal->cov*kal->A*kal->A+kal->Q;
  
  kg=cov_pre/(cov_pre+kal->R);   //���㱾�εĿ���������
  
  kal->kal_out=kalman_pre+kg*(x-kalman_pre);   //ͨ��Ԥ��ֵ�����㱾�ο������˲�������
  
  kal->cov=(1-kg)*cov_pre;
  
  return kal->kal_out;
}


