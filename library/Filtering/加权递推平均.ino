/*
A�����ƣ���Ȩ����ƽ���˲���
B��������
    �ǶԵ���ƽ���˲����ĸĽ�������ͬʱ�̵����ݼ��Բ�ͬ��Ȩ��
    ͨ���ǣ�Խ�ӽ���ʱ�̵����ݣ�Ȩȡ��Խ��
    �����²���ֵ��Ȩϵ��Խ����������Խ�ߣ����ź�ƽ����Խ�͡�
C���ŵ㣺
    �������нϴ��ͺ�ʱ�䳣���Ķ��󣬺Ͳ������ڽ϶̵�ϵͳ��
D��ȱ�㣺
    ���ڴ��ͺ�ʱ�䳣����С���������ڽϳ����仯�������źţ�
    ����Ѹ�ٷ�Ӧϵͳ��ǰ���ܸ��ŵ����س̶ȣ��˲�Ч���
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
 
// ��Ȩ����ƽ���˲���
#define FILTER_N 12
int coe[FILTER_N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};    // ��Ȩϵ����
int sum_coe = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 + 11 + 12; // ��Ȩϵ����
int filter_buf[FILTER_N + 1];
int Filter() {
  int i;
  int filter_sum = 0;
  filter_buf[FILTER_N] = Get_AD();
  for(i = 0; i < FILTER_N; i++) {
    filter_buf[i] = filter_buf[i + 1]; // �����������ƣ���λ�Ե�
    filter_sum += filter_buf[i] * coe[i];
  }
  filter_sum /= sum_coe;
  return filter_sum;
}

