/*
A�����ƣ�����ƽ���˲������ֳƻ���ƽ���˲�����
B��������
    ������ȡ�õ�N������ֵ����һ�����У����еĳ��ȹ̶�ΪN��
    ÿ�β�����һ�������ݷ����β�����ӵ�ԭ�����׵�һ�����ݣ��Ƚ��ȳ�ԭ�򣩣�
    �Ѷ����е�N�����ݽ�������ƽ�����㣬����µ��˲������
    Nֵ��ѡȡ��������N=12��ѹ����N=4��Һ�棬N=4-12���¶ȣ�N=1-4��
C���ŵ㣺
    �������Ը��������õ��������ã�ƽ���ȸߣ�
    �����ڸ�Ƶ�񵴵�ϵͳ��
D��ȱ�㣺
    �����ȵͣ���żȻ���ֵ������Ը��ŵ��������ýϲ
    �������������������������Ĳ���ֵƫ�
    ��������������űȽ����صĳ��ϣ�
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
 
// ����ƽ���˲������ֳƻ���ƽ���˲�����
#define FILTER_N 12
int filter_buf[FILTER_N + 1];
int Filter() {
  int i;
  int filter_sum = 0;
  filter_buf[FILTER_N] = Get_AD();
  for(i = 0; i < FILTER_N; i++) {
    filter_buf[i] = filter_buf[i + 1]; // �����������ƣ���λ�Ե�
    filter_sum += filter_buf[i];
  }
  return (int)(filter_sum / FILTER_N);
}

