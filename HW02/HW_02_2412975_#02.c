#include <stdio.h>

int main()
{
	int menu = 0;
	float celsius;
	int fahr;

	printf("[화씨-섭씨 변환 프로그램]\n");
	printf("Menu 1) 화씨 --> 섭씨\n");
	printf("Menu 2) 섭씨 --> 화씨\n");
	printf("Menu 3) 프로그램 종료\n\n");

	// 온도 변환 프로그램은 사용자가 입력한 메뉴가 3인 경우에만 종료
	// 3이 아닌 숫자를 입력하면 계속해서 동작
	while (menu != 3)
	{
		//사용자가 입력한 숫자를 변수에 저장
		printf("menu를 선택하세요) ");
		scanf_s("%d", &menu);


		//입력한 숫자에 따라 2~5번의 내용을 실행
		if (menu == 1) {
			printf("화씨 온도 입력: ");
			scanf_s("%d", &fahr);
			celsius = (fahr - 32) * 5 / 9;
			printf("%d °F는 %.6f °C 입니다. \n\n", fahr, celsius);
		}
		else if (menu == 2) {
			printf("섭씨 온도 입력: ");
			scanf_s("%f", &celsius);
			fahr = celsius * 9 / 5 + 32;
			printf("%.6f °C는 %d °F 입니다. \n\n", celsius, fahr);
		}
		else if (menu == 3) {
			printf("프로그램을 종료합니다.");
			break;
		}
		else {
			printf("올바른 번호를 입력하세요. \n\n");
		}
	}
}