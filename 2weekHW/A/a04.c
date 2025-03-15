#include <stdio.h>

int main() {
  int height[10], weight[10]; // 10명의 신장(cm), 체중(kg)
  float bmi[10];              // 10명의 비만도 수치
  int count = 0;

  for (int i = 0; i < 10; i++) {
    scanf("%d", &height[i]);
    scanf("%d", &weight[i]);
  }

  for (int i = 0; i < 10; i++) {
    bmi[i] = weight[i] / ((height[i] * height[i]) * 0.0001);
    if (bmi[i] >= 25.0) {
      count++;
      printf("%d ", i + 1);
    }
  }

  printf("\n");
  printf("%d", count);

  return 0;
}