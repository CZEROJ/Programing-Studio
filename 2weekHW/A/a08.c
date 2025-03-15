#include <stdio.h>

int bmiLevel(int height, int weight);

int main() {
  int height[10], weight[10]; // 10명의 신장(cm), 체중(kg)
  int all;                    // 총 인원
  char bmi_string[5][20] = {"Underweight", "Normal weight", "Overweight",
                            "Mild obesity", "Severe obesity"};
  int result;

  scanf("%d", &all);

  for (int i = 0; i < all; i++) {
    scanf("%d", &height[i]);
    scanf("%d", &weight[i]);
  }

  for (int i = 0; i < all; i++) {
    result = bmiLevel(height[i], weight[i]);

    if (result == 3 || result == 4) {
      printf("%d %s", i + 1, bmi_string[result]);
      printf("\n");
    }
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