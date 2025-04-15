#include <stdio.h>
#include <math.h>
#define M_PI 3.141592
int main() {
    // �־��� ��
    double v0 = 100.0;             // �ʱ� �ӵ� (m/s)
    double theta_deg = 37.0;       // �߻� ���� (��)
    double theta_rad = theta_deg * M_PI / 180.0; // ���� ������ ��ȯ
    double h = 140.0;              // ���� ���� (m)
    double g = 9.8;                // �߷°��ӵ� (m/s^2)

    // �ʱ� �ӵ��� ����, ���� ����
    double v0x = v0 * cos(theta_rad);
    double v0y = v0 * sin(theta_rad);

    // (a) ���� �ð� ���: 2�� ������ �ع� ���
    double a = -0.5 * g;
    double b = v0y;
    double c = h;

    double discriminant = b * b - 4 * a * c;

    double t;
    if (discriminant < 0) {
        printf("�ذ� �����ϴ� (�ð� ��� ����).\n");
        return 1;
    }
    else {
        t = (-b + sqrt(discriminant)) / (2 * a);  // ���� �� ���
    }

    // (b) ���� �Ÿ� ���
    double x = v0x * t;

    // (c) ���� ���� �ӵ� ����
    double vx_final = v0x;
    double vy_final = v0y - g * t;

    // (d) �ӵ� ũ�� ���
    double v_final = sqrt(vx_final * vx_final + vy_final * vy_final);

    // (e) �ӵ� ���Ͱ� �̷�� ����
    double angle_final_rad = atan2(fabs(vy_final), vx_final);
    double angle_final_deg = angle_final_rad * 180.0 / M_PI;

    // ��� ���
    printf("(a) ���� �ð�: %.2f��\n", t);
    printf("(b) ���� �Ÿ� X: %.2f m\n", x);
    printf("(c) ���� �ӵ� ����: Vx = %.2f m/s, Vy = %.2f m/s\n", vx_final, vy_final);
    printf("(d) �ӵ� ũ��: %.2f m/s\n", v_final);
    printf("(e) �ӵ� ���� ����: %.2f��\n", angle_final_deg);

    return 0;
}
