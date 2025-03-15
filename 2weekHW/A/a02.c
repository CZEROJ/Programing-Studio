#include <stdio.h>

int main() {
  int height, weight; // 신장(cm), 체중(kg)
  float bmi;

  scanf("%d", &height);
  scanf("%d", &weight);

  bmi = weight / ((height * height) * 0.0001);

  printf("%.1f", bmi);

  if (bmi >= 25.0) {
    printf(" Overweight");
  } else {
    printf(" Normal");
  }
  return 0;
}