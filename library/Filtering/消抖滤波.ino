/*
A�����ƣ������˲���
B��������
    ����һ���˲�����������ÿ�β���ֵ�뵱ǰ��Чֵ�Ƚϣ�
    �������ֵ=��ǰ��Чֵ������������㣻
    �������ֵ<>��ǰ��Чֵ���������+1�����жϼ������Ƿ�>=����N���������
    ���������������򽫱���ֵ�滻��ǰ��Чֵ�������������
C���ŵ㣺
    ���ڱ仯�����ı�������нϺõ��˲�Ч����
    �ɱ������ٽ�ֵ�����������ķ�����/����������ʾ������ֵ������
D��ȱ�㣺
    ���ڿ��ٱ仯�Ĳ������ˣ�
    ����ڼ������������һ�β�������ֵǡ���Ǹ���ֵ,��Ὣ����ֵ������Чֵ����ϵͳ��
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
 
// �����˲���
#define FILTER_N 12
int i = 0;
int Filter() {
  int new_value;
  new_value = Get_AD();
  if(Value != new_value) {
    i++;
    if(i > FILTER_N) {
      i = 0;
      Value = new_value;
    }
  }
  else
    i = 0;
  return Value;
}

