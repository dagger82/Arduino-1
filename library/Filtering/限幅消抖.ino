/*
A�����ƣ��޷������˲���
B��������
    �൱�ڡ��޷��˲�����+�������˲�������
    ���޷�����������
C���ŵ㣺
    �̳��ˡ��޷����͡����������ŵ㣻
    �Ľ��ˡ������˲������е�ĳЩȱ�ݣ����⽫����ֵ����ϵͳ��
D��ȱ�㣺
    ���ڿ��ٱ仯�Ĳ������ˡ�
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
 
// �޷������˲���
#define FILTER_A 1
#define FILTER_N 5
int i = 0;
int Filter() {
  int NewValue;
  int new_value;
  NewValue = Get_AD();
  if(((NewValue - Value) > FILTER_A) || ((Value - NewValue) > FILTER_A))
    new_value = Value;
  else
    new_value = NewValue;
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

