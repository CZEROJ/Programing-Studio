#include <stdio.h>

int main() {
  int height, weight; // 신장(cm), 체중(kg)
  float bmi;
  int people;
  int count = 0;

  scanf("%d", &people);

  for (int i = 0; i < people; i++) {
    scanf("%d", &height);
    scanf("%d", &weight);

    bmi = weight / ((height * height) * 0.0001);

    if (bmi >= 25.0) {
      count++;
    }
  }

  printf("%d", count);

  return 0;
}