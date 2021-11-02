void pass_value(int x) {

}

void pass_pointer(int *x) {

}

void pass_reference(int &x) {

}

void pass_array(int arr[]) {

}

int main() {
  int value = 12;
  int *val_pointer = &value; 
  int array[2] = {1, 2};

  pass_value(value);
  pass_pointer(val_pointer);
  pass_reference(value);
  pass_array(array);

  return 0;
}

