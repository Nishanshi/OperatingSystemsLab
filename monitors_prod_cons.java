class monitors_prod_cons {
    private int contents; 
    private boolean available = false;
    public synchronized int get() {
        while (available == false) {
            try {
                wait();
            } catch (InterruptedException e) {
            }
        }
        available = false;
        notifyAll();
        return contents;
    }
    public synchronized void put(int value) {
        while (available == true) {
            try {
                wait();
            } catch (InterruptedException e) {
            }
        }
        contents = value;
        available = true;
        notifyAll();
    }
}
class Producer extends Thread {
    private monitors_prod_cons monitors_prod_cons;
    private int number;
    public Producer(monitors_prod_cons c, int number) {
        monitors_prod_cons = c;
        this.number = number;
    }
    public void run() {
        for (int i = 0; i < 10; i++) {
            monitors_prod_cons.put(i);
            System.out.println("Producer #" + this.number + " put: " + i);
            try {
                sleep((int)(Math.random() * 100));
            } catch (InterruptedException e) {
            }
        }
    }
}
class Consumer extends Thread {
    private monitors_prod_cons monitors_prod_cons;
    private int number;
    public Consumer(monitors_prod_cons c, int number) {
        monitors_prod_cons = c;
        this.number = number;
    }
    public void run() {
        int value = 0;
        for (int i = 0; i < 10; i++) {
            value = monitors_prod_cons.get();
            System.out.println("Consumer #" + this.number + " got: " + value);
        }
    }
}
class ProducerConsumerTest {
    public static void main(String[] args) {
        monitors_prod_cons c = new monitors_prod_cons();
        Producer p1 = new Producer(c, 1);
        Consumer c1 = new Consumer(c, 1);
        p1.start();
        c1.start();
    }
}
