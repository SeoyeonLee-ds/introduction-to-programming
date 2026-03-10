#include<stdio.h>

int main() {
	// 분단위 주차시간, 주차일수, 주차시간, 주차요금
	// 각 값을 저장할 int형 변수 선언
	int time, days, min, fee;
	

	printf("주차시간 분단위 입력: ");
	//scanf_s를 이용해 총 주사치간을 분 단위로 입력
	scanf_s("%d", &time);


	// days, min, fee에 적합한 값 계산 후 대입
	days = (time / 1440);
	min = (time % 1440);
	fee = (days * 24000);

	// 조건문을 이용해 3~5에 해당하는 요금 계산
	if (min != 0){
	     if (min > 600) {
			fee += 24000;
	     }
		 else {
			 fee += 1200;
			 if (min > 30) {
				 fee += ((min - 30) / 15) * 600;
			 }
		 }
	}
	

	// printf를 이용한 주차요금 출력
	printf("주차요금은 %d 원 입니다.", fee);
	
	return 0;
}

