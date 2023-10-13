#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI M_PI

typedef struct {
    double x;
    double y;
} Point;

int main() {
    int n;
    int semicircle = 1;
    scanf("%d", &n);
    Point *points = (Point *)malloc(n * sizeof(Point));

    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
        // 计算点的极坐标角度 atan2() 是已知一个角的正切值（也就是 y/x）
        double angle = atan2(points[i].y, points[i].x);//由于atan2传递的参数是倒置的，所以需要(y,x)这样的写法
        // 角度在 -pi/2 到 pi/2 之间为半圆范围
        if (angle < -PI/2.0 || angle > PI/2.0) {
            semicircle = 0;
            break;
        }
    }
    //用1和0来分辨是否是半圆
    if (semicircle) {
        printf("HCP\n");
    } else {
        printf("NO HCP\n");
    }

    free(points);

    return 0;
}
