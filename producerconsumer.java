import java.util.LinkedList;

class producerConsumerClass {

    LinkedList<Integer> list = new LinkedList<>();
    public void produce() throws InterruptedException {
        int value = 0;
        while (true) {
            // why synchronised when producer is producing the consumer should not do
            // anything
            // Acquired lock on current object of producer consumer thats why "this"
            synchronized (this) {
                while (list.size() > 0) {
                    wait();
                }
                System.out.println("Produced data " + value);
                list.add(value);
                value++;
                // upto here data is produced and added to list

                notify();
                // notify consumer that data is already produced

                Thread.sleep(1000);
                if (value == 10) {
                    break;
                }
            }
        }
    }

    public void consume() throws InterruptedException {
        // we need to consume the data from the list where producer added the data
        while (true) {
            // check if there is any data present inside the list
            // why synchronised-> when producer is producing the consumer should not do
            // anything 
            synchronized (this) {

                while (list.size() == 0) {
                    wait();
                }
                // if it has some value get it
                int value = list.removeFirst();

                System.out.println("Consumer " + value);
                notify();

                Thread.sleep(1000);
                if (value == 10) {
                    break;
                }
            }
        }
    }
}

public class producerconsumer {
    public static void main(String[] args) throws InterruptedException {
        System.out.println("Producer Consumer Problem");
        // We need to create 2 threads one for producer and one for consumer

        producerConsumerClass pc = new producerConsumerClass();

        Thread t1 = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    pc.produce();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });
        Thread t2 = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    pc.consume();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });
        t1.start();
        t2.start();

        t1.join();
        t2.join();
    }
}


    // 4 creating a linked list of intergers
    // 7 logic for producer
