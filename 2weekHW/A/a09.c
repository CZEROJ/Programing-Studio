#include <stdio.h>

struct bmi_struct {
  char name[20];
  int weight;
  int height;
  int bmi_level;
};

void bmiResolve(struct bmi_struct *sp);

int main() {
  struct bmi_struct data;
  char bmi_string[5][20] = {"Underweight", "Normal weight", "Overweight",
                            "Mild obesity", "Severe obesity"};

  scanf("%s %d %d", data.name, &data.height, &data.weight);
  bmiResolve(&data);
  printf("%s, You are %s.\n", data.name, bmi_string[data.bmi_level]);

  return 0;
}

void bmiResolve(struct bmi_struct *sp) {
  float bmi = sp->weight / ((sp->height) * (sp->height) * 0.0001);

  if (bmi >= 30.0) {
    sp->bmi_level = 4;
  } else if (bmi >= 25.0) {
    sp->bmi_level = 3;
  } else if (bmi >= 23.0) {
    sp->bmi_level = 2;
  } else if (bmi >= 18.5) {
    sp->bmi_level = 1;
  } else {
    sp->bmi_level = 0;
  }
}
