/*
A�����ƣ�����ƽ���˲���
B��������
    ����ȡN������ֵ��������ƽ�����㣺
    Nֵ�ϴ�ʱ���ź�ƽ���Ƚϸߣ��������Ƚϵͣ�
    Nֵ��Сʱ���ź�ƽ���Ƚϵͣ��������Ƚϸߣ�
    Nֵ��ѡȡ��һ��������N=12��ѹ����N=4��
C���ŵ㣺
    �����ڶ�һ�����������ŵ��źŽ����˲���
    �����źŵ��ص�����һ��ƽ��ֵ���ź���ĳһ��ֵ��Χ�������²�����
D��ȱ�㣺
    ���ڲ����ٶȽ�����Ҫ�����ݼ����ٶȽϿ��ʵʱ���Ʋ����ã�
    �Ƚ��˷�RAM��
E������shenhaiyu 2013-11-01
*/
 
int Filter_Value;
 
void setup() {
  Serial.begin(9600);       // ��ʼ������ͨ��
  randomSeed(analogRead(0)); // �����������
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
 
// ����ƽ���˲���
#define FILTER_N 12
int Filter() {
  int i;
  int filter_sum = 0;
  for(i = 0; i < FILTER_N; i++) {
    filter_sum += Get_AD();
    delay(1);
  }
  return (int)(filter_sum / FILTER_N);
}

