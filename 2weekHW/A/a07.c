#include <stdio.h>

int main() {
  int height[10], weight[10]; // 10명의 신장(cm), 체중(kg)
  float bmi[10];              // 10명의 비만도 수치
  int count = 0;
  int people;

  scanf("%d", &people);

  for (int i = 0; i < people; i++) {
    scanf("%d", &height[i]);
    scanf("%d", &weight[i]);
  }

  for (int i = 0; i < people; i++) {
    int result = bmiLevel(height[i], weight[i]);
    if (result >= 3) {
      count++;
    }
  }
  printf("%d/%d", count, people);

  return 0;
}

int bmiLevel(int height, int weight) {
  int bmi;
  bmi = weight / ((height * height) * 0.0001);

  if (bmi >= 30.0) {
    return 4;
  } else if (bmi >= 25.0) {
    return 3;
  } else if (bmi >= 23.0) {
    return 2;
  } else if (bmi >= 18.5) {
    return 1;
  } else {
    return 0;
  }
}