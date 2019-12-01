#ifndef __karman_H
#define __karman_H

/*Struct Area*/
typedef struct _kal_struct{
  float A;                      //һ��Ϊ1
  float B;                      //һ��Ϊ0
  float Q;                      //ϵͳ����������Э����
  float R;                      //����������Э����	
  float kal_out;               //��һ�ο����������	
  float cov;                   //��һ�ο������������Э����	
}Kal_Struct;

/*Variable Area*/
extern Kal_Struct kal_distance_L;
extern Kal_Struct kal_distance_R;
extern Kal_Struct kal_adc_L;
extern Kal_Struct kal_adc_R;

/*Function Area*/
float KalMan(Kal_Struct *kal,float x);

#endif