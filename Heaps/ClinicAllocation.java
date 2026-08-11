import java.util.*;

class ClinicAllocation {
  static class village {
    double population;
    int clinic;

    village(double population, int clinic) {
      this.population = population;
      this.clinic = clinic;
    }

    double load() {
      return population / clinic;
    }
  }

  public static double minimizeMaxLoad(int[] population, int k) {
    PriorityQueue<village> maxHeap =
        new PriorityQueue<>((a, b) -> Double.compare(b.load(), a.load()));

    int n = population.length;

    for (int p : population) {
      maxHeap.offer(new village(p, 1));
    }

    int extraClinic = k - n;

    while (extraClinic-- > 0) {
      village v = maxHeap.poll();
      v.clinic += 1;
      maxHeap.offer(v);
    }

    return maxHeap.peek().load();
  }

  public static void main(String[] args) {
    int[] population = {200, 20, 50};
    int k = 5;
    double result = minimizeMaxLoad(population, k);
    System.out.printf("%.2f%n", result);
  }
}
