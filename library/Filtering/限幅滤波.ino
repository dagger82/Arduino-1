/*
A�����ƣ��޷��˲������ֳƳ����ж��˲�����
B��������
    ���ݾ����жϣ�ȷ�����β�����������ƫ��ֵ����ΪA����
    ÿ�μ�⵽��ֵʱ�жϣ�
    �������ֵ���ϴ�ֵ֮��<=A���򱾴�ֵ��Ч��
    �������ֵ���ϴ�ֵ֮��>A���򱾴�ֵ��Ч����������ֵ�����ϴ�ֵ���汾��ֵ��
C���ŵ㣺
    ����Ч�˷���żȻ���������������š�
D��ȱ�㣺
    �޷��������������Եĸ��š�
    ƽ���Ȳ
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
  Value = Filter_Value;          // ���һ����Ч������ֵ���ñ���Ϊȫ�ֱ���
  Serial.println(Filter_Value); // �������
  delay(50);
}
 
// �����������һ��300���ҵĵ�ǰֵ
int Get_AD() {
  return random(295, 305);
}
 
// �޷��˲������ֳƳ����ж��˲�����
#define FILTER_A 1
int Filter() {
  int NewValue;
  NewValue = Get_AD();
  if(((NewValue - Value) > FILTER_A) || ((Value - NewValue) > FILTER_A))
    return Value;
  else
    return NewValue;
}

