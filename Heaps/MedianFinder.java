import java.util.*;

class MedianFinder {
  PriorityQueue<Integer> maxPQ;
  PriorityQueue<Integer> minPQ;

  public MedianFinder() {
    maxPQ = new PriorityQueue<>(Collections.reverseOrder());
    minPQ = new PriorityQueue<>();
  }

  public void addNum(int num) {
    if (maxPQ.isEmpty() || maxPQ.peek() >= num) {
      maxPQ.offer(num);
    } else {
      minPQ.offer(num);
    }

    if (maxPQ.size() > minPQ.size() + 1) {
      minPQ.offer(maxPQ.poll());
    } else if (minPQ.size() > maxPQ.size()) {
      maxPQ.offer(minPQ.poll());
    }
  }

  public double findMedian() {
    if (maxPQ.size() == minPQ.size()) {
      return (maxPQ.peek() + minPQ.peek()) / 2.0;
    } else {
      return maxPQ.peek();
    }
  }

  public static void main(String[] args) {
    MedianFinder mf = new MedianFinder();
    mf.addNum(1);
    mf.addNum(2);
    System.out.println(mf.findMedian());
    mf.addNum(3);
    System.out.println(mf.findMedian());
  }
}
