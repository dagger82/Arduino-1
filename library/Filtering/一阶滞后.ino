/*
A�����ƣ�һ���ͺ��˲���
B��������
    ȡa=0-1�������˲����=(1-a)*���β���ֵ+a*�ϴ��˲������
C���ŵ㣺
    �������Ը��ž������õ��������ã�
    �����ڲ���Ƶ�ʽϸߵĳ��ϡ�
D��ȱ�㣺
    ��λ�ͺ������ȵͣ�
    �ͺ�̶�ȡ����aֵ��С��
    ���������˲�Ƶ�ʸ��ڲ���Ƶ��1/2�ĸ����źš�
E������shenhaiyu 2013-11-01
*/
 
int Filter_Value;
int Value;
 
void setup() {
  Serial.begin(9600);       // ��ʼ������ͨ��
  randomSeed(analogRead(0)); // �����������
  Value = 300;
}
 
void loop() {
  Filter_Value = Filter();       // ����˲������ֵ
  Serial.println(Filter_Value); // �������
  delay(50);
}
 
// �����������һ��300���ҵĵ�ǰֵ
int Get_AD() {
  return random(295, 305);
}
 
// һ���ͺ��˲���
#define FILTER_A 0.01
int Filter() {
  int NewValue;
  NewValue = Get_AD();
  Value = (int)((float)NewValue * FILTER_A + (1.0 - FILTER_A) * (float)Value);
  return Value;
}

