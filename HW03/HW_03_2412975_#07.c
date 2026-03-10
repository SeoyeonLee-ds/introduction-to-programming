#include<stdio.h>
//포인터를 이용한 값 반환을 이용해 코드를 작성하세요.

int get_line(int x1, int y1, int x2, int y2, float* slope, float* y_intercept);


int main()
{
	int a, b, c, d;

	printf("두 점의 좌표 입력: \n");
	scanf_s("%d, %d\n%d, %d", &a, &b, &c, &d);

	float s, y;

	//두 좌표의 x 좌표 값이 같을 때, 기울기를 구할 수 없음
	//get_line 함수의 반환값이 -1일때 '에러 발생'출력
	//get_line 함수의 반환값이 -1이 아닐때 기울기와 y절편 출력
	if (get_line(a, b, c, d, &s, &y) == -1) {
		printf("에러발생");
	}
	else {
		printf("기울기: %.2f, y절편: %.2f", s, y);
	}
	return 0;
}


int get_line(int x1, int y1, int x2, int y2, float* slope, float* y_intercept)
{
	if (x1 == x2) {
		return -1;
	}
	*slope = (float)(y2 - y1) / (x2 - x1);
	*y_intercept = y1 - (*slope) * x1;
}
