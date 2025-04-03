#include <stdio.h>
#include <math.h>

#define M_PI 3.141592

int main() {
    double angle_degree, x, y, r, theta_radian;


    printf("각도를 입력하세요 (degree): ");
    scanf_s("%lf", &angle_degree);


    double angle_radian = angle_degree * M_PI / 180;
    printf("angle_radian: %f\n", angle_radian);

   
    printf("cos(%f): %f\n", angle_radian, cos(angle_radian));
    printf("sin(%f): %f\n", angle_radian, sin(angle_radian));
    printf("tan(%f): %f\n", angle_radian, tan(angle_radian));

    printf("x와 y 좌표를 입력하세요 (공백으로 구분): ");
    scanf_s("%lf %lf", &x, &y);

   
    r = sqrt(x * x + y * y);
    theta_radian = atan2(y, x);
    printf("극좌표: r = %f, theta = %f\n", r, theta_radian);


    printf("극좌표 변환을 위한 반지름을 입력하세요: ");
    scanf_s("%lf", &r);

 
    double x_new = r * cos(angle_radian);
    double y_new = r * sin(angle_radian);
    printf("직교 좌표: x = %f, y = %f\n", x_new, y_new);

    return 0;
}