/*
A�����ƣ��޷�ƽ���˲���
B��������
    �൱�ڡ��޷��˲�����+������ƽ���˲�������
    ÿ�β��������������Ƚ����޷�����
    ��������н��е���ƽ���˲�����
C���ŵ㣺
    �ں��������˲������ŵ㣻
    ����żȻ���ֵ������Ը��ţ������������������������Ĳ���ֵƫ�
D��ȱ�㣺
    �Ƚ��˷�RAM��
E������shenhaiyu 2013-11-01
*/
 
#define FILTER_N 12
int Filter_Value;
int filter_buf[FILTER_N];
 
void setup() {
  Serial.begin(9600);       // ��ʼ������ͨ��
  randomSeed(analogRead(0)); // �����������
  filter_buf[FILTER_N - 2] = 300;
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
 
// �޷�ƽ���˲���
#define FILTER_A 1
int Filter() {
  int i;
  int filter_sum = 0;
  filter_buf[FILTER_N - 1] = Get_AD();
  if(((filter_buf[FILTER_N - 1] - filter_buf[FILTER_N - 2]) > FILTER_A) || ((filter_buf[FILTER_N - 2] - filter_buf[FILTER_N - 1]) > FILTER_A))
    filter_buf[FILTER_N - 1] = filter_buf[FILTER_N - 2];
  for(i = 0; i < FILTER_N - 1; i++) {
    filter_buf[i] = filter_buf[i + 1];
    filter_sum += filter_buf[i];
  }
  return (int)filter_sum / (FILTER_N - 1);
}

