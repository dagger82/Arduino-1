/*
A�����ƣ���λֵƽ���˲������ֳƷ��������ƽ���˲�����
B��������
    ��һ�����ȥ�����ֵ����Сֵ��ȡƽ��ֵ��
    �൱�ڡ���λֵ�˲�����+������ƽ���˲�������
    ��������N�����ݣ�ȥ��һ�����ֵ��һ����Сֵ��
    Ȼ�����N-2�����ݵ�����ƽ��ֵ��
    Nֵ��ѡȡ��3-14��
C���ŵ㣺
    �ں��ˡ���λֵ�˲�����+������ƽ���˲����������˲������ŵ㡣
    ����żȻ���ֵ������Ը��ţ�����������������Ĳ���ֵƫ�
    �����ڸ��������õ��������á�
    ƽ���ȸߣ����ڸ�Ƶ�񵴵�ϵͳ��
D��ȱ�㣺
    �����ٶȽ�����������ƽ���˲���һ����
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
 
// ��λֵƽ���˲������ֳƷ��������ƽ���˲��������㷨1��
#define FILTER_N 100
int Filter() {
  int i, j;
  int filter_temp, filter_sum = 0;
  int filter_buf[FILTER_N];
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
  // ȥ�������С��ֵ����ƽ��
  for(i = 1; i < FILTER_N - 1; i++) filter_sum += filter_buf[i];
  return filter_sum / (FILTER_N - 2);
}
 
 
//  ��λֵƽ���˲������ֳƷ��������ƽ���˲��������㷨2��
/*
#define FILTER_N 100
int Filter() {
  int i;
  int filter_sum = 0;
  int filter_max, filter_min;
  int filter_buf[FILTER_N];
  for(i = 0; i < FILTER_N; i++) {
    filter_buf[i] = Get_AD();
    delay(1);
  }
  filter_max = filter_buf[0];
  filter_min = filter_buf[0];
  filter_sum = filter_buf[0];
  for(i = FILTER_N - 1; i > 0; i--) {
    if(filter_buf[i] > filter_max)
      filter_max=filter_buf[i];
    else if(filter_buf[i] < filter_min)
      filter_min=filter_buf[i];
    filter_sum = filter_sum + filter_buf[i];
    filter_buf[i] = filter_buf[i - 1];
  }
  i = FILTER_N - 2;
  filter_sum = filter_sum - filter_max - filter_min + i / 2; // +i/2 ��Ŀ����Ϊ����������
  filter_sum = filter_sum / i;
  return filter_sum;
}*/

