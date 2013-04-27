class Test extends Thread {
    public static int ans;
    public static int end;
    public void run() {
        int now = 0;
        for (int i = 0; i < 400000000; i++) {
            now = (now + i) % 9999997;
        }
        System.out.println(now);
        new SubTask(0,0,100000000).start();
        new SubTask(1,100000000,200000000).start();
        new SubTask(2,200000000,300000000).start();
        new SubTask(3,300000000,400000000).start();
        for (;;) {
            try {
                sleep(200);
            } catch (Exception e) {}
            if (end == 4) break;
        }
        System.out.println(ans);
    }
    public static void main(String[] args) {
        new Test().start();
    }
}

class SubTask extends Thread {
    private int pos;
    private int left;
    private int right;
    final static int mod = 9999997;

    // init the input data 
    SubTask(int pos,int left,int right) {
        this.pos = pos;
        this.left = left;
        this.right = right;
    }

    public void run() {
        // solve the problem
        int ans = 0;
        for (int i = left; i < right; i++) {
            ans = (ans + i) % mod;
        }
        // write the answer back
        synchronized (this) {
            Test.ans += ans;
            Test.ans %= mod;
            Test.end ++;
        }
    }
}
