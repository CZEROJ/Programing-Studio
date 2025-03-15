#include <stdio.h>

int main() {
  int height, weight;

  scanf("%d", &height);
  scanf("%d", &weight);

  int result = bmiLevel(height, weight);

  switch (result) {
  case 0:
    printf("Underweight (%d)", result);
    break;

  case 1:
    printf("Normal weight (%d)", result);
    break;

  case 2:
    printf("Overweight (%d)", result);
    break;

  case 3:
    printf("Mild obesity (%d)", result);
    break;

  case 4:
    printf("Severe obesity (%d)", result);
    break;
  }

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