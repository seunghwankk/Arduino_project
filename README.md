# Arduino_project

## 제습기 스위치 제어 With Arduino

### 아두이노를 활용한 제습기(Servo Motor) 자동제어
- 아두이노에서 DHT11을 사용하여 온도, 습도 측정
- 아두이노 간 Serial통신을 통해 온도, 습도 값 송수신
- LCD를 연결하여 수신받은 데이터 출력
- 습도 수치 변화에 따른 Servo Motor 제어(세기 조절)
- 스위치를 활용하여 인터럽트 구현

### 회로도
 ![image](https://user-images.githubusercontent.com/126065290/236662837-6f4eb3db-6bc2-48e4-a7f7-980b68d76e9a.png)

### 결과

습도가 낮을 때

![image](https://user-images.githubusercontent.com/126065290/236662911-db1c7d19-d020-4481-8898-9fdf939cce39.png)

습도가 높을 때

![image](https://user-images.githubusercontent.com/126065290/236662943-645c5198-9970-46df-9709-b9033c855582.png)

스위치 눌렀을 때(인터럽트)

![image](https://user-images.githubusercontent.com/126065290/236662954-835ef9c2-ff35-4b8a-b7cb-519f7df72aab.png)
