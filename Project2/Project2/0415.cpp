#include <stdio.h>
#include <math.h>
#define M_PI 3.141592
int main() {
    // 주어진 값
    double v0 = 100.0;             // 초기 속도 (m/s)
    double theta_deg = 37.0;       // 발사 각도 (도)
    double theta_rad = theta_deg * M_PI / 180.0; // 라디안 단위로 변환
    double h = 140.0;              // 절벽 높이 (m)
    double g = 9.8;                // 중력가속도 (m/s^2)

    // 초기 속도의 수평, 수직 성분
    double v0x = v0 * cos(theta_rad);
    double v0y = v0 * sin(theta_rad);

    // (a) 낙하 시간 계산: 2차 방정식 해법 사용
    double a = -0.5 * g;
    double b = v0y;
    double c = h;

    double discriminant = b * b - 4 * a * c;

    double t;
    if (discriminant < 0) {
        printf("해가 없습니다 (시간 계산 오류).\n");
        return 1;
    }
    else {
        t = (-b + sqrt(discriminant)) / (2 * a);  // 양의 해 사용
    }

    // (b) 수평 거리 계산
    double x = v0x * t;

    // (c) 낙하 직전 속도 성분
    double vx_final = v0x;
    double vy_final = v0y - g * t;

    // (d) 속도 크기 계산
    double v_final = sqrt(vx_final * vx_final + vy_final * vy_final);

    // (e) 속도 벡터가 이루는 각도
    double angle_final_rad = atan2(fabs(vy_final), vx_final);
    double angle_final_deg = angle_final_rad * 180.0 / M_PI;

    // 결과 출력
    printf("(a) 낙하 시간: %.2f초\n", t);
    printf("(b) 수평 거리 X: %.2f m\n", x);
    printf("(c) 최종 속도 성분: Vx = %.2f m/s, Vy = %.2f m/s\n", vx_final, vy_final);
    printf("(d) 속도 크기: %.2f m/s\n", v_final);
    printf("(e) 속도 벡터 각도: %.2f도\n", angle_final_deg);

    return 0;
}
