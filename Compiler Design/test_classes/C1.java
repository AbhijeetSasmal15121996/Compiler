class Sum {
  public static void main(String[] a){
    System.out.println(new Test().Sum(100));
  }
}

class Test {
  public int Sum(int num) {
    int sum;
    sum = 0;
    while (0 < num) {
      if (sum < 100) {
    	  sum = sum + num;
      } else {
        sum = sum + 20;
      }
      num = num - 1;
    }
    return sum;
  }
}

