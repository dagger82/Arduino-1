/*
A�����ƣ���λֵ�˲���
B��������
    ��������N�Σ�Nȡ����������N�β���ֵ����С���У�
    ȡ�м�ֵΪ������Чֵ��
C���ŵ㣺
    ����Ч�˷���żȻ��������Ĳ������ţ�
    ���¶ȡ�Һλ�ı仯�����ı�����������õ��˲�Ч����
D��ȱ�㣺
    ���������ٶȵȿ��ٱ仯�Ĳ������ˡ�
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
 
// ��λֵ�˲���
#define FILTER_N 101
int Filter() {
  int filter_buf[FILTER_N];
  int i, j;
  int filter_temp;
  for(i = 0; i < FILTER_N; i++) {
    filter_buf[i] = Get_AD();
    delay(1);
  }
  // ����ֵ��С�������У�ð�ݷ���
  for(j = 0; j < FILTER_N - 1; j++) {
    for(i = 0; i < FILTER_N - 1 - j; i++) {
      if(filter_buf[i] > filter_buf[i + 1]) {
        filter_temp = filter_buf[i];
        filter_buf[i] = filter_buf[i + 1];
        filter_buf[i + 1] = filter_temp;
      }
    }
  }
  return filter_buf[(FILTER_N - 1) / 2];
}

